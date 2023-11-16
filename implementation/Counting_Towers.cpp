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

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

const int N = 1000005;
int dp[1000005][2]; // -> we are ith index and 
                //(p == 0 means two 1*1 block, p == 1 means one 2*1 block)
int n;
int f(int i, int p)
{
    if(i == n-1) return 1; // close whatever we have
    if(dp[i][p] != -1) return dp[i][p];

    int ans = 0;
    if(p == 1) // previous was 2*1 block
    { 
         // either close it and start another similar block , f(1)
            //or don't close it , f(1)
        modsum(ans, 2*f(i+1, 1));

        // close it and start two 1*1 blocks, f(0)
        modsum(ans, f(i+1, 0)); 
    }

    else if(p == 0) // previous was two 1*1 blocks
    {   
        // case1 : close it 
            // 1 : start two 1*1 blocks , f(0)
            // 2 : start one 2*1 block , f(1)
        // case 2 : close one of the two
            // start one 1*1 block -> 2 ways , 2*f(0)
        // case 3 : don't close it
            // continue 1*1 blocks , f(0)

        modsum(ans, 4*f(i+1, 0)); 
        modsum(ans, f(i+1, 1));
        
    }
    return dp[i][p] = ans;
}

void solve()
{
    // cin >> n;
    // memset(dp, -1, sizeof dp);
    // int ans = f(0, 0);
    // modsum(ans, f(0, 1));
    // cout << ans << endl;

    dp[0][0] = dp[0][1] = 1;
    for(int i=1; i<N; i++){
        for(auto p : {0, 1}){
            if(p == 0){
                modsum(dp[i][p] , dp[i-1][1]);
                modsum(dp[i][p], 4*dp[i-1][0]);
            }
            else{
                modsum(dp[i][p], 2*dp[i-1][1]);
                modsum(dp[i][p], dp[i-1][0]);
            }
        }
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
    cin >> t;
    solve();
    while(t--){
        cin >> n;
        int ans = dp[n-1][0];
        modsum(ans, dp[n-1][1]);
        cout << ans << endl;
    }
    return 0;
}
