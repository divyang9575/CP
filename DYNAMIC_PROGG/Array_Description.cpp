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

// int dp[100005][105];
// int f(int i, int prev, vi& arr, int n, int m){
//     if(dp[i][prev] != -1) return dp[i][prev];
//     if(i == n) return 1;
//     if(arr[i] != 0){
//         if(i > 0 && abs(prev-arr[i]) > 1) return 0; 
//         else return f(i+1, arr[i], arr, n, m);
//     }

//     int ans = 0;
//     for(int j = -1; j <= 1; j++){
//         if(prev+j > 0 && prev+j <= m){
//             modsum(ans, f(i+1, prev+j, arr, n, m));
//         }
//     }
//     return dp[i][prev] = ans;
// }


void solve()
{
    int n, m; cin >> n >> m;
    vi arr(n); 
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    db(arr)
    
    // memset(dp, -1, sizeof dp);
    // int ans = 0;
    // if(arr[0] == 0){
    //     for(int i=1; i<=m; i++)
    //         modsum(ans,  f(1, i, arr, n, m ));
    // }
    // else{
    //     ans = f(1, arr[0], arr, n, m);
    // }
    // cout << ans << endl;


    vector<vector<int>> dp(n, vi(m+1, 0));
    if(arr[0] != 0)
        dp[0][arr[0]] = 1;
    else{
        for(int i=1; i<=m; i++) dp[0][i] = 1;
    }


    for(int i=1; i<n; i++){
        if(arr[i] == 0){  // j can be anything
            for(int j=1; j<=m; j++){
                for(int p=-1; p<=1; p++){
                    if(j + p > 0 && j + p <= m)
                    modsum(dp[i][j] , dp[i-1][j+p]);
                }
            }
        }
        else{ // j is fixed to arr[i]
            for(int p=-1; p<=1; p++) {
                if(arr[i] + p > 0 && arr[i] + p <= m) {
                    modsum(dp[i][arr[i]], dp[i-1][arr[i] + p]);
                }
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=m; i++){
        modsum(ans , dp[n-1][i]);
    }
    cout << ans << endl;
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