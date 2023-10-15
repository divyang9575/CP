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

// binary search ? dp ? change observation..
// edge cases ? overflow ? limits ?

void solve()
{
    int px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;

    precise(12);

    double d1 = (px - ax) * (px - ax) + (py - ay) * (py - ay);
    double d2 = (px - bx) * (px - bx) + (py - by) * (py - by);
    db(d1) db(d2) double D;
    bool one = false, two = false;
    if (d1 < d2)
    {
        D = d1;
        one = true;
    }
    else
    {
        D = d2;
        two = true;
    }
    db(D)

        double o1 = (0 - ax) * (0 - ax) + (0 - ay) * (0 - ay);
    double o2 = (0 - bx) * (0 - bx) + (0 - by) * (0 - by);
    db(o1) db(o2)

        double O;
    if (o1 < o2)
    {
        O = o1;
        one = true;
    }
    else
    {
        O = o2;
        two = true;
    }
    db(O)
        db(one) db(two)

            double dist = (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
    dist = sqrt(dist) / 2;
    db(dist)

        double w = max(sqrt(O), sqrt(D));
    db(w)

        if (one == false)
    {
        cout << w << endl;
    }
    else if (two == false)
    {
        cout << w << endl;
    }
    else
    {
        if (w < dist)
        {
            cout << dist << endl;
        }
        else
        {
            cout << w << endl;
        }
    }
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