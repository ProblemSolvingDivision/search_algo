#LINEAR SEARCH
arr = [1, 3, 4, 8 ,11, 20]
n = len(arr)

x = 8
pos = -1


for i in range(n):
    if(arr[i] == x):
        pos = i
        break
if(pos == -1):
    print(f"{x} is not found in the list.")
else:
    print(f"the position of {x} is : {pos}")

#BINARY SEARCH
#iterative solution
def binarySearch(list, l, r, x):
    while(l <=r):
        mid = (l+r) / 2
        
        #Checks if x is present at mid
        if (arr[mid] == x):
            return mid
        
        # if x greater, ignore left half
        if (arr[mid] < x):
            l = mid + 1
        
        #if x is smaller, ignore right half
        else:
            r = mid - 1
    #if we've reached here, all the elements have been checked but
    #there was no match.
    return -1

#recursive solution
def binarySearch_rec(list, l, r, x):
    if (r >= l):
        mid = (r + l) / 2
        
        if (arr[mid] == x):
            return mid
        
        #if element is smaller than mid, then
        #it can only be present in left subarray
        if (arr[mid] > x):
            return binarySearch_rec(arr, l, mid -1, x)
        
        #else the element can only be present
        #in right subarray
        return binarySearch_rec(arr, mid + 1, r, x)
    
    #Just like the iterative solution, this is where we've
    #searched all the elements but no match was found.
    return -1

#library function for binary search
from bisect import bisect_left 
  
def BinarySearch(a, x): 
    i = bisect_left(a, x) 
    if i != len(a) and a[i] == x: 
        return i 
    else: 
        return -1
  
a  = [1, 2, 4, 4, 8] 
x = int(4) 
res = BinarySearch(a, x) 
if res == -1: 
    print(x, "is absent") 
else: 
    print("First occurrence of", x, "is present at", res) 