import init
import xml.dom.minidom

config = init.get_config("ol")
header = "CensusNo,School,Gender,IndexNo,"
subjects = "Buddhism,Saivaneri,Catholicism,Christianity,Islam,Sinhala Language & Litt.," \
         "Tamil Language & Litt.,English Language,Mathematics,History,Science,Music (Oriental)," \
         "Music (Western),Music (Carnatic),Art,Dancing (Oriental),Dancing (Bharatha)," \
         "Appreciation of English Literary Texts,Appreciation of Sinhala Literary Texts," \
         "Appreciation of Tamil Literary Texts,Appreciation of Arabic Literary Texts," \
         "Drama & Theatre (Sinhala),Drama & Theatre (Tamil),Drama & Theatre (English)," \
         "Business and Accounting Studies,Geography,Civic Education,Entrepreneurship Education," \
         "Second Language (Sinhala),Second Language (Tamil),Pali,Sanskrit,French,German,Hindi,Japanese,Arabic,Korean," \
         "Chinese,Russian,Infor. & Comm. Technology,Agriculture & Food Technology," \
         "Aquatic Bio. Technology,Arts & Crafts,Home Economics,Health & Physical Education," \
         "Communication & Media Studies,Design & Con. Technology,Design & Mec. Technology," \
         "Design & Elec. & Elec.  Technology,Electronic Writing & Shorthand (Sinhala),Electronic Writing & Shorthand (Tamil)," \
         "Electronic Writing & Shorthand (English)".split(",")
input_sep = ','


def parse(content,index_line,f):
    elements = xml.dom.minidom.parseString(content).getElementsByTagName("td")
    mark_array = [""] * len(subjects)
    for x in range(10, len(elements), 2):
        subject = init.strip(elements[x].childNodes[0].data.replace("\n", ""))
        grade = init.strip(elements[x + 1].childNodes[0].data.replace("\n", ""))
        index = init.get_index(subjects,subject)
        if index is not None:
            mark_array[index] = grade
        else:
            print "Error for Subject " + subject
    init.write_to_file(",".join(index_line.split(input_sep)[0:4]) + "," + ",".join(mark_array) + "\n",f)


init.start(config[1],config[2],header + ",".join(subjects) + "\n",config[0],input_sep,parse)