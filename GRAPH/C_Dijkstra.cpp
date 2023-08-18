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

#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define cntbits(x) __builtin_popcount(x)
#define nl '\n'
#define sz(a) a.size()
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) a.begin(), a.end()
#define precise(i) cout<<fixed<<setprecision(i)
#define take(a,n) for(int j=0;j<n;j++) cin>>a[j]
#define give(a,n) for(int j=0;j<n;j++) cout<<a[j]<<' '; cout << endl;
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define memset(dp) memset(dp , -1, sizeof(dp))
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
vpi g[N];
vi dist(N, INF);
vi vis(N, 0);

// bool cmp(pi a, pi b){
//     return a.first < b.first;
// } 
int dijkstra(int start, int end)
{
    set<pi> pq;   // min heap 
    dist[start] = 0;
    pq.insert({dist[start], start});  // distance and node so that sorted according to the distance

    while(!pq.empty())
    {
        auto par = *pq.begin();  // node with min distance selected and finalized
        pq.erase(pq.begin());
        int par_node = par.ss;
        if(vis[par_node]) continue;
        vis[par_node] = 1;

        for(auto child : g[par_node]){
            int child_node = child.ff;
            int distance = child.ss;     // distance of child from parent
            if(dist[par_node] + distance < dist[child_node]){
                dist[child_node] = dist[par_node] + distance;
                pq.insert({dist[child_node], child_node});     // push the new distance of the child node
            }
        }
    }

    return dist[end];
}

void solve()
{
    int n, m; cin >> n >> m;
    fo(i,1,m){
        int u, v, wt; cin >> u >> v >> wt;
        if(g[u][0].ss > wt ) g[u][0] = {v, wt};
        if(g[v][0].ss > wt ) g[v][0] = {u, wt};
    }
    cout << dijkstra(1, n) << nl;
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