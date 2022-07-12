// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int convertEvenBitToZero(long long int n) {
        // code here
        
        for(int i=0; i<32; i= i+2)
        {
            int t = n & (1<<i);
            if(t)
                n = n & ~t;
        }
        return n;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.convertEvenBitToZero(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends