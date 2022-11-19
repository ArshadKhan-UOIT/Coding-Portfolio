import numpy as np
import math

def f(x):                           #function thats given in the question
    return (math.exp(-x**2))

# def compositeSimpson(f,a,b,M):                                                      
#     h = (b-a)/M                     #calculates H                                              
#     x = []
#     I = 0.
#     for l in range(0,M+1):            #initialized the endpoints
#         x.append(a+(l*h))           #endpoint into x
#     for k in range(1,M+1):
#         I += (f(x[k-1]) + 4.*f((x[k-1]+x[k])/2) + f(x[k]))  #using the composite Simpson formula 
#     I *= (h/6.)                                             #multiply exerything by h/6
#     return I                                                #return it
    
def compositeSimpson(f,a,b,M):
    h = (b-a)/float(M)
    xs = np.linspace(a,b,M+1)
    I = f(a) + f(b)
    for k in range(1,M):
        I += 2.0 * f(xs[k])
    for k in range(1,M+1):
        I += 4.0 * f((xs[k-1]+xs[k])/2.0)
    I *= h/6.0
    return I
M = 1
while (True):
    print(compositeSimpson(f,0,1,M))
    M+=1
    if (M==5): break