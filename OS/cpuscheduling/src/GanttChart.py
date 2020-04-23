class GanttChart():

    def __init__(self):
        pass

    def get_random(self):
        from random import randint
        random = randint(30, 255)
        return random

    def create_gantt_chart(self,cpu, p_list, wt, tt, context_switches,time_quantum, output_options):
        try:
            import matplotlib.pyplot as plt
        except ModuleNotFoundError:
            print("Matplotlib Not Found. Please Install")
            return
        plt.rcParams["figure.figsize"] = (10, 8)
        max_x = cpu.running_slots[len(cpu.running_slots) - 1][2]
        max_y = len(p_list) + 1

        colors = {}
        y_ticks = []
        fake_bars = []
        self.fill(p_list, colors, y_ticks, fake_bars)

        fig, gnt = plt.subplots()
        plt.title("Round Robin Scheduling")
        gnt.legend(fake_bars, y_ticks)
        gnt.set_xlabel('Seconds')
        gnt.set_ylabel('')

        gnt.set_ylim(0, max_y)
        gnt.set_xlim(0, max_x + 1)

        plt.xticks([x for x in range(0, max_x + 1)])
        gnt.set_yticklabels([])
        gnt.grid(True)

        self.draw_slots(cpu, gnt, colors,output_options)
        self.draw_text(p_list, gnt, time_quantum, wt, tt, context_switches, output_options)
        plt.show()

    def fill(self,p_list, colors, y_ticks, fake_bars):
        try:
            import matplotlib.patches as mpatch
        except ModuleNotFoundError:
            return
        color = '#' + str(hex(self.get_random()))[2:] + str(hex(self.get_random()))[2:] + str(hex(self.get_random()))[2:]
        colors['IDLE'] = color
        y_ticks.append('Idle')
        fake_bars.append(mpatch.Rectangle((0, 0), 1, 1, fc=color))
        for process in p_list:
            color = '#' + str(hex(self.get_random()))[2:] + str(hex(self.get_random()))[2:] + str(hex(self.get_random()))[2:]
            colors[process.pid] = color
            y_ticks.append(process.pid)
            fake_bars.append(mpatch.Rectangle((0, 0), 1, 1, fc=color))

    def draw_slots(self,cpu, gnt,colors,output_options):
        for slot in cpu.running_slots:
            pid = str(slot[0])
            if output_options.get_prop("stacked") is True:
                if pid == "IDLE":
                    gnt.broken_barh([(slot[1], slot[2] - slot[1])], (0, 1), color=colors.get(pid))
                else:
                    gnt.broken_barh([(slot[1], slot[2] - slot[1])],(int(pid[1:]),1), color=colors.get(pid))
            else:
                gnt.broken_barh([(slot[1], slot[2] - slot[1])], (0, 1), color=colors.get(pid))

    def draw_text(self,p_list, gnt, time_quantum, wt, tt, context_switches, output_options):
        y = 1
        y_gap = float(.7) / (len(p_list) + 5)
        y = self.draw_process_info(p_list, gnt, wt, tt, time_quantum, y, y_gap, output_options)
        self.draw_authors(gnt, output_options, y)
        y = y - y_gap

        gnt.annotate('t.w.time = ' + str(wt[0]) + " a.w.time = " + str(wt[1]), xy=(3, 1), xycoords='data',
                     xytext=(0.5, y), textcoords='axes fraction',
                     horizontalalignment='right', verticalalignment='top',
                     )
        y = y - y_gap
        gnt.annotate('t.t.time = ' + str(tt[0]) + ' a.t.time = ' + str(tt[1]), xy=(3, 1), xycoords='data',
                     xytext=(0.5, y), textcoords='axes fraction',
                     horizontalalignment='right', verticalalignment='top',
                     )
        y = y - y_gap
        gnt.annotate('# of context switches = ' + str(context_switches), xy=(3, 1), xycoords='data',
                     xytext=(0.5, y), textcoords='axes fraction',
                     horizontalalignment='right', verticalalignment='top',
                     )

    def draw_headers(self,gnt,y,show_questions):

        gnt.annotate("PID", xy=(3, 1), xycoords='data',
                     xytext=(0.3, y), textcoords='axes fraction',
                     horizontalalignment='right', verticalalignment='top',
                     )
        if show_questions:
            gnt.annotate("(A.T,B.T,Order)", xy=(3, 1), xycoords='data',
                         xytext=(0.3 + .2, y), textcoords='axes fraction',
                         horizontalalignment='right', verticalalignment='top',
                         )
            gap = .4

        gnt.annotate("(W.T,T.T)", xy=(3, 1), xycoords='data',
                     xytext=(0.3 + gap, y), textcoords='axes fraction',
                     horizontalalignment='right', verticalalignment='top',
                     )

    def draw_process_info(self,p_list, gnt, wt, tt, time_quantum, y, y_gap, output_options):
        y = y - y_gap
        gap = .2
        show_questions = output_options.get_prop("show_questions")
        self.draw_headers(gnt,y,show_questions)
        y = y - y_gap
        for p in p_list:
            gnt.annotate(str(p.pid), xy=(3, 1), xycoords='data',
                         xytext=(0.3, y), textcoords='axes fraction',
                         horizontalalignment='right', verticalalignment='top',
                         )
            if show_questions:
                gnt.annotate(p.graph_str(), xy=(3, 1), xycoords='data',
                             xytext=(0.3 + 0.2, y), textcoords='axes fraction',
                             horizontalalignment='right', verticalalignment='top',
                             )
                gap = .4
            gnt.annotate("(" + str(wt[2][p.pid]) + "," + str(tt[2][p.pid]) + ")", xy=(3, 1), xycoords='data',
                         xytext=(0.3 + gap, y), textcoords='axes fraction',
                         horizontalalignment='right', verticalalignment='top',
                         )
            y = y - y_gap

        if show_questions:
            gnt.annotate('time quantum = ' + str(time_quantum) + " no of process = " + str(len(p_list)), xy=(3, 1), xycoords='data',
                         xytext=(0.5, y), textcoords='axes fraction',
                         horizontalalignment='right', verticalalignment='top',
                         )
        return y

    def draw_authors(self,gnt, output_options, y):
        if output_options.get_prop("show_authors") is False:
            return
        authors = ['Project Done By']
        f = open("../AUTHORS.txt")
        for line in f:
            tokens = line.split(",")
            authors.append(tokens[0] + " (" + tokens[1] + ")")
        f.close()
        for author in authors:
            gnt.annotate(author, xy=(7, 1), xycoords='data',
                         xytext=(0.8, y), textcoords='axes fraction',
                         horizontalalignment='right', verticalalignment='top',
                         )
            y = y - .05