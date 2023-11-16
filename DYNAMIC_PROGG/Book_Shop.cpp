#include <bits/stdc++.h>
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
#define vpi vector<pair<int, int>>
#define pb push_back
#define pi pair<int, int>
#define ff first
#define ss second
#define fo(i, s, e) for (int i = s; i <= e; i++)
#define rfo(i, e, s) for (int i = e; i >= s; i--)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
void _print(int t)
{
    cerr << t;
}
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T, class V>
void _print(multimap<T, V> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(multimap<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

#define yes cout << "YES" << endl
#define no cout << "NO" << endl

// binary search ? dp ? change observation..
// edge cases ? overflow ? limits ?

// int dp[100005];
// int f(int mxMoney, vi &C, vi &P, int n, set<int> &st)
// {   
//     if(mxMoney == 0) return 0;

//     int ans = 0;
//     for(int i=0; i<n; i++){
//         if(mxMoney - C[i] >= 0){
//             if(st.count(i) > 0) continue;
//             else {
//                 st.insert(i);
//                 ans = max(ans, f(mxMoney - C[i], C, P, n, st ) + P[i]) ;
//                 st.erase(i);
//             }
//         }
//     }
//     return ans;
// }

void solve()
{
    int n, price;
    cin >> n >> price;
    vector<int> C(n), P(n);
    for (int i = 0; i < n; i++)
    {
        cin >> C[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
    }

    // memset(dp, -1, sizeof dp);
    // cout << f( price, C, P, n, st);
    
    vector<int> curdp(price+1, 0), prevdp(price+1, 0);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=price; j++){
            curdp[j] = prevdp[j] ;
            if( j - C[i-1] >= 0 ) {
                curdp[j] = max(curdp[j], prevdp[j - C[i-1]] + P[i-1]) ;
            }
        }
        prevdp = curdp;
    }
    cout << curdp[price];
}

int32_t main()
{
    fast
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}