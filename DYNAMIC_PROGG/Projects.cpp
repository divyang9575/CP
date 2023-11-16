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
#define endl '\n'
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

void modsum(int &a, int b) { a = (a%M + b%M + M )%M ;}
void modmul(int &a, int b) { a = (a%M * b%M )%M ;}
void ckmn(int &a, int b){ if(b < a) a = b; }
void ckmx(int &a, int b){ if(b > a) a = b; }

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

struct project {
    int start , end, reward;
};

bool cmp(project a, project b){
    return a.end <= b.end;
}

void solve()
{
    int n; cin >> n;
    vector<project> v(n+1);
    v[0].start = 0, v[0].end = 0, v[0].reward = 0;
    for(int i=1; i<=n; i++) cin >> v[i].start >> v[i].end >> v[i].reward;

    sort(all(v), cmp);
    vi ends(n+1, 0);
    for(int i=1; i<=n; i++) ends[i] = v[i].end;

    vi dp(n+1, 0); // dp[i] -> max reward ending at i'th project
    dp[0] = 0;

    // SOLUTION ONE , MAX SUBSEQUENCE ENDING AT I
    vi pref(n+1, 0); // prefix max of dp
    for(int i=1; i<=n; i++){
        int st = v[i].start ;
        int ind = lower_bound(all(ends), st) - ends.begin() ;
        ind--; // won't go out of bound 
        dp[i] = v[i].reward + pref[ind];

        pref[i] = max(pref[i-1], dp[i]);
    }
    // cout << *max_element(all(pref));

    // SOLUTION 2 : MAX SUBSEQUENCE TILL I (not necessarily ending at i)
    for(int i=1; i<=n; i++){
        int notake = dp[i-1];
        int take = v[i].reward;
        int j = lower_bound(all(ends), v[i].start) - ends.begin();
        j--;
        take += dp[j];
        dp[i] = max(notake, take);
    }
    cout << dp[n];
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