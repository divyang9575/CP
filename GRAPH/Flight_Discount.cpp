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
const int N = 1e5 + 5;
const int INF = 1e17;
int n, m; 
vpi adj[N] ;
vvi dist(N, vi(2, INF)); // 0 means coupon is used and 1 means we can use the coupon
vvi vis(N, vi(2, 0));

void dijkstra(int st)
{   
    pqg<vi> pq;
    pq.push({0, st, 1}) ;
    dist[st][0] = dist[st][1] = 0;

    while(!pq.empty()){
        int parnode = pq.top()[1] ;
        int pardist = pq.top()[0] ;
        int coupon = pq.top()[2] ;
        pq.pop();
        if(vis[parnode][coupon]) continue;
        vis[parnode][coupon] = 1;

        for(auto ch : adj[parnode])
        {
            int child = ch.first, wt = ch.second ;
            
            // not using the coupon
            if(dist[parnode][coupon] + wt < dist[child][coupon]){
                dist[child][coupon] = dist[parnode][coupon] + wt;
                pq.push({dist[child][coupon], child, coupon});
            }
            
            // can still use the coupon
            if(coupon == 1){ 
                if(dist[parnode][1] + wt/2 < dist[child][0]){
                    dist[child][0] = dist[parnode][1] + wt/2  ;
                    pq.push({dist[child][0], child, 0});
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    dist.assign(n+1, {INF, INF});
    while(m--){
        int  u, v, wt; cin >> u >> v >> wt ;
        adj[u].push_back({v, wt});
    }
    
    dijkstra(1);
    cout << dist[n][0] ;
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