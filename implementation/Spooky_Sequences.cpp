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

void modsum(int &a, int b) { a = (a%M + b%M + M )%M ;}
void modmul(int &a, int b) { a = (a%M * b%M )%M ;}

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

const int N = 3e5 + 5;
const int mod = 1e9 + 7 ;
int fact[N];

void factorial(){
    fact[0] = 1 ;
    for(int i=1; i<N; i++){
        fact[i] = (fact[i-1] *1LL* i) % mod ;
    }
}
int inv[N];
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void inverse(){    // fermat's little theorum
    for(int i=1; i<N; i++){
        inv[i] = binpow(i, mod-2, mod);
    }
}

int n, m;
vi S(N);
vvi adj(N);
vi vis(N);
vi cur;

void dfs(int i){
    cur.push_back(S[i]);
    vis[i] = 1;
    for(auto j : adj[i]){
        if(!vis[j])
            dfs(j);
    }
}

void solve()
{
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        adj[i].clear();
        vis[i] = 0;
    }
    
    while(m--){
        int u, v; cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for(int i=1; i<=n; i++) cin >> S[i];

    int ans = fact[n];
    for(int i = 1; i<=n; i++){
        if(!vis[i]) {
            db(i)
            cur.clear();
            dfs(i);

            int cnt = cur.size();
            modmul(ans, binpow(fact[cnt], mod-2, mod));
            map<int, int> mp;
            for(auto it : cur){
                mp[it]++;
            }
            for(auto it : mp){
                int f = it.second;
                if(f > 1)
                modmul(ans, fact[f]);
            }
        }
    }
    cout << ans << endl;
    
}

int32_t main()
{fast
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif
    factorial();
    inverse();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}