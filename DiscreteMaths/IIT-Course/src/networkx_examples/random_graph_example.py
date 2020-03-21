import networkx as nx
import matplotlib.pyplot as plt

def vertex_edge():
    G = nx.gnm_random_graph(5,10)
    nx.draw_shell(G,  with_labels=True, font_weight='bold')
    plt.show()

def probablity_graph():
    for i in range(10):
        H = nx.gnm_random_graph(12,0.5)
        print H.edges()
        #nx.draw_shell(H,  with_labels=True, font_weight='bold')
        #plt.show()

probablity_graph()