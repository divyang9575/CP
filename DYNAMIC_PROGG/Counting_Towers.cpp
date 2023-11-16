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

// int dp[1000005][9];
void solve()
{
    // set<int> down = {3, 4, 6, 7, 8};
    // set<int> nodown = {1, 2, 5};
    // set<int> top = {3, 5, 6, 7, 8};
    // set<int> notop = {1, 2, 4};
    vector<int> down = {0, 0, 0, 1, 1, 0, 1, 1, 1};
    vector<int> nodown = {0, 1, 1, 0, 0, 1, 0, 0, 0};
    vector<int> top = {0, 0, 0, 1, 0, 1, 1, 1, 1};
    vector<int> notop = {0, 1, 1, 0, 1, 0, 0, 0, 0};
    
    // at top there can only be 2 and 4
    vector<vi> dp(1000005, vi(9, 0));
    dp[0][2] = dp[0][4] = 1;

    for(int i=1; i<1000004; i++){
        for(int j=1; j<=8; j++){
            if(top[j] > 0){
                for(int p = 1; p<=8; p++) // i-1 should have a down
                    if(down[p]) modsum(dp[i][j], dp[i-1][p]);
            }
            else{
                for(int p = 1; p<=8; p++) { // i-1 should not have a down
                    if(nodown[p]) modsum(dp[i][j], dp[i-1][p]);
                }
            }
        }
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = 0;
        // final state we have no restrictions
        for(int i=1; i<=8; i++){
            modsum(ans, dp[n-1][i]);
        }
        cout << ans << endl;
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