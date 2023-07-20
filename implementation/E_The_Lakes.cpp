#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define cntbits(x) __builtin_popcount(x)
#define nl '\n'
#define sz(a) a.size()
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) a.begin(), a.end()
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define memset(dp) memset(dp , -1, sizeof(dp))
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define yes cout << "YES" << endl
#define no cout << "NO" << endl

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

bool visited[1005][1005];
vvi a(1003, vi(1003));
int n, m;
int volume = 0;
int dfs(int i, int j)
{
    visited[i][j] = true;
    int ans = a[i][j];
    if(i!=0) {
        if( a[i-1][j] != 0 && !visited[i-1][j]){
            ans += dfs(i-1, j);
        }
    }
    if(i != n-1){
        if( a[i+1][j] != 0 && !visited[i+1][j]){
            ans += dfs(i+1, j);
        }
    }
    if(j != 0){
        if( a[i][j-1] != 0 && !visited[i][j-1]){
            ans += dfs(i, j-1);
        }
    }
    if(j != m-1){
        if( a[i][j+1] != 0 && !visited[i][j+1]){
            ans += dfs(i, j+1);
        }
    }
    return ans;
}

void JaiShreeKrishna()
{
    int volume = 0;
    cin >> n >> m;
    fo(i,0,n-1){
        fo(j,0,m-1){
            cin >> a[i][j];
            visited[i][j] = false;
        }
    }

    fo(i,0,n-1){
        fo(j,0,m-1){
            if( !visited[i][j] && a[i][j] != 0)
            volume = max(volume, dfs(i, j));
        }
    }
    cout << volume<< nl;
    
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
        JaiShreeKrishna();
    }
    return 0;
}