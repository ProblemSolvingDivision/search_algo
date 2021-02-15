#include<bits/stdc++.h> 
using namespace std;
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = (l+r)/2;
        
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
        
        // IF x greater, ignore left half
        if(arr[m] < x)
            l = m + 1;
        
        // If x is smaller, ignore right half
        else
            r = m -1;
            
    }
    
    // if we reach here, then element
    // is not present
    return -1;
}

//Recursive Implementation of Binary search
int binarySearch_rec(int arr[], int l, int r, int x)
{
    if (r >=l) {
        int mid = (r + l)/2;
        
        // Checks if the element is in the middle
        if (arr[mid] == x)
            return mid;
        
        //Checks if element is smaller than the element at mid
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch_rec(arr, l, mid - 1, x);
        
        // Else the element can only be present in the right subarray
        return binarySearch_rec(arr, mid + 1, r, x);
    }
    
    // We reach here when element is not present in the sorted array 
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 8, 11, 20};
    int n = 6; // size of arr;
    
    int x = 8;
    int pos  = -1;
    
    // Linear Search
    for (int i = 0; i < n; i++){
        if(arr[i] == x){
            pos = i;
            break;
        }
    }
    
    if(pos == -1) cout << "x is not found "<<endl;
    else cout<<"the position of x is : " << pos << endl;
    
    //Binary Search
    pos = binarySearch(arr, 0, n-1, x);
    
    if(pos==-1) cout <<"x is not found " <<endl;
    else cout <<"the position of x is : " <<pos << endl;
    
    // STL predefined function
    
    vector<int>vec = {1, 3, 4, 8, 11, 20};
    n = vec.size(); // size of vec
    
    int val1 = 8;
    bool exist1 = binary_search(vec.begin(), vec.end(), val1);
    
    int val2 = 5;
    bool exist2= binary_search(vec.begin(), vec.end(), val2);
    
    cout<<val1<<" is "<<(exist1 ? "found": "not found")<<endl;
    cout<<val2<<" is "<<(exist2 ? "found": "not found")<<endl;
    return 0;
}