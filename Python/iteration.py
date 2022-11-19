
import math
from copy import copy

# def functionf(x): #f(x)
#     return math.sin(math.pi*x)-x**2

def functiong(x): #g(x)
    return (1/x)-(x/2)

# print(functionf(0))
# print(functiong(0))
#initialx iterationmax tolerance residual
def iteration(x0, itmx, tol, res):
    x = copy(x0)    #copying value of x0  
    xPrev=0 #initializing the previous x
    for i in range(itmx):   #forloop that excutes for the max iterations 
        xPrev = x   #these are for output variables 
        x = functiong(x)
        residual=abs(x)
        estErr=x-xPrev
        print('It:%d, x=%f, err=%e, res=%r' % (i+1,x,estErr,residual))  #displaying the output 
        if(abs(x)<res and abs(x-xPrev)<tol):    #if converged
           print("Estimated error or the residual are below their respective tolerance")
           break    #exits the for loop
        if((i+1)==itmx):    #if reaches max iterations 
            print("max number of iterations is reached")    #for loop stops anyway no need for a break

# iteration(-0.1,20,0.0001,0.00001)
iteration(math.sqrt(2),30,0.000000000000001,0.000000000000001)


