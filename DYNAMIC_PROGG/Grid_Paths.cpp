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

// int dp[1005][1005];
// vector<vi> grid(1005, vi(1005));

// int f(int vert, int hori)
// {
//     if(vert == 1 && hori == 1) return 1;
//     if(vert == 0 || hori == 0) return 0;
//     if(dp[vert][hori] != -1) return dp[vert][hori];

//     int paths = 0;
//     if(grid[vert][hori-1] == 1) paths += (f(vert, hori-1))%M;
//     if(grid[vert-1][hori] == 1) paths += (f(vert-1, hori))%M;
//     paths %= M;

//     return dp[vert][hori] = paths;
// }

    
// void solve()
// {
//     int n; cin >> n;

//     // fo(i,0,n-1){
//     //     string s; cin >> s;
//     //     fo(j,0,n-1){
//     //         if(s[j] == '.') grid[i+1][j+1] = 1;
//     //         else grid[i+1][j+1] = 0;
//     //     }
//     // }
//     // if(grid[n][n] == 0) cout << 0;
//     // else
//     // {
//     //     memset(dp);
//     //     cout << f(n, n);
//     // }

//     vector<string> grid(n);
//     fo(i,0,n-1){
//         cin >> grid[i];
//     }
//     debug(grid)
//     int dp[n+1][n+1] ;
//     fo(i,0,n) {
//         fo(j,0,n) dp[i][j] = 0;
//     }
//     if(grid[0][0] == '.') dp[1][1] = 1;
    
//     fo(i,1,n){
//         fo(j, 1, n){
//             // debug(i) debug(j) debug(dp[i][j]) 
//             if(i == 1 && j == 1) continue;
//             if(grid[i-1][j-1] == '.' ){
//                 dp[i][j] = (dp[i-1][j] + dp[i][j-1]) %M;
//                 debug(dp[i-1][j]) debug(dp[i][j-1])
//             }
//             // debug(dp[i][j])
//         }
//     }
//     cout << dp[n][n];
    
// }

void modsum(int &a, int b) { a += b; if(a >= M) a %= M;}
void modmul(int &a, int b) { a *= b; if(a >= M) a %= M;}

void solve(){
    int n; cin >> n;
    vector<string> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<vi> dp(n+1, vi(n+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == 1 && j == 1){
                if(arr[i-1][j-1] != '*') dp[i][j] = 1;
            }
            else{
                if(arr[i-1][j-1] != '*'){
                    modsum(dp[i][j] , dp[i-1][j]);
                    modsum(dp[i][j] , dp[i][j-1]);
                }
            }
        }
    }
    cout << dp[n][n] << endl;
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