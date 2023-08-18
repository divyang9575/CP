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
#define precise(i) cout<<fixed<<setprecision(i)
#define take(a,n) for(int j=0;j<n;j++) cin>>a[j]
#define give(a,n) for(int j=0;j<n;j++) cout<<a[j]<<' '; cout << endl;
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
#define db(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define db(x)
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


void solve()
{
    int n; cin >> n;
    vi a(n); take(a, n);
    
    int cnt = 0;
    int i = 0;

    bool two = false;
    while( i<n ){
        if(a[i] == 0){
            int j = i+1;
            while(j < n){
                if(a[j] == 2) two = true;
                if(a[j] == 0) break;
                j++;
            }
            if(two) i = j + 1;
            else i = j;
            cnt++;
            two = false;
        }
        else if(a[i] == 1 || a[i] == 2){
            int j = i;
            while(j < n){
                if(a[j] == 0) break;
                j++;
            }
            i = j + 1;
            cnt++;
        }
    }
    cout << cnt << nl;
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