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

vvi vis(1005, vi(1005, 0));
char g[1005][1005];
char p[1005][1005];
int n, m;
pi st;
pi endd;

bool valid(int i, int j, int n, int m) {return !(i < 0 || j < 0 || i >= n | j >= m);}

string ans = "";
void tracepath(int i, int j)
{
    while(true){
        ans += p[i][j] ;
        if(p[i][j] == 'L') j++;
        else if(p[i][j] == 'R') j--;
        else if(p[i][j] == 'U') i++;
        else if(p[i][j] == 'D') i--;

        if(i == st.first && j == st.second) break;
    }
}

bool bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});

    while(!q.empty()){
        pi par = q.front();
        q.pop();
        int a = par.first, b = par.second;
        if(g[a][b] == 'B'){
			tracepath(a, b);
			return true;
		}
        if(vis[a][b]) continue;
        vis[par.first][par.second] = 1;
        int x1 = par.first + 1, y1 = par.second ;
        int x2 = par.first - 1, y2 = par.second ;
        int x3 = par.first , y3 = par.second + 1;
        int x4 = par.first , y4 = par.second - 1;

        if(valid(x1, y1, n, m) && !vis[x1][y1] && (g[x1][y1] == '.' || g[x1][y1] == 'B')){
            q.push({x1, y1});
            p[x1][y1] = 'D';
        }
        if(valid(x2, y2, n, m) && !vis[x2][y2] && (g[x2][y2] == '.' || g[x2][y2] == 'B')){
            q.push({x2, y2});
            p[x2][y2] = 'U';
        }
        if(valid(x3, y3, n, m) && !vis[x3][y3] && (g[x3][y3] == '.' || g[x3][y3] == 'B')){
            q.push({x3, y3});
            p[x3][y3] = 'R';
        }
        if(valid(x4, y4, n, m) && !vis[x4][y4] && (g[x4][y4] == '.' || g[x4][y4] == 'B')){
            q.push({x4, y4});
            p[x4][y4] = 'L';
        }
    }
    return false;
}


void solve()
{
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            cin >> g[i][j];
            if(g[i][j] == 'A') st = {i, j} ;
            if(g[i][j] == 'B') endd = {i, j} ;
        }
    }
    
    if(bfs(st.first, st.second)){
        yes;
        cout << ans.size() << endl;
        reverse(all(ans));
        cout << ans << endl;
    }
    else cout << "NO\n";
    
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