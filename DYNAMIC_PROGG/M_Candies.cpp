#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define cntbits(x) __builtin_popcount(x)
#define nl '\n'
#define sz(a) a.size()
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) a.begin(), a.end()
#define precise(i) cout<<fixed<<setprecision(i)
#define take(a,n) for(int j=0;j<n;j++) cin>>a[j]
#define give(a,n) for(int j=0;j<n;j++) cout<<a[j]<<' '; cout << endl;
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define memset(dp) memset(dp , -1, sizeof(dp))
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

#ifndef ONLINE_JUDGE
#define db(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define db(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define yes cout << "YES" << endl
#define no cout << "NO" << endl

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

const int N = 105;
const int K = 1e5+5;
int maxcandies[N];
int dp[N][K];
int pre[K];
int n, k;

// int func(int ind, int candiesleft )
// {
//     if(candiesleft == 0 && ind == 0){
//         return 1;
//     }
//     if(ind == 0) return 0;

//     if(dp[ind][candiesleft] != -1) return dp[ind][candiesleft];

//     int ans = 0;
//     for(int i = 0; i <= maxcandies[ind] ; i++){
//         if(candiesleft - i >= 0)
//         ans = (ans % M + func(ind-1, candiesleft - i) % M) % M ;
//     }

//     return dp[ind][candiesleft] = ans;
// }

void solve()
{
    cin >> n >> k;
    fo(i,1,n) cin >> maxcandies[i]; 

    // memset(dp);
    
    // int ans = func(n, k);
    // cout << ans << nl;

    fo(i,1,k){
        dp[0][i] = 0;
    }
    fo(i,0,n){
        dp[i][0] = 1;
    }


    fo(i,1,n)
    {
        // calc pre array
        pre[0] = dp[i-1][0];
        fo(x, 1, k){
            pre[x] = (pre[x-1] + dp[i-1][x]) % M;
        }
        fo(j,1,k)
        {
            // give candies
            int mx = maxcandies[i];
            if(j - mx - 1 >= 0)
            dp[i][j] = ( (pre[j] + M) - pre[j - mx - 1]) % M;
            else
            dp[i][j] = pre[j] ;
        }
    }

    cout << dp[n][k] << nl;
}

int32_t main()
{fast
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}