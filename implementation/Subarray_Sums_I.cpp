#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define nl '\n'
#define sz(a) a.size()
#define int long long int
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
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
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

/// prefix sum.............////////////////////////////
//  WORKS FOR NEGATIVE NUMBERS ALSO//////////////////////
void solve()
{
    int n, sum; cin >> n >> sum;
    vi a(n); fo(i,0,n-1) cin >> a[i];
    
    vi pre(n+1); pre[0] = 0;
    fo(i,1,n)
    {
        pre[i] = pre[i-1] + a[i-1];
    }
    debug(a)
    debug(pre)
    int cnt = 0;

    map<int, int> st;
    fo(i,0,n)
    {
        if(st.find( pre[i] - sum ) != st.end())
        {
            debug(pre[i] - sum)
            cnt += st[pre[i] - sum];
        }
        st[pre[i]]++;
        debug(st)
        debug(cnt)
    }
    
    cout << cnt;
}

// sliding window..........//////////////////////////
// ONLY FOR POSITIVE NUMBERS
// void solve()
// {
//     int n, sum; cin >> n >> sum;
//     vi a(n); fo(i,0,n-1) cin >> a[i];
    
//     int i = 0, j = 0;
//     int cursum = 0;
//     int cnt = 0;
//     while(i < n && j < n)
//     {
//         cursum += a[j];
//         while(cursum >= sum)
//         {
//             if(cursum == sum) cnt++;

//             cursum -= a[i++];
//         }
//         j++;
//     }
    
//     cout << cnt;
// }

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