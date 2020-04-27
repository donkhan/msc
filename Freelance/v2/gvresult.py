import init

config = init.get_config("gv")


def parse(op_file,d,index_line):
    if 'errMsge' in d:
        init.write_to_file(index_line + " - Student Not Found \n",op_file)
        return
    init.write_to_file(index_line + "," + d['name'] + "," +
                       init.find(d['studentInfo'],"District / Medium Cut off Mark") + ","
                       + d['subjectResults'][0]['subjectResult'] + "\n", op_file)


def q_fn(url,index_no):
    return url + "/" + index_no


init.start(config[1],config[2],config[3] + ",".join(config[4]) + "\n",config[0],init.input_sep,parse,6,query_forming_fn=q_fn)
