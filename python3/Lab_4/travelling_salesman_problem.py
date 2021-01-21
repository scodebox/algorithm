import sys
import heapq as heap
from copy import deepcopy


class TravellingSalesman:
    '''
    Class TravellingSalesman finds optimal path from given adjacency matrix.
    '''

    def __init__(self, m):
        # Total number of node count.
        self.total_node = 1
        # Matrix
        self.m = m
        # MIN Heap for the nodes : least cost branch and bound
        self.node_heap = []
        # Upper bound.
        self.upper = None
        # For holding the result(Node)
        self.result = None

    # Function for to start computation.
    def optimal_travel_path(self):
        # Set the root node.
        self.root = self.Node(self.total_node, [0])
        # Copy the adjacency matrix
        self.root.m = deepcopy(self.m)
        # Calculating the cost after reduing the matrix
        self.root.cost = (self.reduce_row(self.root.m) +
                          self.reduce_column(self.root.m))

        # Push the node into the heap.
        heap.heappush(self.node_heap, self.root)
        self.show(self.root)

        # Calling solve() for computer all the child nodes.
        self.solve()

        # Get the path from the result node and return the path.
        path = [k+1 for k in self.result.path]
        path.append(self.root.path[-1]+1)
        return path, self.result.cost

    class Node:
        '''
        Class Node for storing all the information and data of each node.
        '''

        def __init__(self, id, path):
            # Node number.
            self.id = id
            # Matrix
            self.m = []
            # Path of this node the root node.
            self.path = path
            # Cost of this node.
            self.cost = None
            # Link to the parent node.
            self.parent = None

        # Function to show the details of the node.
        def show(self):
            print('--------------------')
            print('ID : ', self.id)
            print('COST : ', self.cost)
            print('PATH : ', self.path)
            print('PARENT : ', self.parent)
            self.show_matrix(self.m)

        # Function to show the matrix.
        def show_matrix(self, m):
            print('--------------------')
            for row in m:
                print(row)
            print('--------------------')

        # lessthan will compare the cost of two object.
        def __lt__(self, other):
            return self.cost < other.cost

        # equal will check equality of cost of two object.
        def __eq__(self, other):
            if other == None:
                return False
            if not isinstance(other, TravellingSalesman.Node):
                return False
            return self.cost == other.cost

    # Function to compute all the node.
    def solve(self):
        # Continue until heap is empty.
        while self.node_heap:
            # Take the minimum cost node from the heap
            current_root = heap.heappop(self.node_heap)

            # If the length of the path is same as number of vertex then we reached to the end.
            if len(current_root.path) == len(self.m):
                # Update the upper.
                if self.upper == None:
                    self.upper = current_root.cost
                    self.result = current_root
                elif self.upper > current_root.cost:
                    self.upper = current_root.cost
                    self.result = current_root

                # Remove nodes with higher cost.
                self.kill_nodes()
                # Skip all the next step of the while loop.
                continue

            # Create all the nodes of next level.
            for i in range(0, len(self.m)):
                # Skip ancestor nodes.
                if i not in current_root.path:
                    # print (i)
                    # Count the number of nodes.
                    self.total_node += 1

                    # Creating child node with path of parent node + current vertex.
                    child = self.Node(self.total_node, current_root.path+[i])
                    # Setting parent node.
                    child.parent = current_root
                    # copying the matrix from the prarent node.
                    child.m = deepcopy(current_root.m)
                    # Setting Infinite to row and column.
                    self.set_row_INF(child.m, current_root.path[-1])
                    self.set_col_INF(child.m, child.path[-1])
                    # Setting Infinite cost of this node to the root node.
                    child.m[child.path[-1]][self.root.path[-1]] = sys.maxsize
                    # Compute the cost of the node.
                    child.cost = (current_root.m[current_root.path[-1]][child.path[-1]])+(
                        self.reduce_row(child.m)+self.reduce_column(child.m))+current_root.cost
                    # child.show()

                    # Push the node into the MIN heap.
                    heap.heappush(self.node_heap, child)
                    self.show(child)

    # Function to kill node having higher cost.
    def kill_nodes(self):
        # print('------KILL--------')
        #  Copy the heap to the temp list and set the heap to empty.
        temp_list = self.node_heap
        self.node_heap = []

        # Copy back alive nodes.
        for node in temp_list:
            if node.cost < self.upper:
                self.node_heap.append(node)
            # else:
            #     print('DELETE')
            #     node.show()

        # Delete the temp list.
        del temp_list

    # Function to set a row to infinite.
    def set_row_INF(self, m, row):
        # Putting the row the MAX value then integer can hold.
        for i in range(len(m)):
            m[row][i] = sys.maxsize

    # Function to set a column to infinite.
    def set_col_INF(self, m, col):
        # Putting the column the MAX value then integer can hold.
        for i in range(len(m)):
            m[i][col] = sys.maxsize

    # Function to reduce the rows and return the cost.
    def reduce_row(self, m):
        # Search for the min values of each row.
        min_list = []
        for row in m:
            min_value = min(row)
            # Discard the value if all the row have infinite.
            if min_value == sys.maxsize:
                min_list.append(0)
            else:
                min_list.append(min_value)
        # print (min_list)

        # Reduce the min values from each row elements.
        for row in range(0, len(m)):
            if min_list[row] != 0:
                for col in range(0, len(m)):
                    # Skip infinie
                    if m[row][col] != sys.maxsize:
                        m[row][col] -= min_list[row]
        # print (sum(min_list))
        return sum(min_list)

    # Function to reduce the columns and return the cost.
    def reduce_column(self, m):
        # Search for the min values of each column.
        min_list = []
        for col in range(0, len(m)):
            min_value = m[0][col]
            for row in range(0, len(m)):
                if min_value > m[row][col]:
                    min_value = m[row][col]
            # Discard the value if all the row have infinite.
            if min_value == sys.maxsize:
                min_list.append(0)
            else:
                min_list.append(min_value)
        # print(min_list)
        # Reduce the min values from each column elements.
        for col in range(0, len(m)):
            if min_list[col] != 0:
                for row in range(0, len(m)):
                    # Skip infinite
                    if m[row][col] != sys.maxsize:
                        m[row][col] -= min_list[col]
        # print(sum(min_list))
        return sum(min_list)

    # Function to show the created node.
    def show(self, node):
        print('Node (%d) created - COST : %d' % (node.id, node.cost))


if __name__ == "__main__":
    # Max value of int as infinite
    INF = sys.maxsize
    # adjacency matrix
    m1 = [
        [INF, 20, 30, 10, 11],
        [15, INF, 16, 4, 2],
        [3, 5, INF, 2, 4],
        [19, 6, 18, INF, 3],
        [16, 4, 7, 16, INF]
    ]

    m2 = [
        [INF, 7, 3, 12, 8],
        [3, INF, 6, 14, 9],
        [5, 8, INF, 6, 18],
        [9, 8, 5, INF, 11],
        [18, 14, 9, 8, INF]
    ]

    # creating object and calling function to solve.
    obj = TravellingSalesman(m1)
    path, cost = obj.optimal_travel_path()

    # Printing the path and cost.
    print()
    print('COST : %d' % (cost))
    print('PATH : ', end='')
    for i in range(len(path)):
        print(path[i], end='')
        if i < len(path)-1:
            print(' -> ', end='')
        else:
            print()
