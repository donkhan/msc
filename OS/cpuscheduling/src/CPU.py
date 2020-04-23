
class CPU:

    def __init__(self):
        self.running_slots = []

    def run_process(self,process,start_time,end_time,logging):
        if logging:
            print("CPU: Execute " + str(process.pid) + " between " + str(start_time) +  " and " + str(end_time))
        self.running_slots.append((process,start_time,end_time))
        process.run_pass(start_time,end_time)

    def add_idle_time(self,idle,start_time,end_time,logging):
        if logging:
            print("CPU: "+idle.pid+" between " + str(start_time) + " and " + str(end_time))
        self.running_slots.append((idle,start_time,end_time))
