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
    int n, k, a, b; cin >> n >> k >> a >> b;

    vpi city(n); 
    pi st, end ;
    for(int i=0; i<n; i++){
        cin >> city[i].first >> city[i].second ;
        if(i == a-1) st = {city[i].first,  city[i].second};
        if(i == b-1) end = {city[i].first,  city[i].second};
    }

    int mn1 = 5e11, mn2 = 5e11 , ind1 = -1, ind2 = -1;
    for(int i=0; i<k; i++){
        if( abs(city[i].first - st.first) + abs(city[i].second - st.second) < mn1){
            mn1 = abs(city[i].first - st.first) + abs(city[i].second - st.second);
            ind1 = i;
        }
        if( abs(city[i].first - end.first) + abs(city[i].second - end.second) < mn2){
            mn2 = abs(city[i].first - end.first) + abs(city[i].second - end.second);
            ind2 = i;
        }
    }

    // if(a <= k) mn1 = 0;
    // if(b <= k ) mn2 = 0;

    // direct distance
    int dist = abs(city[a-1].first - city[b-1].first) + abs(city[a-1].second - city[b-1].second);
    if(k <= 1){
        cout << min(dist, mn1+mn2) << endl;
    }
    else{
        cout << min(dist, mn1 + mn2) << endl;
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