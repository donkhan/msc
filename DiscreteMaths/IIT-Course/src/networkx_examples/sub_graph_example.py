import networkx as nx
import matplotlib.pyplot as plt

G = nx.star_graph(10)
S = G.subgraph([1,10])

nx.draw_shell(G,  with_labels=True, font_weight='bold')
plt.show()