

def getDigit(num,digit):
    working = num//10**(digit-1)
    return working %  10

#Counting sort
def countingSort(arr, digit): 
    c = arr.copy()
    for i in range(len(c)):
        c[i] = getDigit(c[i], digit)
    
    maximum = int(max(c))
    minimum = int(min(c))
    
    count = [0 for _ in range(10)] 
    output = [0 for _ in range(len(arr))] 
  
    for i in range(0, len(arr)): 
        
        count[getDigit(arr[i],digit)-minimum] += 1 
  
    for i in range(1, len(count)): 
        count[i] += count[i-1] 
  
    for i in range(len(arr)-1, -1, -1): 
        output[count[getDigit(arr[i],digit) - minimum] - 1] = arr[i]
        count[getDigit(arr[i],digit) - minimum] -= 1
    
    
    return output 
    

#Radix sort
def radixSort(arr, digits):
    for i in range(1,digits+1):
        arr = countingSort(arr,i)
    
    return arr


