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
void ckmn(int &a, int b){ if(b < a) a = b; }
void ckmx(int &a, int b){ if(b > a) a = b; }

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 
const int N = 21;
map<int, int> dp[(1<<20)]; 
    // dp[i][curwt] -> i is mask, curwt is weight left in last lift
int n, wt;
int arr[N];

int f(int mask, int curwt) 
{
    if(cntbits(mask) == n) return 0;

    if(dp[mask].find(curwt) != dp[mask].end()) 
        return dp[mask][curwt];

    int ans = 1e17;
    for(int i=0; i<n; i++) {
        if((mask & (1<<i))) continue;

        if(curwt + arr[i] <= wt){
            ans = min(ans, f((mask | (1<<i)), curwt + arr[i] ));
        }
        else{
            ans = min(ans, 1 + f((mask | (1<<i)), arr[i]));
        }
    }
    return dp[mask][curwt] = ans;
}   

void solve()
{
    cin >> n >> wt; 
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int ans = f(0, 0) + 1 ;
    cout << ans ;

    // pair<int, int> lifts[1<<n]; // {lifts required , curwt}
    // lifts[0] = {1, 0}; 
    // for(int mask=1; mask<(1<<n); mask++){
    //     pair<int, int> best = {1e17, 1e17};
    //     for(int i=0; i<n; i++){
    //         if((mask & (1<<i)) == 0) continue;

    //         pair<int, int> ans = lifts[mask ^ (1<<i)] ;
    //         if(ans.second + arr[i] <= wt){
    //             ans.second += arr[i];
    //         }
    //         else{
    //             ans.second = arr[i];
    //             ans.first += 1;
    //         }
    //         best = min(best, ans);
    //     }
    //     lifts[mask] = best;
    // }
    // cout << lifts[(1<<n) - 1].first ;
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