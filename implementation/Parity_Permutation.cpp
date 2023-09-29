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

const int mod = 1e9 + 7 ;
const int N = 2e5 + 5;
int fact[N];


void factorial(){
    fact[0] = 1 ;
    for(int i=1; i<N; i++){
        fact[i] = (fact[i-1] *1LL* i) % mod ;
    }
}


void solve()
{
    int n, k; cin >> n >> k;
    vi arr(n); 
    int od = 0, ev = 0 ;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i] & 1) od++;
        else ev++;
    }

    if(k == 0){
        if(od > 0 && ev > 0){
            cout << 0 << endl;
            return ;
        }
        
        cout << fact[n]<< endl;
        return ;
    }

    if(k == 1){
        int mn = min(od, ev) ;
        if((n & 1) && (mn == n/2)){
            cout << (fact[od] *1LL* fact[ev]) %mod << endl;
        }
        else if(n % 2 == 0 && (od == n/2 && ev == n/2)){
            cout << (2*fact[od] *1LL* fact[ev]) %mod << endl;
        }
        else{
            cout << 0 << endl;
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
    factorial();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}