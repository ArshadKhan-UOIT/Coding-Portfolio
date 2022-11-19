import numpy as np

def triDigMatVec(x, a, b, c):                                       #takes in vector x, a, b, and c
    n = np.size(x)                                                  #making n the size of vector x (same as a)
    y = np.zeros(len(x))                                            #declearing a empty vector y that is of size x and 1 column
    for i in range(0,n-2):                                          #looping to the third last row
        y[i] = (a[i]*x[i]) + (b[i]*x[i+1]) + (c[i]*x[i+2])          #puting in every row into vector y until the third last row 
    y[n-2] = (a[n-2]*x[n-2]) + (b[n-2]*x[n-1])                      #puting in vector y until the second last row
    y[n-1] = (a[n-1]*x[n-1])                                        #puting in vector y until the last last row
    return y                                                        #return the result, vector y

# x = np.array([2,2,2])                                               #making a numpy array for x (size n)
# a = np.array([2,2,2])                                               #making a numpy array for a (size n)
# b = np.array([2,2])                                                 #making a numpy array for b (size n-1)
# c = np.array([2])                                                   #making a numpy array for c (size n-2)
# print(triDigMatVec(x, a, b, c))                                     #putting the vectors into the function 
'''
output
[12.  8.  4.]
'''