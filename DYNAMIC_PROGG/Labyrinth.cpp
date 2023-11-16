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

void modsum(int &a, int b) { a += b; if(a >= M) a %= M;}
void modmul(int &a, int b) { a *= b; if(a >= M) a %= M;}

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

vi ans ;
bool f = false;
vvi vis(1005, vi(1005, 0));
vector<vi> moves = {{0, 1, 1}, {0, -1, 2}, {1, 0, 3}, {-1, 0, 4}}; // up down right left

bool valid(int i, int j, int n, int m) {return !(i < 0 || j < 0 || i >= n | j >= m);}

void dfs(int i, int j, vector<vector<char>> &g, int n , int m, vi &str){
    if(g[i][j] == 'B' && ans.empty()){
        ans = str;
        f = true;
        return;
    }
    if(f) return;
    vis[i][j] = 1;
    for(auto mv : moves){
        int x = i + mv[0], y = j + mv[1];
        if(valid(x, y, n, m) && !vis[x][y] && (g[x][y] == '.' || g[x][y] == 'B')){
            str.push_back(mv[2]);
            dfs(x, y, g, n, m, str);
            str.pop_back();
        }
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    pi st, end;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            cin >> g[i][j];
            if(g[i][j] == 'A') st = {i, j};
            if(g[i][j] == 'B') end = {i, j};
        }
    }
    vi str;
    dfs(st.first, st.second, g, n, m, str);
    db(st) db(ans)
    string aa ;
    if(!f) no;
    else {
        yes;
        cout << ans.size() << endl;
        for(auto &i : ans){
            if(i == 1) aa += 'U';
            else if(i == 2) aa += 'D';
            else if(i == 3) aa += 'R';
            else aa += 'L';
        }
        cout << aa << endl;
    }
    
    
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