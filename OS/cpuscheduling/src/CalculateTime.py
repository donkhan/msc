from PrintUtil import print_line


class CalculateTime:

    def __init__(self):
        pass

    def calculate(self, process_list, name, logging):
        if logging:
            print_line()
            print(name)
        total_time = average_time = 0
        time_set = {}
        for process in process_list:
            method_to_call = getattr(process, "calculate_" + name)
            time = method_to_call()
            if logging:
                print(str(process.pid) + " = " + str(time))
            time_set[process.pid] = time
            total_time += time
        average_time = round(total_time / float(len(process_list)), 2)
        if logging:
            print("Total " + name + " Time " + str(total_time))
            print("Average  " + name + " = " + str(average_time))
        return total_time, average_time, time_set