class HamiltonianCircuits:
    '''
    Class HamiltonianCircuits finds all possible Hamiltonian Cycle of a given graph(adjacency matrix)
    '''

    def __init__(self, graph):
        self.graph = graph
        # total number of node in the graph.
        self.total_node = len(graph)-1
        # List for holding the path
        self.path = [0]*len(graph)
        # List for holding all possible paths.
        self.circuits = []

    # Function to get the weight of the path between two nodes.(if exist)
    def get_weight(self, node1, node2):
        return (self.graph[node1][node2])

    # Function take start node from user and search for Hamiltonian Circuits from given node.
    def search(self, start_node=1):
        self.path[1] = start_node
        self.find_cycle(2)

    # Recursive function for explore all possible combination of node.
    def find_cycle(self, path_index):
        while True:
            # Search for next node.
            self.next_value(path_index)

            # If next node not found. | done with all the options
            if self.path[path_index] == 0:
                return

            # When a path is found.
            if path_index == self.total_node:
                # Storing the path.
                self.circuits.append(self.path[1:]+self.path[1:2])
            else:
                # Recursive call to find next node.
                self.find_cycle(path_index+1)

    # Function to search for next possible node.
    def next_value(self, path_index):
        while True:
            # Checkout next node.
            self.path[path_index] = (self.path[path_index]+1) % len(self.graph)

            # run out of options | Done with all possible option
            if self.path[path_index] == 0:
                return

            # There should be a path exist from the last node.
            if self.get_weight(self.path[path_index-1], self.path[path_index]) != 0:
                # The selected node should node be a repetition of previously selected node.
                flag = 0
                for i in range(1, path_index):
                    if self.path[i] == self.path[path_index]:
                        flag = 1
                        break
                # If the node is unique selection.
                if not flag:
                    # if (more nodes to be selected for a complete Hamiltonian Circuits) OR (This is the last node of a complete path AND there exist a path from this last node to first starting node)
                    if (path_index < self.total_node) or (path_index == self.total_node and self.get_weight(self.path[self.total_node], self.path[1]) != 0):
                        return

    # Function to print all the paths.
    def show_circuits(self):
        # Path found.
        if self.circuits:
            for circuit in self.circuits:
                print(circuit)
        else:
            # no path found.
            print("NOT FOUND!")


if __name__ == "__main__":
    # graph = [
    #     [0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    #     [0,0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
    #     [0,0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0],
    #     [0,0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0],
    #     [0,0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0],
    #     [0,1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0],
    #     [0,0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0],
    #     [0,0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0],
    #     [0,0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0],
    #     [0,0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1],
    #     [0,0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0],
    #     [0,0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1],
    #     [0,0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0]
    # ]

    graph = [
        [0, 0, 0, 0, 0, 0],
        [0, 0, 1, 1, 0, 1],
        [0, 1, 0, 1, 1, 1],
        [0, 1, 1, 0, 1, 0],
        [0, 0, 1, 1, 0, 1],
        [0, 1, 1, 0, 1, 0]
    ]
    hamiltonian_cycle = HamiltonianCircuits(graph)
    hamiltonian_cycle.search()
    hamiltonian_cycle.show_circuits()
