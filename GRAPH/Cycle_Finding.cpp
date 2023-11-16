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
const int N = 5005;
const int INF = 1e17;
int n, m;
vvi edges;
vi dist;
vi vis;
vi par;
vi cycle;
void printCycle(int x){
    for(int v = x ; ; v = par[v]){
        cycle.push_back(v);
        if(v == x && cycle.size() > 1) break;
    }
    reverse(all(cycle));
    give(cycle, (int)cycle.size());
}

void bellmanFORD(int st)
{
    dist[st] = 0;
    for(int i=0; i<n-1; i++){
        for(auto e : edges){
            int u = e[0], v = e[1], wt = e[2];
            if(dist[u] == INF) continue;
            if(dist[u] + wt < dist[v]){
                par[v] = u;
                dist[v] = dist[u] + wt;
            }
            dist[v] = max(dist[v], -1*INF); // correction
        }
    }

    int x = -1;
    for(auto e : edges){
        int u = e[0], v = e[1], wt = e[2];
        if(dist[u] == INF) continue;
        if(dist[u] + wt < dist[v]){
            par[v] = u;
            x = v;
        }
    }
    
    if(x == -1) no;
    else{
        for(int i=1;i<=n; i++){
            x = par[x];
        }
        // the vertex x is surely inside the cycle now
        yes;
        printCycle(x);
    }
}

void solve()
{
    cin >> n >> m;
    edges.resize(m);
    dist.resize(n+1, 0); // initial distance is from an arbitrary node A' oxilary node more precisely
    par.resize(n+1);
    vis.resize(n+1);

    for(int i=0; i<m; i++){
        int u, v, wt; cin >> u >> v >> wt;
        edges[i] = {u, v, wt} ;
    }

    bellmanFORD(1);

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