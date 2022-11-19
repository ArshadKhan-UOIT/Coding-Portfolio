# minimum edit distance/Levenshtein's algorithm
import numpy as np

#operation costs
#insert = 1
#delete = 1
#substitute = 2

print('operation costs')
print('insert = 1')
print('delete = 1')
print('substitute = 2')
print('\n')

def minEditDist(x,y):
    n = len(x)
    m = len(y)
    D = np.zeros((n+1, m+1))
    
    for i in range(0,n+1):
        D[i,0] = i
        
    for j in range(0,m+1):
        D[0,j] = j
    
    for i in range(1,n+1):
        for j in range(1,m+1):
            insert = D[i-1,j] + 1
            delete = D[i,j-1] + 1
            
            if x[i-1] != y[j-1]:
                substitute = D[i-1,j-1] + 2
            else:
                substitute = D[i-1,j-1] + 0
            
            D[i,j] = min(insert, delete, substitute)
            
    print(x, 'to', y)
    print('Table\n', D)
    print('minimum edit distance =', D[n,m], '\n')
      
minEditDist("spoof","stool")
minEditDist("podiatrist","pediatrician")
minEditDist("blaming","conning")
