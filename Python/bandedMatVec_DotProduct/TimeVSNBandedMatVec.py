
import numpy as np                                  #used for the array, technically not need since we already imported from banded_matvec.py file  
import matplotlib.pyplot as pl                      #plotting lib for displaying graph of results 
import time                                         #using time lib for finding computing time of the function for each matrix size 
from banded_matvec import *                         #importing all the contents from banded_matvec.py

times = []                                          #declearing a array holds the time in seconds for each matrix size 
n = []                                              #declearing a array holds the matrix size's
for k in range(2,8):                                #iterationg the for loop from 2 to 7
    x = np.random.rand(10**k)                       #generating random numbers for x
    a = np.random.rand(10**k)                       #generating random numbers for a
    b = np.random.rand(10**k-1)                     #generating random numbers for b
    c = np.random.rand(10**k-2)                     #generating random numbers for c

    n.append(10**k)                                 #appending the size of each matrix
    print("Computing Matrix of size",10**k)         #displaying the size of operation thats about to be computed
                                                    #for getting computing time of the triDigMatVev function 
    start = time.time()                             #declearing the start time 
    triDigMatVec(x, a, b, c)                        #putting in the x, a, b, and c into the function 
    current = time.time()                           #declearing the current time 
    seconds = current - start                       #finding the difference in seconds 

    times.append(seconds)                           #appending the times for each iteration of the for loop for the value of k
    # print(seconds)
    print("Finished. It took",seconds,"seconds.")   #displaying when its finished computing and time in seconds it took 
print("outputting graph...")                        #displating that the graph will be outputting 
pl.loglog(n, times, label="Actual")                 #log scaling type of pyplot for y
pl.plot(n, n, label="Prediction")                   #plotting the prediction of O(n)
pl.legend(loc="lower right")                        #making a lenend for the two plots                                  
pl.title("Time vs. N")                              #title of the graph
pl.xlabel('Matrix Size (n)')                        #labeling the x coordinate 
pl.ylabel('Computing Time (sec)')                   #labeling the y coordinate 
pl.show()                                           #to display/show the graph