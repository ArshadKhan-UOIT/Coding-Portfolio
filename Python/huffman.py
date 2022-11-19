#!/usr/bin/python3
import sys

'''
how to run 
'python3 p4.py code.txt'
Make sure the txt file you want to use is in the same directory

From lecture:

Huffman(c)
n = |c|
Q = c
for i = 1 to n - 1
    allocate a new node z
    z.left = y = Extract-Min(Q)
    z.right = x = Extract-Min(Q)
    z.freq = x.freq + y.freq
    insert(Q.z)
return Extract-Min(Q)   //return the root of the tree
'''
class Node:
    def __init__(self, freq, left, right, character):
        self.left = left
        self.right = right
        self.freq = freq
        self.character = character
    
    def __gt__(self,other):
        return self.freq > other.freq

def getTableData(node, prefix = ""):
    if (node.left == None or node.right == None):
        if (node.left == None and node.right == None):
            return node.character, node.freq, prefix
        elif (node.left == None):
            prefix += "1"
            return getTableData(node.right, prefix)
        elif (node.right == None):
            prefix += "0"
            return getTableData(node.left, prefix)
    elif (node.left != None and node.right != None):
        return getTableData(node.right, prefix + "1") + getTableData(node.left, prefix + "0")

def FormatTable(nList):
    print('Character\tFrequency\tPrefix')
    table = getTableData(nList[0])
    for i in range(len(table)):
        if (i % 3 == 0 and i != 0):
            print()
        print(table[i], end = "\t\t")
    print()

def Huffman(frequencyList):
    nList = []
    
    for i in frequencyList:
        nList.append(Node(i[1],None,None,i[0]))

    newNList = []
    while len(nList) > 1:
        left = min(nList)
        nList.remove(left)

        right = min(nList)
        nList.remove(right)

        frequency = left.freq + right.freq
        newNList = Node(frequency, left, right, None)

        nList.append(newNList)
    return nList

def getLength(node, prefix = ""):
    if (node.left == None or node.right == None):
        if (node.left == None and node.right == None):
            return len(prefix) * node.freq
        elif (node.left == None):
            prefix += "1"
            return getLength(node.right)
        elif (node.right == None):
            prefix += "0"
            return getLength(node.left, prefix)
    elif (node.left != None and node.right != None):
        return getLength(node.right, prefix + "1") + getLength(node.left, prefix + "0")

def FormatLength(nList, data):
    newlength = getLength(nList[0])
    print('Old Lenght of bits: ',len(data)*8,' Bits')   # 8 bits per
    print('New Length of bits (After using Greedy Huffman''s Algorithm): ',newlength, ' Bits')
    
def getFrequencyList(data):
    frequency = {}
    for x in data:
        if x in frequency:
            frequency[x] += 1
        else:
            frequency[x] = 1
    frequentList = list(frequency.items())
    return frequentList

            
if len(sys.argv) == 2:
    fileName = str(sys.argv[1])
    with open(fileName, 'r') as file:
        data = file.read().replace('\n', '')

    frequencyList = getFrequencyList(data)  # gets the frequent for each letter 
    nList = Huffman(frequencyList)   # makes a node list from huffman algo
    FormatTable(nList)   # displays the table
    print()
    FormatLength(nList, data)    # displays the calculated length of the new and old document 
else:
    print('usage: q4.py <inputfile>')
    sys.exit(1)
