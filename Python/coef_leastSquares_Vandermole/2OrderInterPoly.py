import numpy as np
from scipy.interpolate import CubicSpline
import matplotlib.pyplot as plt
import math
from LUP import *

x = [1,1.5,2]

def f(x):
    X = math.log((x+2)/(x+1))
    return X

def yVal(x):
    x0 = x
    n = len(x)
    y = np.zeros((n))
    for i in range(n):
        y[i] = f(x0[i])
    return y
# print(yVal(x))

def makeK(x):
    x0 = x
    n = len(x)
    K = np.zeros([n,n])
    for r in range(n):
        for c in range(n):
            K[r,c] = math.pow(x0[r],c)
    return K

# print(makeK(x))

def getCoefficients(K, Y):  #using LUP to solve for the coefficients for the Vandermonde
    L,U,P,par,ok = LUP(K)
    z = ForwardSub(L,P,Y)
    a = BackwardSub(U,z)
    return (a)

Y = yVal(x)
K = makeK(x)
coef = getCoefficients(K,Y)
print(coef)
