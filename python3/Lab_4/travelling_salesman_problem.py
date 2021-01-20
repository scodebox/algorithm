import sys
import heapq as heap
from copy import deepcopy


class TravellingSalesman:
    def __init__(self, m):
        self.total_node = 1
        self.m = m
        self.node_heap = []
        self.upper = None
        self.result = None

    def optimal_travel_path(self):
        self.root = self.Node(self.total_node, [0])
        self.root.m = deepcopy(self.m)
        self.root.cost = (self.reduce_row(self.root.m) +
                          self.reduce_column(self.root.m))
        heap.heappush(self.node_heap, self.root)
        self.show(self.root)
        self.solve()
        path = [k+1 for k in self.result.path]
        path.append(self.root.path[-1]+1)
        return path

    class Node:
        def __init__(self, id, path):
            self.id = id
            self.m = []
            self.path = path
            self.cost = None
            self.parent = None

        def show(self):
            print('--------------------')
            print('ID : ', self.id)
            print('COST : ', self.cost)
            print('PATH : ', self.path)
            print('PARENT : ', self.parent)
            self.show_matrix(self.m)

        def show_matrix(self, m):
            print('--------------------')
            for row in m:
                print(row)
            print('--------------------')

        def __lt__(self, other):
            return self.cost < other.cost

        def __eq__(self, other):
            if other == None:
                return False
            if not isinstance(other, TravellingSalesman.Node):
                return False
            return self.cost == other.cost

    def solve(self):
        while self.node_heap:
            current_root = heap.heappop(self.node_heap)

            if len(current_root.path) == len(self.m):
                self.upper = current_root.cost
                self.result = current_root
                self.kill_nodes()
                continue

            for i in range(0, len(self.m)):
                if i not in current_root.path:
                    # print (i)
                    self.total_node += 1
                    child = self.Node(self.total_node, current_root.path+[i])
                    child.parent = current_root
                    child.m = deepcopy(current_root.m)
                    self.set_row_INF(child.m, current_root.path[-1])
                    self.set_col_INF(child.m, child.path[-1])
                    child.m[child.path[-1]][self.root.path[-1]] = sys.maxsize
                    child.cost = (current_root.m[current_root.path[-1]][child.path[-1]])+(
                        self.reduce_row(child.m)+self.reduce_column(child.m))+current_root.cost
                    # child.show()
                    heap.heappush(self.node_heap, child)
                    self.show(child)

    def kill_nodes(self):
        # print('------KILL--------')
        temp_list = self.node_heap
        self.node_heap = []
        for node in temp_list:
            if node.cost < self.upper:
                self.node_heap.append(node)
            # else:
            #     print('DELETE')
            #     node.show()
        del temp_list

    def set_row_INF(self, m, row):
        for i in range(len(m)):
            m[row][i] = sys.maxsize

    def set_col_INF(self, m, col):
        for i in range(len(m)):
            m[i][col] = sys.maxsize

    def reduce_row(self, m):
        min_list = []
        for row in m:
            min_value = min(row)
            if min_value == sys.maxsize:
                min_list.append(0)
            else:
                min_list.append(min_value)
        # print (min_list)
        for row in range(0, len(m)):
            if min_list[row] != 0:
                for col in range(0, len(m)):
                    if m[row][col] != sys.maxsize:
                        m[row][col] -= min_list[row]
        # print (sum(min_list))
        return sum(min_list)

    def reduce_column(self, m):
        min_list = []
        for col in range(0, len(m)):
            min_value = m[0][col]
            for row in range(0, len(m)):
                if min_value > m[row][col]:
                    min_value = m[row][col]
            if min_value == sys.maxsize:
                min_list.append(0)
            else:
                min_list.append(min_value)
        # print(min_list)
        for col in range(0, len(m)):
            if min_list[col] != 0:
                for row in range(0, len(m)):
                    if m[row][col] != sys.maxsize:
                        m[row][col] -= min_list[col]
        # print(sum(min_list))
        return sum(min_list)

    def show(self, node):
        print('Node (%d) created - COST : %d' % (node.id, node.cost))


if __name__ == "__main__":
    INF = sys.maxsize
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

    obj = TravellingSalesman(m1)
    path = obj.optimal_travel_path()
    print('PATH : ', end='')
    for i in range(len(path)):
        print(path[i], end='')
        if i < len(path)-1:
            print(' -> ', end='')
        else:
            print()
