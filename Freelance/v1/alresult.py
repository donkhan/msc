import init
import xml.dom.minidom

config = init.get_config("al")
input_sep = ","
header = "CensusNo,School,Gender,IndexNo,Zone,Division,Subject Stream,"
subjects = "PHYSICS,CHEMISTRY,MATHEMATICS,AGRICULTURAL SCIENCE,BIOLOGY,COMBINED MATHEMATICS,HIGHER MATHEMATICS," \
         "GENERAL ENGLISH,CIVIL TECHNOLOGY,MECHANICAL TECHNOLOGY,ELECTRICAL ELECTRONIC & INFORMATION TECHNOLOGY," \
         "FOOD TECHNOLOGY,AGRO TECHNOLOGY,BIO RESOURCE TECHNOLOGY,INFORMATION & COMMUNICATION TECHNOLOGY,ECONOMICS," \
         "GEOGRAPHY,POLITICAL SCIENCE,LOGIC & SCIENTIFIC METHOD,HISTORY OF INDIA,HISTORY OF EUROPE," \
         "HISTORY OF MODERN WORLD,HOME ECONOMICS,COMMUNICATION & MEDIA STUDIES,BUSINESS STATISTICS,BUSINESS STUDIES," \
         "ACCOUNTING,BUDDHISM,HINDUISM,CHRISTIANITY,ISLAM,BUDDHIST CIVILIZATION,HINDU CIVILIZATION,ISLAMIC CIVILIZATION," \
         "GREEK & ROMAN CIVILIZATION,CHRISTIAN CIVILIZATION,ART,DANCING (INDIGENOUS),DANCING (BHARATHA),ORIENTAL MUSIC," \
         "CARNATIC MUSIC,WESTERN MUSIC,DRAMA & THEATRE (SINHALA),DRAMA & THEATRE (TAMIL),DRAMA & THEATRE (ENGLISH)," \
         "ENGINEERING TECHNOLOGY,BIO SYSTEMS TECHNOLOGY,SCIENCE FOR TECHNOLOGY,SINHALA,TAMIL,ENGLISH,PALI,SANSKRIT," \
         "ARABIC,FRENCH,GERMAN,RUSSIAN,HINDI,CHINESE,JAPANESE,COMMON GENERAL TEST".split(",")


def get_subject_wise_data(table):
    tds = table.getElementsByTagName("td")
    mark_array = [""] * len(subjects)
    for i in range(0,tds.length-1,2):
        mark_array[init.get_index(subjects,init.strip(tds[i].firstChild.nodeValue))] = \
            init.strip(tds[i+1].firstChild.nodeValue)
    return ",".join(mark_array)


def get_subject_stream(table):
    tds = table.getElementsByTagName("td")
    return tds[tds.length-1].firstChild.nodeValue.lstrip().rstrip()


def parse(content,index_line,f):
    tables = xml.dom.minidom.parseString(content).getElementsByTagName("table")
    init.write_to_file(
        index_line.lstrip().rstrip() + "," +
        get_subject_stream(tables[0]) + "," +
        get_subject_wise_data(tables[1]) + "\n", f)


init.start(config[1],config[2],header + ",".join(subjects) + "\n",config[0],input_sep,parse)