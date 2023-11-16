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

void modsum(int &a, int b) { a = (a%M + b%M + M )%M ;}
void modmul(int &a, int b) { a = (a%M * b%M )%M ;}

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

// int f(int i, int prod, vi &arr, int k, int n){
//     if(i == n && prod % k == 0) return 0;
//     if(i == n) return 1e15;
//     int ans = 1e14 ;

//     for(int inc = 0; inc<10; inc++){
//         if(arr[i] + inc <= 10){
//             prod += inc * prod / arr[i];
//             arr[i] += inc;
//             ans = min(ans, inc + f(i+1, prod, arr, k, n));
//             arr[i] -= inc;
//             prod -= inc * prod / arr[i];
//         }
//     }
//     return ans;
// }

void solve()
{
    int n, k; cin >> n >> k;
    vi arr(n); 
    int ans = 1e9;
    int ev = 0, fv = 1e9, th = 1e9, fo = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        ev += (arr[i] % 2 == 0) ;
        fo += (arr[i] % 4 == 0 ) ;
        fv = min(fv, (5 - arr[i]%5)%5) ;
        th = min(th, (3 - arr[i]%3)%3) ;
    }

    if(k == 2){
        if(ev > 0) cout << 0 << endl;
        else cout << 1 << endl;
    }
    else if(k == 4){
        if(ev > 1 || fo > 0) cout << 0 << endl;
        else if(ev == 1) cout << 1 << endl;
        else {
            for(int i=0; i<n; i++){
                if((arr[i] + 1) % 4 == 0){
                    cout << 1 << endl;
                    return;
                }
            }
            cout << 2 << endl;
        }
    }
    else if(k == 5){
        cout << fv << endl;
    }
    else{
        cout << th << endl;
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