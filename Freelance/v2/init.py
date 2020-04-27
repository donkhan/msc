import urllib2
import json

input_sep = ","


def get_config(exam):
    return get("base_url")+exam[0].upper() + exam[1:]+"Result","input-"+exam+".csv",\
           "output-"+exam+".csv",get(exam + "_header"),get(exam + "_subjects").split(",")


def fire_request(url):
    try:
        req = urllib2.Request(url)
        sock = urllib2.build_opener(urllib2.HTTPHandler(debuglevel=0)).open(req)
        d = json.loads(sock.read())
        sock.close()
        return d
    except urllib2.HTTPError as error:
        code = error.getcode()
        print "Error Code " + code


def open_file(output_file,header):
    f = open(output_file, "w")
    header = header.upper()
    f.write(header)
    return f


def query_forming_fn(url,index_no):
    return url + "?index=" + index_no + "&nic="


def make_request(op_file,parse_fn,url,index_no,index_line,query_forming_fn):
    return parse_fn(op_file,fire_request(query_forming_fn(url,index_no)),index_line)


def start(input_file,output_file,header,url,input_sep,parse_fn,pos=6,query_forming_fn=query_forming_fn):
    print "Started...."
    f = open_file(output_file,header)
    lines = open(input_file, "r").readlines()[1:]
    for line in lines:
        index_line = line.replace('\n', '').replace("\r", "")
        if index_line.startswith("#"):
            continue
        index_no = index_line.split(input_sep)[pos]
        index_no = index_no.replace("\r","")
        try:
            print "Processing " + index_no
            make_request(f,parse_fn,url,index_no,index_line,query_forming_fn)
        except:
            pass
    f.close()


def write_to_file(line,f):
    f.write(line)
    f.flush()


def get_index(subjects,subject):
    for x in range(0,len(subjects)):
        if subject == subjects[x].upper():
            return x


def strip(s):
    return s.lstrip().rstrip()


def find(json,key):
    value = ''
    for element in json:
        if element['param'] == key:
            value = element['value']
            break
    return value


def fill_marks(subjects,subject_results,index_no,expected_no_of_results):
    mark_array = []
    no_of_subjects = 0
    for subject in subjects:
        try:
            found = False
            for a in subject_results:
                if a['subjectName'] == subject.upper():
                    found = True
                    mark_array.append(a['subjectResult'])
                    no_of_subjects = no_of_subjects + 1
                    break
            if found is False:
                mark_array.append('')
        except:
            print "Exception happened"
    if no_of_subjects != expected_no_of_results:
        print "Error for " , index_no, "Expected = " , expected_no_of_results, " Observed = ", len(mark_array), mark_array
        print "Subjects" , subjects
        sub = ''
        for a in subject_results:
            sub = sub + a['subjectName'] + ","
        print sub
    return mark_array


def get(config):
    fd = open("v2.config")
    for line in fd:
        if line.startswith(config):
            c = line[line.find("=")+1:]
            c = c.replace("\n","")
            return c