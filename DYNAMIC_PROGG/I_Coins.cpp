#include<bits/stdc++.h>
using namespace std;

#define nl '\n'
#define int long long int
#define vi vector<int>
#define take(a,n) for(int j=1;j<=n;j++) cin>>a[j]
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

const int N = 3001;
double dp[N][N]; // coins and heads

void solve()
{
    int n; cin >> n;
    vector<double> phead(n+1);
    fo(i,1,n) cin >> phead[i];

    dp[1][1] = phead[1];
    dp[1][0] = (1-phead[1]);

    fo(heads, 0 , n){   // coins 0
        dp[0][heads] = 0;
    }

    fo(i,1,n){ // n coins
        fo(j,0,n){ // n heads
            if(j > i) { // heads cannot be greater than coins
                continue;
            }
            // tails
            dp[i][j] += (1-phead[i]) * dp[i-1][j];
            //heads 
            if(j > 0) 
                dp[i][j] += phead[i] * dp[i-1][j-1];
        }
    }
    cout << fixed << setprecision(10);
    
    double ans = 0;
    fo(heads, n/2 +1, n){
        ans += dp[n][heads];
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