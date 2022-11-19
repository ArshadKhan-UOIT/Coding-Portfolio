
import numpy as np                                  #used for the array, technically not need since we already imported from banded_matvec.py file  
import matplotlib.pyplot as pl                      #plotting lib for displaying graph of results 
import time                                         #using time lib for finding computing time of the function for each matrix size 
from banded_matvec import *                         #importing all the contents from banded_matvec.py
from dotproduct import *                                 #importing all the contents from bonus.py

times = []                                          #declearing a array holds the time in seconds for each matrix size 
n = []                                              #declearing a array holds the matrix size's
times2 = []                                         #declearing a array holds the time in seconds for each matrix size 

print("Legend:")                                
print("(A) is the function from banded_matvec.py")
print("(B) is the function from bonus.py")
for k in range(2,5):                                    #iterationg the for loop from 2 to 4, more than 4 will be an error 
    x = np.random.rand(10**k)                           #generating random numbers for x
    a = np.random.rand(10**k)                           #generating random numbers for a
    b = np.random.rand(10**k-1)                         #generating random numbers for b
    c = np.random.rand(10**k-2)                         #generating random numbers for c

    n.append(10**k)                                     #appending the size of each matrix
    print()
    print("(A) Computing Matrix of size",10**k)         #displaying the size of operation thats about to be computed
                                                        #for getting computing time of the triDigMatVev function 
    start = time.time()                                 #declearing the start time 
    triDigMatVec(x, a, b, c)                            #putting in the x, a, b, and c into the function 
    current = time.time()                               #declearing the current time 
    seconds = current - start                           #finding the difference in seconds 
    
    times.append(seconds)                               #appending the times for each iteration of the for loop for the value of k
    # print(seconds)
    print("(A) Finished. It took",seconds,"seconds.")   #displaying when its finished computing and time in seconds it took 
    print()

    print("(B) Computing Matrix of size",10**k)         #displaying the size of operation thats about to be computed
    MAT = builtInDotProduct(x, a, b, c)                 #putting in the x, a, b, and c into the function, i cannot put this in the start time the results will be flawed. This is explained in bonus.py 
    start2 = time.time()                                #declearing the start time 
    # np.dot(MAT,x)                                     #np.matmul/np.dot to compute the dot product of matrix
    np.matmul(MAT,x)                                    #using this for the time of the program
    current2 = time.time()                              #declearing the current time 
    seconds2 = current2 - start2                        #finding the difference in seconds
    print("(B) Finished. It took",seconds2,"seconds.")  #displaying when its finished computing and time in seconds it took 
    times2.append(seconds2)                             #appending the times for each iteration of the for loop for the value of k
print("outputting graph...")                            #displating that the graph will be outputting 
pl.loglog(times, n, label="(A)")                        #log scaling type of pyplot
pl.loglog(times2, n, color='red',label="(B)")           #log scaling type of pyplot
pl.legend(loc="lower right")                            #making a lenend for the two plots 
pl.title("Time vs. N")                                  #title of the graph
pl.ylabel('Matrix Size (n)')                            #labeling the x coordinate 
pl.xlabel('Computing Time (sec)')                       #labeling the y coordinate 
pl.show()                                               #to display/show the graph