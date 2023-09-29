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

bool possible(int R, vi &arr, int prebits[][32] , int n, int L, int K){
    int val = 0;
    for(int i=0; i<32; i++){
        if(prebits[R][i] - prebits[L-1][i] == R - L + 1 ){
            val += (1 << i) ;
        }
    }
    return val >= K ;
}

void solve()
{
    int n; cin >> n;
    vi arr(n); 
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int prebits[n+1][32] ;
    memset(prebits, 0, sizeof prebits) ;

    for(int i=0; i<n; i++){
        for(int j=0; j<32; j++){
            if(arr[i] & (1<<j)){
                prebits[i+1][j] += 1;
            }
            prebits[i+1][j] += prebits[i][j];
        }
    }

    int q; cin >> q;
    vi answer ;
    while(q--){
        int L, K ; cin>> L >> K;

        int lo = L, hi = n, mid, ans = -1 ;
        while(lo <= hi)
        {
            mid = hi - (hi - lo) / 2 ;
            if(possible(mid, arr, prebits, n, L, K)){
                lo = mid + 1;
                ans = mid;
            }
            else{
                hi = mid - 1;
            }
        }
        answer.push_back(ans) ;
    }
    give(answer, answer.size()) ;
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