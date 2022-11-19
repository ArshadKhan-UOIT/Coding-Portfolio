from LUP import *
import numpy as np
import matplotlib.pyplot as plt


x = np.array([-1.2,0.5,2.2,3.1])
y = np.array([-0.4,1.2,5.5,10.2])

def VandermondeMatrix(x):
    n = len(x)
    V = np.zeros([n,n])

    for i in range(n):  #rows
        for j in range(n):  #cols
            V[i, j] = x[i]**j   #first col is to the power 0 (j=0) and rest of cols continue to n
    return (V)  #returning the valdermonde matrix 

# V = VandermondeMatrix(x)
# print(V)
def transpose(matrix):  #transposing the matrix y. Ex. (1x4) -> (4x1)
    # return matrix.transpose()
    n = len(matrix)
    R = np.zeros((n,1))

    for i in range(n):
        R[i,0] = matrix[i]
    
    return R

def getCoefficients(V, Y):  #using LUP to solve for the coefficients for the Vandermonde
    L,U,P,par,ok = LUP(V)
    z = ForwardSub(L,P,Y)
    a = BackwardSub(U,z)
    return (a)

def plotting(C,X,Y):    #plotting the interpolant
    xAxis = []
    yAxis = []
    n = len(C)
    #                     start, stop, num=50, endpoint=True, retstep=False, dtype=None, axis=0
    for i in np.linspace(X[0],X[n-1],100000,endpoint=True,retstep=False,dtype=float):#using 100000 between start and end values t0 create a better curve 
        funcVal = 0
        for j in range(n):
            funcVal = funcVal + (C[j]*i**j) #gets the y values for the y-axis
        xAxis.append(i)
        yAxis.append(funcVal)

    plt.plot(xAxis,yAxis)   #plotting the values 
    plt.scatter(X,Y)    #showing points from the table 
    for i in range(n):  #labeling the points from the scatter plot
        points = "(%.2f, %.2f)" % (X[i],Y[i])   #this is 2 decimal places
        plt.text(X[i],Y[i],points,fontsize=7)
    plt.title("Interpolant")
    plt.xlabel("Xk")
    plt.ylabel("Yk")
    plt.grid()
    plt.show()


# print(transpose(y))
V = VandermondeMatrix(x)
Y = transpose(y)
# Coef = getCoefficients(V, y)
Coef = getCoefficients(V, Y)
# print(Coef)
plotting(Coef,x,y)