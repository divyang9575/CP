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
template <class T> void _print(queue <T> q);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(queue <T> q) {cerr << "[ "; while(!q.empty()) {_print(q.front()), q.pop(); cerr << " ";} cerr << "]";}

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

const int N = 1e5+5;
int n, m ;
vvi adj(N);
const int INF = 1e18;
int dist[N];
int vis[N];
int  par[N];
int indeg[N];
queue<int> q;

void topo(){
    while(!q.empty()){
        int parent = q.front();
        q.pop();

        for(int child : adj[parent]){
            if(dist[parent] + 1 > dist[child]){
                par[child] = parent;
                dist[child] = dist[parent] + 1;
            }
            indeg[child]--;
            if(indeg[child] == 0) {
                q.push(child);
            }
        }
    }
}

 
void solve()
{
    cin >> n >> m;
    for(int i=0; i<=n; i++){
        dist[i] = indeg[i] = vis[i] = 0;
    }
    while(m--){
        int u, v, wt = -1;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    // topological sorting using kahn's algorithm
    for(int i=2; i<=n; i++){
        if(indeg[i] == 0) {
            q.push(i);
        }
    }
    db(q)
    // removes all nodes other than 1
    while(!q.empty()){
        int parent = q.front();
        q.pop();

        for(int child : adj[parent]){
            if(child == 1) continue;
            db(child)
            indeg[child]--;
            if(indeg[child] == 0) {
                q.push(child);
            }
        }
    }

    q.push(1) ;
    topo();

    if(dist[n] == 0 ){
        cout << "IMPOSSIBLE\n";
        return;
    }

    vi ans = {n};
    int node = par[n];
    while(node != 1){
        ans.push_back(node);
        node = par[node];
    }
    ans.push_back(1);
    reverse(all(ans));
    cout << ans.size() << endl;
    give(ans, (int)ans.size());


    
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