import numpy as np

def search(A, l, h, x):
    # so if the x is not found in A
    # because recursion was used 
    # it causes the new value of l to be larger then the h
    # this is how we check for when x is not in A
    if (l > h): 
        return None
    m = (l + h)//2
    # once the recursion steps narrows it down
    # the m is the index for the value of x in A
    if A[m] == x:
        # we just display the information need for part 3
        return 'Element [{x}] is located at index A[{m}]'.format(x = x, m = m) 
    
    if A[m] >= A[l]:  # if low to mid is already sorted
        if x >= A[l] and x <= A[m]:  # checking if the element we want is between A[l] to A[m]
            return search(A, l, m - 1, x) # subtract the mid so we can narrow down where between A[l] to A[m] is it
        return search(A, m + 1, h, x) # otherwise its between A[m] to A[h] and add the mid to narrow down 
    if x >= A[m] and x <= A[h]:  # otherwise if its not sorted, checking for x between A[m] to A[h] 
            return search(A, m + 1, h, x)   # increment the mid so we can narrow it down between A[m] to A[h]
    return search(A, l, m - 1, x)   #otherwise its between A[l] to A[m] and subtract the mid to narrow down

A = np.array([4,5,9,10,1])    
# A = np.array([5,9,10,1,4])  
# A = np.array([9,10,1,4,5])  
# A = np.array([10,1,4,5,9])  
# A = np.array([1,4,5,9,10])  
n = len(A)
x = 9
s = search(A, 0, n - 1 , x)
print(s)