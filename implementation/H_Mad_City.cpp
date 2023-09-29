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

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

/* Find both marcel and valeru's location from the cycles */

const int INF = 1e18 ;
const int N = 3e5 + 5;
vi adj[N];
vi cycle(N);
vi vis(N);
bool cyc = false;
set<int> ans;

void cycDFS(int node, set<int> st, int p = -1)
{
    for(auto child : adj[node])
    {
        if(child == p) continue;
        if(st.count(child) > 0)
        {
            ans = st; return;
        }
        else
        {
            st.insert(child);
            cycDFS(child, st, node);
            st.erase(child);
        }
    }

}


void dfs(int node, int par = -1){
    vis[node] = 1;
    for(auto child : adj[node]){
        if(vis[child] && child != par){
            cyc = true ;
            set<int> st = {child} ;
            cycDFS(child, st, node);
            return;
        }
        else if(!vis[child]){
            dfs(child, node);
        }
    }
}

vi dist(N, INF);

void dijkstra(int start)
{
    set<pair<int, int>> st;
    st.insert({0, start});
    vis[start] = 1;
    dist[start] = 0;

    while(!st.empty())
    {
        int parnode = st.begin()->second;
        st.erase(st.begin());
        vis[parnode] = 1;

        for(int child : adj[parnode]){
            if(vis[child]) continue;
            if(dist[parnode] + 1 < dist[child]){
                dist[child] = dist[parnode] + 1;
                st.insert({dist[child], child}) ;
            }
        }
    }
}

void solve()
{
    int n, a, b; cin >> n >> a >> b;

    for(int i=0; i<=n; i++){
        adj[i].clear() ;
    }

    for(int i=0; i<n; i++){
        int u, v; cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(a == b){
        no; 
        db("same node\n") 
        return;
    }

    // check for cycle
    cyc = false;
    vis.assign(n+1, 0); 
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i, -1);
        }
    }

    if(cyc == false){
        no ; 
        db("Cycle false\n") 
        return ;
    }

    db(ans)
    if(ans.count(b) > 0){ // valeru is on the cycle
        yes; 
        db("valeru on cycle") 
        return ;
    }

    // now both are not on the cycle 
    //so calculate the shortest distance of both from the cycle

    vis.assign(n+1, 0) ;
    dist.assign(n+1, INF);
    dijkstra(b);
    int mnB = INF, Bnode = -1 ;
    for(auto it : ans){
        if(dist[it] < mnB){
            mnB = dist[it];
            Bnode = it ;
        } 
    }

    dist.assign(n+1, INF);
    vis.assign(n+1, 0) ;
    dijkstra(a);
    int mnA = dist[Bnode];

    if(mnB < mnA){
        yes; 
        db("main yes\n") 
    }
    no ;

}

int32_t main()
{fast
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}