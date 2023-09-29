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


void solve()
{
    int n, k; cin >> n >> k ; db(n) db(k)
    string s; cin >> s; db(s)
    vi l(k), r(k) ; 
    for(int i=0; i<k; i++){
        cin >> l[i]  ;
    }
    for(int i=0; i<k; i++){
        cin >> r[i]  ;
    }
    db(l) db(r)
    
    vi swaps(n+1) ;
    for(int i=0; i<k; i++){
        for(int L = l[i]; L<=(r[i]) ; L++){
            swaps[L] = (l[i]+r[i]) - L ;
        }
    }
    db(swaps)

    int q; cin >> q;
    vi pref(n+2, 0);
    while(q--)
    {
        int x; cin >> x ;
        // int ind = lower_bound(all(r), x) - r.begin();
        int L = min(x, swaps[x]), R = max(x, swaps[x]) ;
        pref[L] += 1, pref[R+1] -= 1;
    }

    vi vis(n+1, false) ;
    for(int i=1; i<=n; i++){
        pref[i] += pref[i-1] ;
        if((pref[i] & 1) && vis[i] == 0 ){
            db(vis[i])
            db(s[i-1]) db(s[swaps[i]-1])
            swap(s[i-1], s[swaps[i]-1]) ;
            vis[i] = 1, vis[swaps[i]] = 1;

            
            // db(s[i-1]) db(s[swaps[i]-1])
        }
    }
    db(pref)
    db(s)
    cout << s << endl;

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