from compositeSimpson import *  
M = 1                               #given in question                                        
a = 0.  #a and b are given in the questions 
b = 3.  
actual = 0.4999382950979567
while (True):
    I = compositeSimpson(f,a,b,M)                                            
    # h = (b-a)/M
    err = abs(I-actual)                                                     #compute error, by absolute value of the difference between approx and actual 
    # err = ((b-a)/2880)*(h**4)*(16.357)                                      #16.357 from max in fourth deriv, computes the err 
    print("%d %e" % (M,err))                                                #print statement for M and err
    if (err <= 0.000000000001):                                              #exits only when the error is less than 1x10^-12 
        print("LIMIT: err < ",u"10\u207B\u00B9\u00B2")                      #printing the last results once is says it has reached the limits 
        print("M = %d, err = %e" % (M,err))
        break
    M += 1  #increment the subintervals once the error is still less than 1x10^-12
print("I = ",I) #prints the composite value of the Simpson formula
