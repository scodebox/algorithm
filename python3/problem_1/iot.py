import heapq


class IdGenerator:
    '''
    ID Generator.
    Takes dict of MAC address : probability and generate unique ID using Huffman Coding Technique.
    '''

    def __init__(self, device_list):
        self.device_list = device_list
        self.device_heap = []
        self.device_ids = {}

    class HeapNode:
        '''
        This is the class of Devices. Takes the MAC address of devices and the probability.
        For leaf node left and right will be None.
        For internal node left and right will be holding the child node.
        '''

        def __init__(self, mac, probability):
            self.mac = mac
            self.probability = probability
            self.left = None
            self.right = None

        # Operator Overloading

        # lessthan will compare the probability of two object.
        def __lt__(self, other):
            return self.probability < other.probability

        # equal will check equality of probability of two object.
        def __eq__(self, other):
            if other == None:
                return False
            if not isinstance(other, IdGenerator.HeapNode):
                return False
            return self.probability == other.probability

        # Show the details.
        def show_details(self):
            print('MAC : ', self.mac)
            print('PROB : ', self.probability)
            print('LEFT NODE : ', self.left)
            print('RIGHT NODE', self.right)

    def build_heap(self):
        for mac in self.device_list.keys():
            # Create HeapNode of each devices.
            new_node = self.HeapNode(mac, self.device_list[mac])
            # Adding into heap.
            heapq.heappush(self.device_heap, new_node)

    def build_tree_structure(self):
        while len(self.device_heap) > 1:
            # Heapify the device_heap list.
            heapq.heapify(self.device_heap)

            # Extracting two minimal node.
            node1 = heapq.heappop(self.device_heap)
            node2 = heapq.heappop(self.device_heap)

            # Creating new node and setting left and right child.
            new_node = self.HeapNode(
                None, (node1.probability+node2.probability))
            new_node.left = node1
            new_node.right = node2

            # Adding new node into heap.
            heapq.heappush(self.device_heap, new_node)

    def generate_id(self, root, current_id=''):
        # If the node is the leaf node.
        if (root.left == None) and (root.right == None):
            self.device_ids[root.mac] = current_id
            # print(root.mac,current_id)
            return
        else:
            # recursive call for internal nodes.
            self.generate_id(root.left, current_id+'0')
            self.generate_id(root.right, current_id+'1')

    def generate(self):
        self.build_heap()
        self.build_tree_structure()
        head = self.device_heap[0]
        self.generate_id(head)
        return self.device_ids


if __name__ == '__main__':
    device_details = {
        '75:56:92:75:c7:7a': 0.11,
        '92:6b:7e:82:3b:46': 0.22,
        '0f:fe:0f:23:32:6a': 0.16,
        'da:be:77:8e:5e:c3': 0.12,
        '82:cd:f7:d7:25:27': 0.15,
        'c6:ed:fb:56:22:92': 0.10,
        '4c:5d:00:ef:a2:7f': 0.14
    }

    x = IdGenerator(device_details)
    print(x.generate())