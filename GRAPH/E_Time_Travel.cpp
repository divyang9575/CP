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

const int N = 2e5+5;
int n, t, k;
vpi adj[N];
vi arr(N);
const int INF = 1e18;
vector<int> dist(N, INF);
vector<vector<int>> pos(N);
vector<int> vis(N, 0);
void dijkstra(int st)
{   
    pqg<pi> pq;
    pq.push({0, st}) ;
    dist[st] = 0;

    while(!pq.empty()) {
        int parnode = pq.top().second ;
        int pardist = pq.top().first ;
        pq.pop() ;
        if(vis[parnode]) continue ;
        vis[parnode] = 1 ;
        for(auto ch : adj[parnode]){
            int child = ch.first, moment = ch.second ;
            auto it = upper_bound(all(pos[moment]), pardist) ;
            if(it != pos[moment].end()){
                if(dist[child] > *it){
                    dist[child] =  *it ;
                    pq.push({dist[child], child}) ;
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> t;
    for(int i=0; i<t; i++){
        int m; cin >> m;
        while(m--){
            int u, v; cin >> u >> v;
            u--, v--;
            adj[u].emplace_back(v, i);
            adj[v].emplace_back(u, i);
        }
    }
    cin >> k;
    for(int i=1; i<=k; i++) {  // 1 based
        cin >> arr[i];
        arr[i]--;
        pos[arr[i]].push_back(i);
    }

    dijkstra(0);
    cout << (dist[n-1] == INF ? -1 : dist[n-1]);
    
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