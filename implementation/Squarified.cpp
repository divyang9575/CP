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

const int N = 1e7 + 5;
vector<int> primes;
int isprime[N];
int spf[N];
void sieve(){
    spf[1] = 1;
    for(int i=2; i<N; i++){
        if(isprime[i] == 0){
            primes.push_back(i);
            spf[i] = i;
            for(int j = i*i;j<N;j+=i){
                isprime[j] = 1; 
                spf[j] = i;
            }
        }
    }
    return;
}



const int INF = 1e17;

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = -INF;
    map<int, int> subs;
    for (int i = 0; i < n; i++)
    {
        int num = 1 ;
        while(arr[i] != 1){
            int div = spf[arr[i]] ;
            int cnt = 0;

            while(arr[i] % div == 0){
                arr[i] /= div ;
                cnt++;
            }
            if(cnt & 1){
                num *= div ;
            }
        }
        if(num != 1) {
            subs[num]++;
            ans = max(ans, subs[num]) ;
        }
    }

    if (ans == -INF)
        cout << "0\n";
    else
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

    sieve();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}