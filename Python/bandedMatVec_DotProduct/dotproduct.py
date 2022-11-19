import numpy as np

"""
    The way this program works is by allocating the empty nxn matrix 
    with x, a, b, and c 
    then just return that martix 

    This function is being imported into compareBoth.py for the testing of the computing  
    for the result to be shown in the plot
    i did not return the dot product of the function because if i did then
    the results in compareBoth.py would be flawed for (B) becasue it would
    also be including the time of the for the for loop. 
    """
def builtInDotProduct(x, a, b, c):          #take in vectors x, a, b, and c 
    n = len(x)                              #n as the size of matrix x
    A = np.zeros((n,n))                     #initializing A to be an nxn matrix of zeros
    for i in range(0,n-2):                  #for loop to go to the third last row
        A[i,i] = a[i]                       #putting matrix a into A accross the diagonal to n-2
        A[i,i+1] = b[i]                     #putting matrix b into A accross the n+2 diagonal to n-2
        A[i,i+2] = c[i]                     #putting matrix c into A accross the n+2 diagonal to n-2
    A[n-2,n-2] = a[n-2]                     #putting matrix a into A for the position (n-2, n-2)
    A[n-2,n-1] = b[n-2]                     #putting matrix b into A for the position (n-2, n-1)
    A[n-1,n-1] = a[n-1]                     #putting matrix b into A for the position (n-2, n-1)
    return A                                #returning the matrix A


# x = np.array([2,2,2])                      #testing the program 
# a = np.array([2,2,2])                                               
# b = np.array([2,2])                                                 
# c = np.array([2])                                                      
# Matrix = builtInDotProduct(x, a, b, c)
# print(np.matmul(Matrix,x))
'''
output 
[12.  8.  4.]
'''