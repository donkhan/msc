import re
import init
import xml.dom.minidom

config = init.get_config("gv")
url = config[0]
input_file = config[1]
output_file = config[2]
input_sep = "\t"


def parse(content,index_line,f):
    doc = xml.dom.minidom.parseString(content)
    lines = content.split("\n")
    matching_lines = []
    for line in lines:
        m = re.search("(.*rightre\">)(.*)",line)
        if m:
            matching_lines.append(m.group(2))
    init.write_to_file(",".join(index_line.split(input_sep)[0:4])
            + "," + matching_lines[2] + "," + matching_lines[4] + "," + matching_lines[5] + "\n",f)


init.start(input_file,output_file,"CensusNo,School,Gender,IndexNo,Name,Mark,Qualification" + "\n",url,input_sep,parse)
