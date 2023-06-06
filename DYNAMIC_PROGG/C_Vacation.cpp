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

const int N = 1e5 + 10;
int dp[3][N];

int func(int index, int row, vector<vi> &abc)
{
    if(row >= abc.size()) return 0;

    if(dp[index][row] != -1) return dp[index][row];

    if(index == 0)
    {
        return dp[index][row] = max(abc[row][1] + func(1,row+1 ,abc), abc[row][2] + func(2,row+1 ,abc) ); 
    }
    if(index == 1)
    {
        return dp[index][row] = max(abc[row][0] + func(0,row+1 ,abc), abc[row][2] + func(2,row+1 ,abc) ); 
    }
    if(index == 2)
    {
        return dp[index][row] = max(abc[row][0] + func(0,row+1 ,abc), abc[row][1] + func(1,row+1 ,abc) ); 
    }
}

void solve()
{
    memset(dp, -1, sizeof(dp));

    int n; cin >> n;
    vector<vi> abc;
    fo(i,0,n-1) 
    {
        vi temp(3);
        cin >> temp[0] >> temp[1] >> temp[2];
        abc.pb(temp);
    }
    
    int ans = max(max(abc[0][0] + func(0, 1, abc), abc[0][1] + func(1, 1, abc)), abc[0][2] + func(2, 1, abc));
    
    cout << ans;
    
}

int32_t main()
{fast
    solve();
    return 0;
}