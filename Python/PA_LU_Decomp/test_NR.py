import numpy as np

'''
x1 = x[0]
x2 = x[1]
x3 = x[2]
'''
def f(x):                                                       #for when NR calls the function, x is an array thats 3x1 that is given in NR
    y = np.zeros((3,1))                                         #creating an empty 3x1 matrix of zeros to fill with functions in Q1)         
    y[0] = -x[1]**2 - x[2]**2 - (x[0]/4) + 2                    #function 1 from Q1)
    y[1] = x[0]*x[1] - 4*x[0]*x[2] - x[1] + 1                   #function 2 from Q1)
    y[2] = 4*x[0]*x[1] + x[0]*x[2] - x[2]                       #function 3 from Q1)
    return y                                                    #returning it

def Df(x):                                                      #functions for 'partial' derivatives, what NR call it. x is an array thats 3x1 that is given in NR. (Jocobian functions in a matrix)
    J = np.zeros((3,3))                                         #creating an empty 3x3 matrix of zeros to fill with partial derivatives for each function in Q1) with respect to x1, x2, and x3
    J[0,0] = -(1/4)                                             #partial derivative of function 1 in Q1) with respect to x1
    J[0,1] = -2*x[1]                                            #partial derivative of function 1 in Q1) with respect to x2
    J[0,2] = -2*x[2]                                            #partial derivative of function 1 in Q1) with respect to x3
    J[1,0] = x[1] - 4*x[2]                                      #partial derivative of function 2 in Q1) with respect to x1
    J[1,1] = x[0] - 1                                           #partial derivative of function 2 in Q1) with respect to x2
    J[1,2] = -4*x[0]                                            #partial derivative of function 2 in Q1) with respect to x3
    J[2,0] = 4*x[1]+x[2]                                        #partial derivative of function 3 in Q1) with respect to x1
    J[2,1] = 4*x[0]                                             #partial derivative of function 3 in Q1) with respect to x1
    J[2,2] = x[0] - 1                                           #partial derivative of function 3 in Q1) with respect to x1
    return J                                                    #returning the partial derivatives 

def NR(x0,f,Df,epsx,epsf,itmx):                                 #for returning Newton-Raphson Iteration
    x = np.copy(x0)                                             #takes a copy of initial x (3x1)
    for k in range(itmx):                                       #for loop for max iterations 
        r = - f(x)                                              #process for calculating the dx, gets the negative value for the functions with a given x
        J = Df(x)                                               #process for calculating the dx, gets the partial derivatives for the partial functions (with respet to x1, x2, and x3) with a given x
        dx = np.linalg.solve(J,r)                               #solves the dx 
        x += dx                                                 #adds dx to x (x=x+dx)
        err = np.linalg.norm(dx,2)                              #calculates the error
        res = np.linalg.norm(r,2)                               #calculates the residual
        print("%d err=%e res=%e" %(k,err,res))                  #prints info. prints the max iterations, the error, and residual 
        if err < epsx and res < epsf:                           #if it meets the converged conditions 
            print("Converged!")                                 #prints converged
            return x,err,res                                    #returns the nessessary info which also breaks the for loop
    print("Warning: no convergence!")                           #otherwise prints does not converge, this is shown when the for loop reaches max iterations 
    return x,err,res                                            #and output the nessessary info 

x = np.array([[7.0],[0.0],[0.0]])                               #For this specific questions there exists a solution when x = (7, 0, 0)^t, so im just creating an 3x1 array with those values to put into NR 
print(NR(x,f,Df,0.000000000001,0.000000000001,10))              #putting in the nessessary arguments into NR, and printing the NR to get an output for its return statements within NR 