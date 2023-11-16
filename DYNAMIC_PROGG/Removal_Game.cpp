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
#define endl '\n'
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
void ckmn(int &a, int b){ if(b < a) a = b; }
void ckmx(int &a, int b){ if(b > a) a = b; }

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

const int N = 5005;
int n;
vi arr;
int dp[N][N][2];

int f(int i, int j, int p){
    if(i == j){
        if(p == 0) return arr[i];
        else return 0;
    }
    if(dp[i][j][p] != -1) return dp[i][j][p];

    if(p == 0){
        int front = arr[i] + f(i+1, j, 1);
        int back = arr[j] + f(i, j-1, 1);
        return dp[i][j][p] = max(front, back);
    }
    else {
        return dp[i][j][p] = min(f(i+1, j, 0), f(i, j-1, 0));
    }
}

void solve()
{
    cin >> n ;
    arr.resize(n); 
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    // memset(dp, -1, sizeof dp);
    // cout << f(0, n-1, 0);

    int dp[n][n][2]; // score of the first player when : 
                        // 1. a subarray of i to j. 2. player p's turn it is
    for(int i=0; i<n; i++) dp[i][i][0] = arr[i], dp[i][i][1] = 0;

    for(int i=n-2; i>=0; i--) {
        for(int j=i+1; j<n; j++) {
            dp[i][j][0] = max( arr[i] + dp[i+1][j][1], arr[j] + dp[i][j-1][1]) ;
            dp[i][j][1] = min( dp[i+1][j][0] , dp[i][j-1][0] ) ; // minimize the score of player first
        }
    }
    cout << dp[0][n-1][0];
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