import numpy as np 
import math
import matplotlib.pyplot as plt

def f(x):
    return math.log(x)      #function in question

def fp(x):
    return 1/x              #derivative of function 

def fowardDiff(x,h):                #for the foward difference
    return (f(x+h)-f(x))/h

def centredDiff(x,h):               #for the centered difference 
    return (f(x+h)-f(x-h))/(2*h)

def fd(x):                          #computes the finite difference 
    x0 = x
    n = 16
    h = []
    Ep = []
    E = []
    Oh = []
    Oh2 = []
    for i in range(n):                      #from 0 to 15
        h.append(10**(-i))               #getting the h val
        Ep.append(abs(fp(x0)-fowardDiff(x0,h[i])))      #array for Ep, calculated the Ep and putting it in an array
        E.append(abs(fp(x0)-centredDiff(x0,h[i])))      #array for E, calculated the E and putting it in an array
        print("%e %e %e" % (h[i],Ep[i],E[i]))           #printing results 
        Oh.append(h[i])                         #for plotting O(h)
        Oh2.append(h[i]**2)                     #for plotting O(h^2)
    plt.loglog(h,Ep,label="$Ep$")   #ploting all of the results on the line 
    plt.loglog(h,E,label="$E$")
    plt.loglog(h,Oh,'--', label="$O(h)$")       #different lines of O(h) and O(h^2)
    plt.loglog(h,Oh2,'--', label="$O(h^2)$")
    plt.ylim(h[-3],1)                   #to limit the y axis
    plt.legend(loc = "lower right")             #to put in a legend
    plt.title("Finite-Difference")                  #graph title
    plt.show()                          
fd(2)   #we are approximating at x=2
'''
Console Output:
1.000000e+00 9.453489e-02 4.930614e-02
1.000000e-01 1.209836e-02 4.172928e-04
1.000000e-02 1.245849e-03 4.166729e-06
1.000000e-03 1.249583e-04 4.166662e-08
1.000000e-04 1.249958e-05 4.168337e-10
1.000000e-05 1.249986e-06 8.826717e-12
1.000000e-06 1.249412e-07 1.437783e-11
1.000000e-07 1.303074e-08 2.631779e-10
1.000000e-08 3.038735e-09 3.038735e-09
1.000000e-09 4.137019e-08 4.137019e-08
1.000000e-10 4.137019e-08 4.137019e-08
1.000000e-11 4.137019e-08 4.137019e-08
1.000000e-12 4.445029e-05 4.445029e-05
1.000000e-13 3.996389e-04 3.996389e-04
1.000000e-14 1.070259e-02 5.151476e-03
1.000000e-15 5.591079e-02 3.996389e-04
'''