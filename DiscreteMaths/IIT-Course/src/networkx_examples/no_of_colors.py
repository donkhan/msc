import networkx as nx

def c(d):
    s = set()
    for k in d:
        s.add(d[k])
    return len(s)


print "Star Graph with 5 vertices ",c(nx.greedy_color(nx.star_graph(5)))
print "Complete Graph with 5 vertices ",c(nx.greedy_color(nx.complete_graph(5)))