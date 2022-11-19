import numpy as np
import math

# Takes an arbitrary array and builds it into a max heap
def buildMaxHeap(A):
    n = len(A)
    for i in range(n//2, 0, -1):
        maxHeapify(A, i)

# Takes an almost-heap with one violation, and fixes the violation 
def maxHeapify(A, i):
    l = 2 * i
    r = 2 * i + 1
    n = len(A)
    if l <= n  and A[l - 1] > A[i - 1]: # if left is bigger 
        largest = l # l is largest
    else:
        largest = i # otherwise i is

    if r <= n and A[r - 1] > A[largest - 1]: # if right is bigger
        largest = r # r is largest

    if largest != i:
        A[i - 1], A[largest - 1] = A[largest - 1], A[i - 1]    #swap
        maxHeapify(A, largest)

# Returns the largest element in the max heap 
def heapMaximum(maxHeap):
    return maxHeap[0]   # the largest is the first element

# Removes and returns the largest element in the max heap 
def heapExtractMax(maxHeap):    
    n = len(maxHeap)
    max = heapMaximum(maxHeap)
    maxHeap[0],maxHeap[n - 1] = maxHeap[n - 1], 0   #swap
    maxHeapify(maxHeap, 1) 
    return max

# Inserts a new element into the heap, preserving the heap property 
def maxHeapInsert(heap, key):
    heap = np.append(heap, key) # appending key to heap array
    i = len(heap)
    while heap[i - 1] > heap[i//2 - 1] and i > 1:
        heap[i - 1], heap[i//2 - 1]  = heap[i//2 - 1], heap[i - 1]  #swap
        i = i//2
    return heap

# Prints the array representation
def printAsArray(heap):
    print(heap)

# Prints the heap as a sideways tree 
def printAsTree(heap):  #finds the depth then calls printTree
    d = int(math.log2(len(heap)))
    printTree(heap, d, 0, 1)

# printTree then prints it as a side ways tree 
def printTree(heap, depthMax, space, heapIndex):
    str = ''
    n = len(heap)
    for i in range(space):
        str = str + '\t'
    if space == depthMax:
        if heapIndex <= n:
            print(str, heap[heapIndex - 1])
        return 
    printTree(heap, depthMax, space + 1, heapIndex * 2 + 1)
    print(str, heap[heapIndex - 1]) # how the tree gets printed (spacing, heapValue) 
    printTree(heap, depthMax, space + 1, heapIndex * 2)

# Function that takes an arbitrary array, and sorts it using a heap
def heapSort(heap):
    tmpArr = []
    buildMaxHeap(heap)
    for i in range(len(heap), 0, -1):
        temp = heap[0]
        heap[0] = heap[i - 1]
        tmpArr.append(temp)
        heap = np.delete(heap, len(heap) - 1)
        maxHeapify(heap, 1)
    return tmpArr

arr = np.array([81,64,37,21,58,24,11,14,7,23])
print('print as arr')
print('')
printAsArray(arr)
print('print as tree')
print('')
printAsTree(arr)
print('')


print('inserting 79')
print('')
arr = maxHeapInsert(arr,79)
print('')
print('print as arr')
print('')
printAsArray(arr)
print('print as tree')
print('')
printAsTree(arr)
print('')

# print('max heap extract 1')
# print('')
# max = heapExtractMax(arr)
# print('')
# print('print as arr')
# print('')
# printAsArray(arr)
# print('print as tree')
# print('')
# printAsTree(arr)
# print('')

# print('max heap extract 2')
# print('')
# max2 = heapExtractMax(arr)
# print('')
# print('print as arr')
# print('')
# printAsArray(arr)
# print('print as tree')
# print('')
# printAsTree(arr)
# print('')

# print('max heap extract 3')
# print('')
# max3 = heapExtractMax(arr)
# print('')
# print('print as arr')
# print('')
# printAsArray(arr)
# print('print as tree')
# print('')
# printAsTree(arr)
# print('')



# # arr = np.array([16,14,10,8,7,3,9,1,4,2])
# # print("Printing as array before building a max heap:")
# print('')
# printAsArray(arr)
# print('')
# buildMaxHeap(arr)
# print("Printing as array before building a max heap:")
# print('')
# printAsArray(arr)
# print('')

# print("Printing as tree after building a max heap:")
# print('')
# printAsTree(arr)
# print('')

# print(f'Heap Maximum  = {heapMaximum(arr)}')
# print('')

# print("Printing as array before heap extract max:")
# print('')
# printAsArray(arr)
# print('')
# print("Printing as array before heap extract max:")
# print('')
# printAsTree(arr)
# print('')
# max = heapExtractMax(arr)
# print(f'Heap Extract Max = {max}')
# print("Printing as array after heap extract max:")
# print('')
# printAsArray(arr)
# print('')
# print("Printing as array after heap extract max:")
# print('')
# printAsTree(arr)
# print('')

# arr = np.array([16,14,10,8,7,3,9,1,4,2])
# print("Printing as array before max heap insert of 132:")
# print('')
# printAsArray(arr)
# print('')
# print("Printing as array before max heap insert of 132:")
# print('')
# printAsTree(arr)
# print('')
# arr = maxHeapInsert(arr,132)
# print("Printing as array after max heap insert of 132:")
# print('')
# printAsArray(arr)
# print('')
# print("Printing as array after max heap insert of 132:")
# print('')
# printAsTree(arr)
# print('')

# arr = np.array([16,14,10,8,7,3,9,1,4,2,18])
# print("Printing as array before heap sort:")
# print('')
# printAsArray(arr)
# print('')
# print("Printing as array before heap sort:")
# print('')
# printAsTree(arr)
# print('')
# s = heapSort(arr)
# print("Printing as array after heap sort:")
# print('')
# printAsArray(s)
# print('')
# print("Printing as array after heap sort:")
# print('')
# printAsTree(s)
# print('')