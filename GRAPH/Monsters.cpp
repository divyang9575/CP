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

const int N = 1005 ;
vector<vector<char>> g(N, vector<char>(N));
vector<vector<char>> p(N, vector<char>(N));
vvi lava(N, vi(N, 1e9));
vvi vis(N, vi(N));
vector<pair<int, int>> mons;
pi st;
int n, m;
vpi moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool isvalid(int x, int y){
    if(x < 1 || y < 1 || x > n || y > m) return false;
    if(g[x][y] == '#') return false;
    if(lava[x][y] != 1e9) return false;
    return true;
}

queue<vector<int>> q;
void monsbfs()
{
    while(!q.empty())
    {
        int x = q.front()[0], y = q.front()[1];
        q.pop();
        for(auto m : moves){
            int i = x + m.first, j = y + m.second ;
            if(isvalid(i, j)){
                lava[i][j] = lava[x][y] + 1;
                q.push({i, j});
            }
        }
    }
}

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

void updatePath(pi m, int xx, int yy){
    if(m.first == 0 && m.second == 1) p[xx][yy] = 'R';
    if(m.first == 1 && m.second == 0) p[xx][yy] = 'D';
    if(m.first == -1 && m.second == 0) p[xx][yy] = 'U';
    if(m.first == 0 && m.second == -1) p[xx][yy] = 'L';
}

bool step(int x, int y, int time){
    if(x < 1 || y < 1 || x > n || y > m) return false;
    if(g[x][y] == '#') return false;
    if(lava[x][y] > time) return true;
    return false;
}

bool Abfs(int i, int j)
{
    q = queue<vi>();
    q.push({i, j, 0}); 

    while(!q.empty())
    {
        int x = q.front()[0], y = q.front()[1], time = q.front()[2];
        if(x == 1 || y == 1 || x == n || y == m) { // reached
            tracepath(x, y);
            return true;
        }
        q.pop();
        vis[x][y] = 1;
        for(auto m : moves){
            int xx = x + m.first, yy = y + m.second ;
            if(step(xx, yy, time + 1) && !vis[xx][yy]){
                vis[xx][yy] = 1;
                updatePath(m, xx, yy);
                q.push({xx, yy, time + 1});
            }
        }
    }
    return false;
}


void solve()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
    {
        cin >> g[i][j];
        if(g[i][j] == 'A') st = {i, j};
        if(g[i][j] == 'M') {
            q.push({i, j});
            lava[i][j] = 0;
        }
    }
    if(st.first == 1 || st.second == 1 || st.first == n || st.second == m){
        yes;
        cout << "0\n";
        return;
    }

    monsbfs();
    if(Abfs(st.first, st.second)){
        cout << "YES\n";
        cout << (int)ans.size() << endl;
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    else{
        cout << "NO\n";
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