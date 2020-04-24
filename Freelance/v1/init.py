import urllib2
import re
import urllib


def get_view_state(page):
    m = re.search("(.*)ViewState(.*)(value)(.*)(autocomplete)", page)
    return m.group(4)


def get_init_data(url):
    request = urllib2.Request(url)
    sock = urllib2.urlopen(request)
    cookies = sock.info()['Set-Cookie']
    content = sock.read()
    sock.close()
    view_state = get_view_state(content)[2:-2]
    return view_state, cookies


def get_config(exam):
    url="https://www.doenets.lk/result/"+exam+"result.jsf"
    input_file="input-"+exam+".csv"
    output_file="output-"+exam+".csv"
    return url,input_file,output_file


def fire_request(url,view_state,cookies,username):
    data = {
        'frm': 'frm',
        'frm:btnSubmit': '',
        'frm:username': username,
        'javax.faces.ViewState': view_state
    }
    request = urllib2.Request(url)
    request.add_header("Cookie", cookies)
    request.add_data(urllib.urlencode(data))
    opener = urllib2.build_opener(urllib2.HTTPHandler(debuglevel=1))
    sock = opener.open(request)
    content = sock.read()
    sock.close()
    return content


def open_file(output_file,header):
    f = open(output_file, "w")
    f.write(header)
    return f


def make_request(index_line,view_state,cookies,f,fn,url,index_no):
    return fn(fire_request(url, view_state, cookies, index_no),index_line,f)


def start(input_file,output_file,header,url,input_sep,parse_fn):
    print "Started...."
    f = open_file(output_file,header)
    print "Opened and Wrote header content to the output file"
    get_data = get_init_data(url)
    print "Got Cookies and View State"
    lines = open(input_file, "r").readlines()[1:]
    for line in lines:
        index_line = line.replace('\n', '')
        index_no = index_line.split(input_sep)[3]
        try:
            print "Processing " + index_no
            make_request(index_line,get_data[0],get_data[1],f,parse_fn,url,index_no)
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