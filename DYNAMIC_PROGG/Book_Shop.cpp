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
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
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
// int dp[1005][100005];
// int f(int ind, int mxMoney, vi&price, vi&pages)
// {
//     if(mxMoney == 0 || ind == 0) return 0;
//     if(dp[ind][mxMoney] != -1) return dp[ind][mxMoney];
//     int page = f(ind-1, mxMoney, price, pages);

//     if(mxMoney - price[ind-1] >= 0)
//     page = max(page, pages[ind-1] + f(ind-1, mxMoney - price[ind-1], price, pages));

//     return dp[ind][mxMoney] = page;
// }
int dp[1005][100005], price[1005], pages[1005];
int n, x;
void solve()
{
    cin >> n >> x;
    fo(i,0,n-1) cin >> price[i];
    fo(i,0,n-1) cin >> pages[i];
    // memset(dp);
    // cout << f(n, x, price, pages);

    int dp[n+1][x+1];
    fo(i,0,n){
        fo(j,0,x){
             dp[i][j] = 0;
        }
    }

    fo(ind, 1, n){
        fo(money, 1, x){
            dp[ind][money] = dp[ind-1][money];
            if(money - price[ind-1] >= 0)
                dp[ind][money] = max(dp[ind][money], pages[ind-1] + dp[ind-1][money - price[ind-1]]);
        }
    }
    cout << dp[n][x];
    
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