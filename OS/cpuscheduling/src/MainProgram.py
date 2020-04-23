from CPU import *
from OutputOptions import *
from Input import *
from GanttChart import *
from AssertInput import *
from CalculateContextSwitch import *
from CalculateTime import *
from PrintUtil import *
from Algorithm import RoundRobinAlgorithm
from os import listdir


def process(p_list,time_quantum,assertions,output_options):
    orig_list = []
    orig_list.extend(p_list)
    logging = output_options.get_prop("show_text_output")
    cpu = CPU()
    RoundRobinAlgorithm().schedule(cpu, p_list, time_quantum,logging)
    wt,tt,context_switches = CalculateTime().calculate(orig_list, "wait_time", logging)\
        ,CalculateTime().calculate(orig_list, "turn_around_time", logging),CalculateContextSwitch().count(cpu.running_slots, logging)
    if assertions is not None:
        assertions.check_assertions(cpu,wt,tt,context_switches,logging)
    if output_options.show_chart:
        GanttChart().create_gantt_chart(cpu, orig_list, wt,
                       tt, context_switches,time_quantum,output_options)


def test_case(no,output_options,do_not_run_if_no_assertion=False):
    print("Start of Running Test case No " + str(no))
    p_list = []
    input_parameters = Input(no)
    assertions = AssertInput()
    try:
        input_parameters.read(p_list, assertions)
    except IOError:
        print("Test case not Found")
        return
    time_quantum = input_parameters.time_quantum
    if not len(assertions.assertion_set) == 0 or not do_not_run_if_no_assertion:
        process(p_list, time_quantum, assertions,output_options)
    else:
        print("No Assertion. Hence Not running the test case")
    print("End of Running Test case No " + str(no))
    print_line()


def handle_custom_inputs():
    n = int(input("Enter No of Processes : "))
    p_list = []
    for i in range(1, n + 1):
        p = Process(["PID" + str(i), int(input("Enter Arrival Time : ")),
                     int(input("Enter Burst Time : ")), int(input("Order : "))])
        p_list.append(p)
    time_quantum = int(input("Enter Time Quantum : "))
    process(p_list, time_quantum, None,OutputOptions())


def test_all_test_cases():
    files = [f for f in listdir("../testcases/")]
    output_options = OutputOptions()
    output_options.show_chart = False
    for file in files:
        test_case(int(file[len("test_"):]),output_options,True)


def get_input_and_start():
    c = 'E'
    if c == 'E':
        test_case(int(input("Enter Test Case No ...")), OutputOptions(), False)
    elif c == 'T':
        test_all_test_cases()
    elif c == 'S':
        handle_custom_inputs()
    else:
        print("Please give Proper input")
        get_input_and_start()


if __name__ == "__main__":
    print_version()
    get_input_and_start()
