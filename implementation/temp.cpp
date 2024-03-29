// Pragmas

// header files
#include <bits/stdc++.h>

// namespace
using namespace std;
using namespace chrono;


// Constants
#define PI 3.1415926535
#define INF 4e18
#define EPS 1e-9
#define MOD 1000000007

// Aliases
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;

// macros
#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define ppc __builtin_popcount
#define parity(x) __builtin_parity(x) // gives true for odd and false for even
#define ppcll __builtin_popcountll
#define msb(x) 63 - __builtin_clzll(x) // gives the most significant bit of the number
#define sz(x) (int)x.size()
#define F first
#define acc accumulate
#define S second
#define amax(a, b) a = max(a, b)
#define amin(a, b) a = min(a, b)
#define getunique(v)                                  \
    {                                                 \
        sort(v.begin(), v.end());                     \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }
#define kickstart(x)                 \
    {                                \
        cout << "Case #" << x << ":" \
             << " ";                 \
    }
#define hi cout << "hi" << endl

// Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}

template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}

template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

/* ----------------------------------Things get better by time, hope for the best-----------------*/
void solve(int testcase)
{
    // kickstart(testcase);
    // debug(testcase);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    if (k == 4)
    {
        int cnt = 0;
        int ans = k;
        for (auto it : a)
        {
            if (it % 4 == 0)
            {
                cout << 0 << endl;
                return;
            }
            if (it % 2 == 0)
            {
                cnt++;
            }
            int rem = k - (it % k);
            amin(ans, rem);
        }
        cout << min(max(2 - cnt, 0ll), ans) << endl;
        return;
    }
    auto f = [&](int x) -> int
    {
        int ans = x;
        for (auto it : a)
        {
            if (it % k == 0)
            {
                ans = 0;
                break;
            }
            int rem = k - (it % x);
            amin(ans, rem);
        }
        return ans;
    };
    cout << f(k) << endl;
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int n = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;
    return 0;
}
