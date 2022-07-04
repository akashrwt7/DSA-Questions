// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

void f(vector<int>& nums, int i, int j, vector<int>& ans)
{
    if(i>j) return;
    int mid = (i+j)/2;
    ans.push_back(nums[mid]);
    f(nums,i,mid-1,ans);
    f(nums,mid+1, j, ans);
}

    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        int n  = nums.size();
        vector<int> ans;
        f(nums,0,n-1,ans);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends