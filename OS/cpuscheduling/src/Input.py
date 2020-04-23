from Process import *


class Input:
    def __init__(self,test_case_no):
        self.test_case_no = test_case_no
        self.time_quantum = 1

    def parse_process_line(self,line, p_list):
        line.replace(" ", "").replace("\n", "").split()
        tokens = line.split()
        if len(tokens) == 0:
            return
        p = Process(tokens)
        p_list.append(p)

    def set_assertion_value(self,line,assert_input):
        tokens = line[len("assert:"):].split("=")
        assert_input.assertion_set[tokens[0]] = float(tokens[1].replace("\n",""))

    def read(self,p_list,assert_input):
        try:
            f = open("../testcases/test_" + str(self.test_case_no), "r")
            for line in f:
                if line.startswith("#"):
                    continue
                if line.startswith("PID"):
                    continue
                if line.startswith("time_quantum"):
                    self.time_quantum = int(line.split("=")[1])
                    continue
                if line.startswith("assert"):
                    self.set_assertion_value(line,assert_input)
                    continue
                self.parse_process_line(line, p_list)
            f.close()
        except IOError:
            print(IOError)
            raise Exception('IO Error Happened')
