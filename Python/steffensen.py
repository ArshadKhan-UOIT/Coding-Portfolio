import math
from copy import copy

def function(x):    #function from 2b
    answer = math.exp(-x**2+x)-x/2-1.0836
    return answer
def functionp(x):   #derivative of function from 2b
    answer = (((-2*x)+1)*math.exp(-x**2+x))-(1/2)
    return answer 



def newton(F,DF,x0):
    x=copy(x0)  #copying the value of x0 to x
    r = F(x)                                          # Compute residual.
    dx = -r/DF(x)                                     # Compute update step.
    x = x + dx                                        # Apply update step.
    return x    #return x to steff

def steffensen(function,functionp,x,esp,N):
    conv=0
    for i in range(N):
        y1=x    #Set y1 = x.
        y2=newton(function,functionp,y1)    #Take one Newton step, starting from y1. Call the result y2.
        y3=newton(function,functionp,y2)    #Take one Newton step, starting from y2. Call the result y3.
        x=y1-(((y2-y1)**2)/(y3-2*y2+y1))    #setting x to the equation in the assignment pdf
        absolV=(abs(function(x)))   #using this for displaying and use for the if statement  
        print("It:",i," |f(x)|=",absolV)
        if(absolV<esp):
            conv=1  #if convergence=0 then it outputs no convergence 
            print("converged!")
            break
    if (conv==0):
        print("No convergence!")
    return x
print("Steffenens:")
print(steffensen(function, functionp, 1, 0.0000000001, 10))




#taken from lecture 
def newtonTest(F,DF,x0,tolf,tolx,kmax):
    x = x0                                                # Initialize the approximate solution.
    conv = 0                                              # By default set the convergence flag to 0 (false).
    for k in range(1,kmax):                               # Loop over Newton iterations.
        r = F(x)                                          # Compute residual.
        dx = -r/DF(x)                                     # Compute update step.
        x = x + dx                                        # Apply update step.
        err = abs(dx)                                     # Estimate error.
        res = abs(F(x))                                   # Compute residual.
        print('it=%d x=%e err=%e res=%e' % (k,x,err,res)) # Print error and residual for diagnostic purposes.
        if err < tolx and res < tolf:                     # Check for convergence.
            conv = 1                                      # Flag convergence.
            break                                         # Exit loop.
    if conv == 0:                                         # if no convergence after kmax iterations print warning.
        print('No convergence!')
    return x,err,res
print()
print("Newtons")
print(newtonTest(function, functionp, 1, 0.0000000001,0.0000000001, 10))