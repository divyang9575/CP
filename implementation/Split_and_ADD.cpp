#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define db(x)          \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define db(x)
#endif
void _print(int t)
{
    cerr << t;
}
void _print(long long int t) { cerr << t; }
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
    _print(p.first);
    cerr << ",";
    _print(p.second);
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

template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define yes cout << "YES" << endl
#define no cout << "NO" << endl
// #define M 1000000007
#define PI 3.1415926535897932384626433832795
#define cntbits(x) __builtin_popcount(x)
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) a.begin(), a.end()
#define precise(i) cout << fixed << setprecision(i)
#define take(a, n)              \
    for (int j = 0; j < n; j++) \
    cin >> a[j]
#define give(a, n)              \
    for (int j = 0; j < n; j++) \
        cout << a[j] << ' ';    \
    cout << endl;
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

// binary search ? dp ? change observation..
// edge cases ? overflow ? limits ?




const int inv2 = 500000004;
const int inv4 = 250000002;
const int M = 1e9 + 7;

int addself(int a, int b)
{
    a = a + b;
    if (a > M)
        a %= M;
    return a;
}


int f(int ind, int l , int r, int total, int seglen, int n) 
{
    if(ind == r) return total ;

    int sum1 = (total * inv2) % M - ((n % M) * inv4) % M + M;
    sum1 %= M;
    int sum2 = (total * inv2) % M + ((n % M) * inv4) % M + M;
    sum2 %= M;

    int ans = 0 ;

    int l1 = l, r1 = l + seglen - 1;
    int l2 = r1 + 1, r2 = r;
    
    if(ind <= r1){
        ans = addself(ans, f(ind, l1, r1, sum1, seglen/2, n)) ;
    }
    else if(ind > r1)
    {
        ans = addself(ans, (sum1 + f(ind, l2, r2, sum2, seglen/2, n)) % M ) ;
    }

    return ans%M ;
}


void solve()
{
    int N, L, R;
    cin >> N >> L >> R;

    int total = N % M;
    total = total * ((N + 1) % M);
    total %= M;
    total = (total * inv2) % M;

    int ans ;
    if(L == 1)
        ans = f(R, 1, N, total, N / 2, N) ;
    else
        ans = (f(R, 1, N, total, N / 2, N) - f(L-1, 1, N, total, N/2, N) + M ) % M ;


    cout << ans << endl;

    
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}