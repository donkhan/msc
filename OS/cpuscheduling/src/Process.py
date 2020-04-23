class Process:

    def __init__(self,tokens):
        self.pid = tokens[0]
        self.arrival_time = int(tokens[1])
        self.burst_time = int(tokens[2])
        self.remaining_burst_time = self.burst_time
        self.order = int(tokens[3]) if len(tokens) == 4 else 1
        self.running_passes = []

    def to_string(self):
        return str(self.pid) + " AT " + str(self.arrival_time) + " BT " + str(self.burst_time) + " RBT " + str(self.remaining_burst_time)

    def graph_str(self):
        return "("  + str(self.arrival_time) + "," + str(self.burst_time) + "," + str(self.order) + ")"

    def run_pass(self,start_time,end_time):
        self.running_passes.append((start_time,end_time))
        self.remaining_burst_time = self.remaining_burst_time - (end_time - start_time)

    def still_needs_cycle_to_run(self):
        return self.remaining_burst_time > 0

    def __repr__(self):
        return str(self.pid)
        #return self.to_string()

    def sort_by_arrival_time_followed_by_order(p1, p2):
        if p1.arrival_time == p2.arrival_time:
            return p1.order - p2.order
        return p1.arrival_time - p2.arrival_time

    def calculate_wait_time(self):
        wait_time = self.running_passes[0][0] - self.arrival_time
        for i in range(1,len(self.running_passes)):
            wait_time = wait_time + self.running_passes[i][0] - self.running_passes[i-1][1]
        self.wait_time = wait_time
        return wait_time

    def calculate_turn_around_time(self):
        turn_around_time = self.running_passes[len(self.running_passes)-1][1] - self.arrival_time
        return turn_around_time

