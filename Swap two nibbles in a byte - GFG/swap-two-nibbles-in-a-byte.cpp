// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int swapNibbles(unsigned char x){
        // code here
        int left = x & 15;
        int right = x& 240;
        left = left<<4;
        right = right>>4;
        return left|right;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.swapNibbles(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends