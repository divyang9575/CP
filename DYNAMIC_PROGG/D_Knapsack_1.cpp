#include<bits/stdc++.h>
using namespace std;

#define nl '\n'
#define int long long int
#define vi vector<int>
#define take(a,n) for(int j=1;j<=n;j++) cin>>a[j]
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

const int N = 2e5;
int dp[105][N];

void solve()
{
    int n, W; cin >> n >> W;
    vi wt(n+1), val(n+1);
    fo(i,1,n){
        cin >> wt[i] >> val[i];
    }

    // initialization
    fo(i,0,n)
        dp[i][0] = 0;
    fo(i,0,W)
        dp[0][i] = 0;

    fo(i, 1, n){
        fo(j,1,W){
            dp[i][j] = dp[i-1][j];

            if(j >= wt[i])
                dp[i][j] = max(dp[i][j], val[i] + dp[i-1][j - wt[i]]);
        }
    }

    cout << dp[n][W] << nl;
}

int32_t main()
{fast
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}



// #include<bits/stdc++.h>
// using namespace std;

// #define mod 1000000007
// #define PI 3.1415926535897932384626433832795
// #define endl '\n'
// #define int long long int
// #define vi vector<int>
// #define sort(a,all) sort(a.begin(), a.end())
// #define vpi vector<pair<int,int>>
// #define pb push_back
// #define pi pair<int,int>
// #define ff first
// #define ss second
// #define fo(i,s,e) for(int i=s; i<=e; i++)
// #define rfo(i,e,s) for(int i=e; i>=s; i--)
// #define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

// int dp[102][100010];

// int func(int ind, int w, int * wt, int * val, int n)
// {
//     if(ind == n || w == 0) return 0;

//     if(dp[ind][w] != -1) return dp[ind][w];

//     if(w - wt[ind] < 0)
//     {
//         return dp[ind][w] = func(ind + 1, w, wt, val, n);
//     }
        
//     return dp[ind][w] = max( val[ind] + func(ind + 1, w - wt[ind], wt, val, n) , func(ind+1, w, wt, val, n));
    
// }

// void solve()
// {
//     memset(dp, -1, sizeof(dp));
//     int n, w; cin >> n >> w;
//     int wt[n], val[n]; fo(i,0,n-1) cin >> wt[i] >> val[i];

//     cout << func(0, w, wt, val, n);
// }

// int32_t main()
// {fast
//     solve();
//     return 0;
// }