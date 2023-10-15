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

void build(int i, int lo, int hi, vi &arr, vi &seg, vi &lazy)
{
    lazy[i] = 0;
    if (lo == hi)
    {
        seg[i] = arr[lo];
        return;
    }

    int mid = (lo + hi) / 2;
    build(2 * i + 1, lo, mid, arr, seg, lazy);
    build(2 * i + 2, mid + 1, hi, arr, seg, lazy);
    // no combine here
}

void update(int i, int lo, int hi, int l, int r, int val, vi &seg, vi &lazy)
{
    if (lazy[i] != 0)
    {
        seg[i] = (seg[i] + lazy[i]) % 26;
        if(lo != hi){
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
        }
        lazy[i] = 0;
    }

    // l r lo hi or lo hi l r
    if (lo > r || hi < l)
        return;

    // l lo  hi r
    if (lo >= l && hi <= r)
    {
        seg[i] = (seg[i] + val) % 26;
        if(lo != hi){
            lazy[2 * i + 1] += val;
            lazy[2 * i + 2] += val;
        }
        return;
    }

    int mid = (lo + hi) / 2;
    update(2 * i + 1, lo, mid, l, r, val, seg, lazy);
    update(2 * i + 2, mid + 1, hi, l, r, val, seg, lazy);
}

int query(int i, int lo, int hi, int l, int r, vi &seg, vi &lazy)
{
    if (lazy[i] != 0)
    {
        seg[i] = (seg[i] + lazy[i]) % 26;
        if(lo != hi){
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
        }
        lazy[i] = 0;
    }

    // l r lo hi or lo hi l r
    if (lo > r || hi < l)
        return 0;

    // l lo  hi r
    if (lo >= l && hi <= r)
        return seg[i];

    int mid = (lo + hi) / 2;
    int left = query(2 * i + 1, lo, mid, l, r, seg, lazy);
    int right = query(2 * i + 2, mid + 1, hi, l, r, seg, lazy);
    return left + right;
}

void setTwoUpdate(int Lp1, int L, int ind, set<int> &two, vi &arr)
{
    auto it = two.find(ind);
    if (it != two.end())
    { // found palindrome
        if (Lp1 != L)
            two.erase(it);
    }
    else
    { // not found
        if (Lp1 == L)
            two.insert(ind);
    }
}

void setThreeUpdate(int Lp, int L1, int ind, set<int> &three, vi &arr)
{
    auto it = three.find(ind);
    if (it != three.end())
    { // found palindrome
        if (Lp != L1)
            three.erase(it);
    }
    else
    { // not found
        if ( Lp ==  L1)
            three.insert(ind);
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        arr[i] = c - 'a';
    }

    set<int> two, three;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n && arr[i] == arr[i + 1]) two.insert(i);

        if (i + 2 < n && arr[i] == arr[i + 2]) three.insert(i);
    }

    vector<int> seg(4 * n + 1), lazy(4 * n + 1);
    build(0, 0, n - 1, arr, seg, lazy);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--;

            update(0, 0, n - 1, l, r, x, seg, lazy);

            // left side
            int L1 = -1, L = -1, Lp1 = -1, Lp2 = -1; // L previous 1, 2

            if (l + 1 < n){
                L1 = query(0, 0, n - 1, l + 1, l + 1, seg, lazy);
            }

            L = query(0, 0, n - 1, l, l, seg, lazy);

            if (l - 1 >= 0 ){
                Lp1 = query(0, 0, n - 1, l - 1, l - 1, seg, lazy);
            }
            if (l - 2 >= 0){
                Lp2 = query(0, 0, n - 1, l - 2, l - 2, seg, lazy);
            }

            if (l - 1 >= 0){
                setTwoUpdate(Lp1, L, l - 1, two, arr);
            }
            if (l - 1 >= 0 && l + 1 < n){
                setThreeUpdate(Lp1, L1, l - 1, three, arr);
            }
            if (l - 2 >= 0){
                setThreeUpdate(Lp2, L, l - 2, three, arr) ;
            }

            // right side
            int Rp1 = -1, R = -1, R1 = -1, R2 = -1;
            if (r - 1 >= 0){
                Rp1 = query(0, 0, n - 1, r - 1, r - 1, seg, lazy);
            }

            R = query(0, 0, n - 1, r, r, seg, lazy);

            if (r + 1 < n){
                R1 = query(0, 0, n - 1, r + 1, r + 1, seg, lazy);
            }
            if (r + 2 < n){
                R2 = query(0, 0, n - 1, r + 2, r + 2, seg, lazy);
            }

            if (r + 1 < n){
                setTwoUpdate(R, R1, r, two, arr);
            }
            if (r + 1 < n && r - 1 >= 0){
                setThreeUpdate(Rp1, R1, r - 1, three, arr);
            }
            if (r + 2 < n){
                setThreeUpdate(R, R2, r, three, arr);
            }
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--, r--;

            auto tw = two.lower_bound(l);
            auto th = three.lower_bound(l);

            if (tw != two.end())
            {
                if(*tw < r){
                    no; continue;
                }
            }
            if (th != three.end() )
            {
                if(*th <= r-2){
                    no; continue;
                }
            }
            yes;
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