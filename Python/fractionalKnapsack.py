import numpy as np

def FractionalKnapsack(weight, value, capacity):
    n = len(weight)
    cost = np.zeros(n)
    sortCost = np.zeros(n)
    tmpCost = np.zeros(n)
    items = np.zeros(n)
    maxVal = 0

    for i in range(n):
        cost[i] = value[i] / weight[i]

    maxIndex = []
    sortCost = np.copy(cost)
    tmpCost = np.copy(cost)
    sortCost = desendIndex(sortCost)
    # print('c1 = ',cost)
    # print('c2 = ',sortCost)
    # print('c3= ',tmpCost)
    for i in range(n):
        for j in range(n):
            if (sortCost[i] == tmpCost[j]):
                maxIndex.append(j)  # the index's of the max index     

    print('Value: ',value)
    print('Weight: ',weight)
    print('Cost: ',cost)
    print('Index Ratio''s: ',maxIndex)
    
    for i in maxIndex:
        if weight[i] <= capacity:
            capacity -= weight[i]
            maxVal += value[i]
            items[i] = 1
        else:
            fraction = capacity / weight[i]
            maxVal += value[i] * fraction
            items[i] = fraction
            break

    return items, maxVal


def desendIndex(arr):   # regular sorting function 
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            if arr[i] < arr[j]:
                arr[i], arr[j] = arr[j], arr[i]
    return arr

weight = [1, 2, 3, 5, 7]
value = [6, 11, 22, 35, 60]
items, maxVal = FractionalKnapsack(weight, value, 5.5)
print(f'Max Value: {maxVal}')
print('')
print(f'Fraction items: {items}')
