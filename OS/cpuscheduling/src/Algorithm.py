import functools
from Idle import *
from KQueue import *
from PrintUtil import print_line


class RoundRobinAlgorithm:
    def __init__(self):
        pass

    def get_running_time(self,process, time_quantum):
        return process.remaining_burst_time if process.remaining_burst_time < time_quantum else time_quantum

    def calculate_idle_time(self,process_list):
        return None if len(process_list) == 0 else process_list[0].arrival_time

    def fill_queue(self,q, scheduled_process_queue, time_pointer, process_list):
        to_be_removed = []
        for process in process_list:
            if process.arrival_time <= time_pointer:
                q.push(process)
                to_be_removed.append(process)
        for process in to_be_removed:
            process_list.remove(process)
        while not scheduled_process_queue.empty():
            q.push(scheduled_process_queue.pop())
        return q.empty()

    def schedule(self,cpu, process_list, time_quantum, logging):
        if logging is True:
            print("Before Sorting " + str(process_list))
        process_list.sort(key=functools.cmp_to_key(Process.sort_by_arrival_time_followed_by_order))
        if logging is True:
            print("After Sorting " + str(process_list))
            print("Time Quantum = " + str(time_quantum))
            print_line()
        q = KQueue()
        scheduled_process_queue = KQueue()
        time_pointer = 0
        while len(process_list) > 0 or not q.empty():
            while not q.empty():
                process = q.pop()
                time_to_run = self.get_running_time(process, time_quantum)
                cpu.run_process(process, time_pointer, time_pointer + time_to_run, logging)
                if process.still_needs_cycle_to_run():
                    scheduled_process_queue.push(process)
                time_pointer = time_pointer + time_to_run
            while self.fill_queue(q, scheduled_process_queue, time_pointer, process_list):
                idle_time = self.calculate_idle_time(process_list)
                if idle_time is None:
                    break
                cpu.add_idle_time(Idle([0]), time_pointer, idle_time, logging)
                time_pointer = idle_time
