import sys


class AssertInput:

    def __init__(self):
        self.assertion_set = {}

    def check_assertions(self,cpu, wt, tt, context_switches,logging):
        s = dict()
        if len(self.assertion_set) == 0:
            if logging:
                print("No Assertions are set")
            return
        s['total_wait_time'] = wt[0]
        s['avg_wait_time'] = wt[1]
        s['total_turnaround_time'] = tt[0]
        s['avg_turnaround_time'] = tt[1]
        s['context_switches'] = context_switches
        s['slots'] = len(cpu.running_slots)
        try:
            for key in s:
                if self.assertion_set.get(key) is not None:
                    if logging:
                        print("compare " + str(s[key]) + " " + str(self.assertion_set[key]))
                    assert s[key] == self.assertion_set[key]
        except AssertionError:
            print('Assertion Error  for key ' + key)
            sys.exit()
        if logging:
            print("Successfully passed all assertions")