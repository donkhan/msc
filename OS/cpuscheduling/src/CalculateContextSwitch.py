from PrintUtil import print_line


class CalculateContextSwitch:

    def __init__(self):
        pass

    def count(self, slots, logging):
        if logging:
            print_line()
            print("Counting Context Switch...")
        c = 0
        for i in range(1,len(slots)):
            if slots[i][0] != slots[i-1][0]:
                if logging :
                    print("Context Switch from " + str(slots[i-1][0]) + " to " + str(slots[i][0]))
                c = c + 1
        if logging:
            print("No of Context Switches " + str(c))
        return c