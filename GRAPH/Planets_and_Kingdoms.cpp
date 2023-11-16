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


class SCC{
    public:
    int N;
    vvi g, gr; vi vis;
    stack<int> st;
    vi comps;

    SCC(int nn){
        N = nn;
        g.resize(N), gr.resize(N), vis = vi(N, 0), comps = vi(N, -1) ;
    }

    void add(int u, int v) { g[u].push_back(v), gr[v].push_back(u); }

    void dfs(int i){
        vis[i] = 1;
        for(int j : g[i]){
            if(!vis[j]) dfs(j);
        }
        st.push(i);
    }

    void sccdfs(int i, int c){
        comps[i] = c ;
        for(int j : gr[i]) {
            if(comps[j] == -1) sccdfs(j, c) ;
        }
    }
};


void solve()
{
    int n, m; cin >> n >> m;
    SCC g(n) ;
    while(m--){
        int u, v; cin >> u >> v;
        u--, v--;
        g.add(u, v);
    }

    for(int i=0; i<n; i++){
        if(!g.vis[i]){
            g.dfs(i);
        }
    }
    g.vis.assign(n, 0);
    int scc = 1;
    while(!g.st.empty()) {
        int i = g.st.top(); g.st.pop();
        if(g.comps[i] == -1){
            g.sccdfs(i, scc);
            scc++;
        }
    }
    cout << scc-1 << endl;
    give(g.comps, n);
    
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