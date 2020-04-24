import init
import json

config = init.get_config("ol")


def parse(op_file,d,index_line):
    init.write_to_file(",".join(index_line.split(init.input_sep)[0:7])
                       + "," + ",".join(init.fill_marks(config[4],d['subjectResults'],index_line.split(init.input_sep)[6],9))
                       + "\n", op_file)


init.start(config[1],config[2],config[3] + ",".join(config[4]) + "\n",config[0],init.input_sep,parse)