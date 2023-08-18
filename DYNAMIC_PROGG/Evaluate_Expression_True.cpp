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

int dp[1005][1005][2];

int func(int i, int j, string &s, bool need)
{
    if(i > j) return 0;
    if(i == j){
        if(need == true) return s[i] == 'T'; // true chahiye
        else return s[i] == 'F';   // false chahiye
    }

    if(dp[i][j][need] != -1) return dp[i][j][need];

    int ans = 0;
    for(int k = i+1; k < j; k += 2)
    {
        int LT = func(i, k-1, s, true);
        int RT = func(k+1, j, s, true);
        int LF = func(i, k-1, s, false);
        int RF = func(k+1, j, s, false);

        if(s[k] == '|'){
            if(need == true){
                ans += LT * RT + LF * RT + LT * RF ;
            }
            else {
                ans += LF * RF;
            }
        }
        else if(s[k] == '&'){
            if(need == true){
                ans += LT * RT;
            }
            else{
                ans += LF * RF + LF * RT + LT * RF ;
            }
        }
        else if (s[k] == '^'){
            if(need == true){
                ans += LT * RF + RT * LF ;
            }
            else{
                ans += LF * RF + LT * RT ;
            }
        }
        ans %= M;
    }
    return dp[i][j][need] = ans;
}

void solve()
{
    string s; cin >> s;
    int n = s.size();

    memset(dp);

    int ans = func(0, n-1, s, true);
    cout << ans << nl;
    
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