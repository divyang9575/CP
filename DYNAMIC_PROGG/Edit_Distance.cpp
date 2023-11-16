#include<bits/stdc++.h>
using namespace std;


#ifndef ONLINE_JUDGE
#define db(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define db(x)
#endif
void _print(int t) {cerr << t;}
void _print(long long int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define cntbits(x) __builtin_popcount(x)
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) a.begin(), a.end()
#define precise(i) cout<<fixed<<setprecision(i)
#define take(a,n) for(int j=0;j<n;j++) cin>>a[j]
#define give(a,n) for(int j=0;j<n;j++) cout<<a[j]<<' '; cout << endl;
#define vpi vector<pair<int,int>>
#define pi pair<int,int>
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

void modsum(int &a, int b) { a += b; if(a >= M) a %= M;}
void modmul(int &a, int b) { a *= b; if(a >= M) a %= M;}

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 
// const int INF = 1e9;
// int dp[5005][5005];
// int f(int i, int j, string &s, string &t){
//     if(i == 0 && j == 0) return (s[i] != t[j]) ;
//     if(i < 0 ) return j;
//     if(j < 0) return i;
//     if(dp[i][j] != -1) return dp[i][j];

//     int ans = INF;
//     ans = min(ans, f(i-1, j-1, s, t) + (s[i] != t[j]) );
//     ans = min(ans,  f(i-1, j, s, t) + 1);
//     ans = min(ans, f(i, j-1, s, t) + 1);

//     return dp[i][j] = ans;
// }

void solve()
{
    string s, t; cin >> s >> t;
    // memset(dp, -1, sizeof dp);
    // cout << f(s.size()-1, t.size()-1, s, t);
    int n = s.size(), m = t.size();
    vector<vi> dp(n+1, vi(m+1, 0));
    dp[0][0] = 0;
    for(int i=1; i<=n; i++) dp[i][0] = i;
    for(int i=1; i<=m; i++) dp[0][i] = i;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] = min({dp[i-1][j-1] + (s[i-1] != t[j-1]), dp[i-1][j] + 1, dp[i][j-1] + 1});
        }
    }
    cout << dp[n][m] << endl;
    
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