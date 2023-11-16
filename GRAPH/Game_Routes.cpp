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

vvi adj;
int n, m;
const int INF = 1e15;
vi ways;
vi indeg;
queue<int> q;
void topo(){
    while(!q.empty()){
        int par = q.front();
        q.pop();
        for(int child : adj[par]){
            modsum(ways[child], ways[par]) ;
            indeg[child]--;
            if(indeg[child] == 0) q.push(child);
        }
    }
}


// vi dp;
// int dfs(int i, int p){
//     if(i == n) return 1;
//     if(dp[i] != -1) return dp[i];
//     int ans = 0;
//     for(auto j : adj[i]){
//         if(j == p) continue;
//         modsum(ans, dfs(j,  i));
//     }
//     return dp[i] = ans;
// }

void solve()
{
    cin >> n >> m;
    // dp.resize(n+1, -1);
    ways.resize(n+1, 0);
    indeg.resize(n+1);
    adj.resize(n+1);
    while(m--){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    //pruning 
    for(int i=2; i<=n; i++){
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int i = q.front(); q.pop();
        for(int j : adj[i]){
            if(j == 1) continue;
            if(--indeg[j] == 0) q.push(j);
        }
    }

    q.push(1);
    ways[1] = 1;
    topo();
    cout << ways[n];

    // cout << dfs(1,-1) ;
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