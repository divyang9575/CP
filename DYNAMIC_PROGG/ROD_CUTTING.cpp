//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int dp[1005];

    int func(int curLength, int price[], int n) // 1 based indexing
    {
        //base case
        if(curLength == 0) return 0;
        
        if(dp[curLength] != -1) return dp[curLength];

        int ans = 0;

        for(int cut_length = 1; cut_length <= n; cut_length++)
        {
            if(curLength - cut_length >= 0)
            ans = max(ans, price[cut_length-1] + func( curLength - cut_length, price, n));
        }
        return dp[curLength] = ans;
    }

    int cutRod(int price[], int n) {
        memset(dp, -1, sizeof(dp));
        //code here
        return func(n, price, n);

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends