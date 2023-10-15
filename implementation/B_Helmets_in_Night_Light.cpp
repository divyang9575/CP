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

bool cmp(pi a, pi b){
    if(a.first == b.first) return a.second > b.second ;
    return a.first < b.first ;
}
bool cmp2(pair<double, int> a, pair<double, int> b){
    if(a.first == b.first) return a.second > b.second ;
    return a.first < b.first ;
}

int f(int i, int left, vi &people, vi &cost, int n,int p){
    if(left == 0) return 0 ;
    if(i >= n) return 1e11 ;

    int c = 0;
    int notake = f(i+1, left, people, cost, n, p) ;
    int take = p + cost[i] * min(people[i], left) + f(i+1, left - min(people[i], left)-1 , people, cost, n, p) ;
    return min(notake, take) ;

}

void solve(){
    int n, p; cin >> n >> p;
    vi arr(n), brr(n) ;
    for(int i=0; i<n; i++){
        cin >> arr[i] ;
    }
    for(int i=0; i<n; i++){
        cin >> brr[i] ;
    }
    int ans = f(0, n, arr, brr, n, p) ;
    cout << ans << endl;
}

// void solve()
// {
//     int n, p; cin >> n >> p;
//     vpi arr(n); 
//     for(int i=0; i<n; i++){
//         cin >> arr[i].second ;
//     }
//     for(int i=0; i<n; i++){
//         cin >> arr[i].first ;
//     }

//     sort(all(arr), cmp) ;
//     int sum = 0;

//     vector<pair<double, int>> val ;
//     for(int i=0; i<n; i++){
//         double c = (arr[i].first * arr[i].second + p) / (1.0 + arr[i].second) ;
//         val.push_back({c, i }) ;

//     }
//     db(val)
//     sort(all(val), cmp2) ;
//     vector<int> vis(n, 0);
//     int total = 0;
//     for(auto it : val){
//         if(total + arr[it.second].second <= n){
//             total += arr[it.second].second ;
//             vis[it.second] = 1;
//             sum += p + arr[it.second].second * arr[it.second].first ;
//         }
//         else{
//             int left = n - total ;
//             vector<pair<double, int>> val2;
//             for(int i=0; i<n; i++){
//                 if(vis[i] == 0){
//                     double c = (arr[i].first * min(arr[i].second, left) + p) / (1.0 + min(arr[i].second, left));
//                     val2.push_back({c, i});
//                 }
//             }
//             sort(all(val2), cmp2);

//         }
//     }

//     cout << sum << endl;
// }

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