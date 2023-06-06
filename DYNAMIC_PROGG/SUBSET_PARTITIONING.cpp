#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define sort(a,all) sort(a.begin(), a.end())
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

int dp[205][20005];

bool func(int sum,int ind, vector<int>& a)
{
    if(sum == 0) return 1;
    if(ind < 0) return 0;

    if(dp[ind][sum] != -1) return dp[ind][sum];

    int ans = func(sum, ind-1, a);

    if(sum - a[ind] >= 0)
        ans = ans | func(sum - a[ind], ind-1, a);

    return dp[ind][sum] = ans;
}

bool canPartition(vector<int>& nums) 
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    
    if(sum & 1) return false;

    else{
        return func(sum/2, nums.size()-1, nums);
    }
         
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    vi a(n); fo(i,0,n-1) cin >> a[i];

    cout << canPartition(a); 
}

int32_t main()
{fast
    solve();
    return 0;
}