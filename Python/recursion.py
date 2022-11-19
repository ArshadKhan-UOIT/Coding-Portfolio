
import math
# from copy import copy

# def functionf(x): #f(x)
#     return math.sin(math.pi*x)-x**2

def functiong(x): #g(x)
    return ((math.sin(math.pi*x))/(2.*math.pi))-(x**2/(2.*math.pi))+x
#initialx previousx iterationmax tolerance residual counter
def recursion(x0, xPrev, itmx, tol, res, count):
    x=functiong(x0) #get the value from the function 
    if(abs(x)<res and (abs(x-xPrev)<tol) or count>=itmx+1): #if it converged or if the count is greater than or equal to the terationmax
        if((count)>=itmx):  #output statement for when it reaches max iterations 
            print("max number of iterations is reached") 
        if(abs(x)<res and abs(x-xPrev)<tol):    #output statement for when it converges 
            print("Estimated error or the residual are below their respective tolerance") #converged
        return x0   #had to return something to stop ir from doing resursion 
    else:   #if not converged or reached max iterations 
        residual=abs(x)
        estErr=x-xPrev
        print('It:%d, x=%f, err=%e, res=%r' % (count,x,estErr,residual))    #outputting values 
        recursion(functiong(x0),x0,itmx,tol,res,count+1)    #keeps doing the recursion whiles increasing the count 

# recursion(-0.1,-0.1,20,0.0001,0.00001,1)
recursion(1,1,60,0.00001,1,1)