import init

config = init.get_config("al")


def parse(op_file,d,index_line):
    student_info = ",".join(index_line.split(init.input_sep)[0:8])
    if 'errMsge' in d:
        init.write_to_file(student_info + " - Student Not Found \n",op_file)
        return
    s = ""
    for s_info in ['Name','Subject Stream','Syllabus','District Rank','Island Rank','Z-Score']:
        s = s + "," + init.find(d['studentInfo'],s_info)

    init.write_to_file(student_info + "," + s[1:] + "," + ",".join(init.fill_marks(config[4], d['subjectResults'],
                                            index_line.split(init.input_sep)[7],5)) + "\n", op_file)


init.start(config[1],config[2],config[3] + ",".join(config[4]) + "\n",config[0],init.input_sep,parse,7)