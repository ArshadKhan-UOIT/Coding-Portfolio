import matplotlib.pyplot as plt 
import numpy as np
import scipy.linalg

def makeLinearSystem(xArray):
    Results = np.zeros((len(xArray),2))
    n = len(xArray)
    for i in range(n):
        for j in range(2):
            if (j==0):
                Results[i,j] = 1
            else:
                Results[i,j] = xArray[i]
    return Results

def makeLinear(yArray):                 #transposes y
    n = len(yArray)
    Results = np.zeros((n,1))
    for i in range(n):
        Results[i,0] = yArray[i]
    return Results

def grapth(coef,xArray,yArray):
    x = []
    y = []
    n = len(coef)
    for i in np.linspace(xArray[0],xArray[len(xArray)-1],10000,endpoint=True,retstep=False,dtype=float):    #used 10000 between start and end
        x.append(i) #putting in elements to the x array for ploting
        f=0
        for j in range(n):
            f += (coef[j]*i**j)
        y.append(f) #putting in elements to the y array for ploting
    plt.plot(x,y)
    plt.scatter(xArray,yArray)
    for i in range(len(xArray)):  #labeling the points from the scatter plot
        points = "(%.2f, %.2f)" % (xArray[i],yArray[i])   #this is 2 decimal places
        plt.text(xArray[i],yArray[i],points,fontsize=7)
    plt.title("Least-square Interpolant")
    plt.xlabel("X")
    plt.ylabel("Y")
    plt.grid()
    plt.show()

xArray = np.array([-.75,0.5,1.25,2.5])
yArray = np.array([-1.89,0.72,1.42,2.16])

a=makeLinearSystem(xArray)                                                          #making the A (in Ax=b)
print(a)
b=makeLinear(yArray)                                                                #transposing, making the b (in Ax=b)
print(b)

LS = scipy.linalg.lstsq(a,b)                                                     #computes the least-square solution 
print("Least Squares Solution: ") 
print(LS[0])                                                                     #Least-squares solution.

print("Least Squares Error: ") 
print(LS[1])                                                                     #Sums of residuals; squared Euclidean 2-norm for each column in b - a*x.

grapth(LS[0],xArray,yArray)

#linalg.lstsq returns ...
#
#LS[0]
#x : {(N,), (N, K)} ndarray
#Least-squares solution. If b is two-dimensional, the solutions are in the K columns of x.
#
#LS[1]
#residuals : {(1,), (K,), (0,)} ndarray
#Sums of residuals; squared Euclidean 2-norm for each column in b - a*x. If the rank of a is < N or M <= N, this is an empty array. If b is 1-dimensional, this is a (1,) shape array. Otherwise the shape is (K,).
#
#LS[2]
#rank : int
#Rank of matrix a.
#
#LS[3]
#s : (min(M, N),) ndarray
#Singular values of a.
