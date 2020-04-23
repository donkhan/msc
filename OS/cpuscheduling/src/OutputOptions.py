class OutputOptions:

    def get_flag(self,p):
        return False if p == 'false' else True

    def __init__(self):
        self.show_authors = True
        self.show_chart = True
        f = open("../conf/output_options")
        self.config_dictionary = {}
        for line in f:
            tokens =  line.split("=")
            self.config_dictionary[tokens[0].replace("\n","")] = self.get_flag(tokens[1].replace("\n",""))
        f.close()

    def __repr__(self):
        return str(self.config_dictionary)

    def get_prop(self,key):
        return self.config_dictionary[key]

