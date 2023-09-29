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

int nc2(int n){
    if(n <= 1) return 0;
    return (n * (n-1)) / 2;
}

void solve()
{
    int n; cin >> n;
    vpi arr(n); 
    map<int , int> mp0; // (x , (_) + x) -> count
    map<int , int> mpI; // (x , (_) + x) -> count
    map<int , int> mp1; // (x , (_) + x) -> count
    map<int , int> mp1d; // (x , (_) + x) -> count
    for(int i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second ;
    }
    sort(all(arr));
    
    for(int i=0; i<n; i++){
        int x = arr[i].first, y = arr[i].second ;

        // slope = 0
        mp0[y]++;

        // slope = 1/0
        mpI[x]++;

        //slope = 1
        mp1[y-x]++;

        //slope = -1
        mp1d[y+x]++;
    }

    int ans = 0;
    for(auto e : mp0){
        int N = e.second;
        ans += nc2(N) * 2 ;
    }
    for(auto e : mpI){
        int N = e.second;
        ans += nc2(N) * 2 ;
    }
    for(auto e : mp1){
        int N = e.second;
        ans += nc2(N) * 2 ;
    }
    for(auto e : mp1d){
        int N = e.second;
        ans += nc2(N) * 2 ;
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
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}