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
#define endl '\n'
#define M 1000000007
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

void modsum(int &a, int b)
{
    a = (a % M + b % M + M) % M;
}
void modmul(int &a, int b) { a = (a % M * b % M) % M; }

// binary search ? dp ? change observation..
// edge cases ? overflow ? limits ?

void solve()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        int s = 0;
        for (auto it : arr[i])
        {
            s += it - '0';
        }
        mp[{s, (int)arr[i].size()}]++;
    }
    db(mp)

    int ans = 0;
    for (int k = 0; k<n; k++)
    {
        string s = arr[k];
        int m = s.size();
        int ind = (m & 1) ? 1 : 2;
        db(s)
        db(ind)

        for(int j = ind; j<m; j+=2){
            // right side string
            int half = (m + j) / 2;
            int sum1 = 0, sum2 = 0;
            for(int i=0; i<m; i++){
                if(i < half) sum1 += s[i]-'0';
                else sum2 += s[i]-'0';
            }
            db(half) db(sum1) db(sum2)

            int req = sum1 - sum2;
            db(req) db(j)
            if(mp.find({req, j}) != mp.end()){
                ans += mp[{req, j}];
            }

            // for left side string 
            int left = m - half;
            sum1 = 0, sum2 = 0;
            for(int i=0; i<m; i++){
                if(i < left) sum1 += s[i] - '0';
                else sum2 += s[i] - '0';
            }
            db(left) db(sum1) db(sum2)
            req = sum2 - sum1;
            db(req) db(j)
            if(mp.find({req, j}) != mp.end()){
                ans += mp[{req, j}];
            }
            db(ans)
        }
    }
    
    for(auto it : mp){
        ans += it.second * it.second;
    }
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}