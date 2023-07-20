#include<bits/stdc++.h>
using namespace std;

#define nl '\n'
#define int long long int
#define vi vector<int>
#define take(a,n) for(int j=1;j<=n;j++) cin>>a[j]
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

const int N = 1e5+5;
int dp[105][N];  // ind , maxval

void solve()
{
    int n, W; cin >> n >> W;
    vi wt(n+1), val(n+1);
    fo(i,1,n){
        cin >> wt[i] >> val[i];
    }

    // initialization
    fo(i,0,n){
        fo(j,0,N){
            dp[i][j] = 2e9;
        }
    }

    fo(i,0,n)
        dp[i][0] = 0;

    // dp[0][val[1]] = wt[1];
    dp[1][val[1]] = wt[1];

    fo(i,2,n){
        fo(j,1,N){
            dp[i][j] = dp[i-1][j];

            if(j - val[i] >= 0)
            dp[i][j] = min(dp[i][j] , dp[i-1][j - val[i]] + wt[i]);
        }
    }

    int ans = -1;
    rfo(value, N, 0){
        if(dp[n][value] <= W){
            ans = max(ans, value);
        }
    }
    
    cout << ans << nl;
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

// #define endl '\n'
// #define int long long int
// #define fo(i,s,e) for(int i=s; i<=e; i++)
// #define rfo(i,e,s) for(int i=e; i>=s; i--)
// #define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

// int dp[105][100005];
// int n, w;
// int wt[105]; int val[1005];

// int func(int ind, int curval) // returns minimum weight for a particular value
// {
//     if(curval == 0 ) return 0;
//     if(ind < 1) return 1e15;    // hypothetical wieght for the "min" condition

//     if(dp[ind][curval] != -1) return dp[ind][curval];

//     int ans = func(ind - 1, curval);

//     if(curval - val[ind] >= 0)
//         ans = min(ans, wt[ind] + func(ind - 1, curval - val[ind]));

//     return dp[ind][curval] = ans;
// }

// void solve()
// {
//     cin >> n >> w;
//     fo(i,1,n) cin >> wt[i] >> val[i];

//     memset(dp, -1, sizeof(dp));

//     for(int i = 100005; i >= 0; i--)
//     {
//         if(func(n, i) <= w)
//         {
//             cout << i;
//             break;
//         }
//     }
// }

// int32_t main()
// {fast
//     solve();
//     return 0;
// }