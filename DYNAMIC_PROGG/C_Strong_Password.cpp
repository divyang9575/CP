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


// void solve()
// {
//     string s; cin >> s;
//     int m; cin >> m;
//     string l , r; cin >> l >> r;
//     int n = sz(s);
//     debug(s) debug(l) debug(r)
//     int start = 0;
//     fo(i,0,m-1) 
//     {
//         int lo = l[i]-'0', hi = r[i]-'0';
//         debug(lo) debug(hi)
//         int mxind = INT_MIN;

//         fo(j,lo,hi)
//         {
//             fo(k,start,n-1)
//             {
//                 if( int32_t(s[k]-'0') == j)
//                 {
//                     mxind = max(mxind, k);
//                     break;
//                 }
//                 if(k == n-1 && (s[k]-'0' != j))
//                 {
//                     yes; 
//                     return;
//                 }
//             }
//         }
//         debug(mxind)
//         if(mxind == n-1 && i != m-1){
//             yes; return;
//         }

//         start = mxind + 1;
//     }

//     no;
    
// }


//DP solution....///
int dp[12][100005][12]; //ind , m , lo-hi
string s, l, r;
int m;


void solve()
{
    cin >> s ; 
    cin >> m;
    cin >> l >> r;



    fo(i,0, m)
    {
        int lo = l[i]-'0', hi = r[i]-'0';
        fo(j, 0 , sz(s))
        {
            fo(k,0,9)
            {
                if(i == 0){
                    dp[i][j][k] = 0;
                    continue;
                }
                if(j == 0){
                    dp[i][j][k] = 1;
                    continue;
                }

                if(k < lo || k > hi) {
                    dp[i][j][k] = -1;
                    continue;
                }

                dp[i][j][k] = dp[i][j-1][k] & (k != s[j-1]);
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
    while(t--){
        solve();
    }
    return 0;
}

