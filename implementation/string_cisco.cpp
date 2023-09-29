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

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 
 
// map<string, int> mp;
// int f(string s){
//     int n = s.size();
//     if(n == 0) return 0;
//     if(mp.find(s) != mp.end()) return mp[s];

//     int ans = 1e9;
//     for(int i=0; i<n; i++){
//         int j=i+1, cnt = 1;
//         while( j < n && s[j] == s[i] ){
//             cnt++; j++;
//         }
//         string temp = s.substr(0, i) + s.substr(j, string::npos);

//         ans = min(ans, 1 + f(temp));
//     }
//     return mp[s] = ans;
// }

string s;
const int N = 505;
int dp[N][N];

int func(int i, int j){
    if(i > j) return 0;
    if(i == j) return 1;
    if(dp[i][j] != -1) return dp[i][j];

    // deleted left char alone
    int ans = 1 + func(i+1, j); 

    //pair the left char with some other similar on the right
    for(int k = i+1; k<=j; k++){
        if(s[i] == s[k]){
            ans = min(ans, func(i+1, k) + func(k+1, j));
        }
    }
    return dp[i][j] = ans;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    int n ; cin >> n;
    cin >> s;
    int ans = func(0, n-1);
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