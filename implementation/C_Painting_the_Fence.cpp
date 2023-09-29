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
    int n, q; cin >> n >> q;
    int L[q], R[q];
    vi arr(n+1, 0);
    for(int i=0; i<q; i++) {
        cin >> L[i] >> R[i];
        for(int j=L[i]; j<=R[i]; j++){
            arr[j]++;
        }
    }

    int ans = -1e9;
    for(int i=0; i<q; i++){
        //remove first painter
        for(int j=L[i]; j<=R[i]; j++){
            arr[j]--;
        }

        // sections that are still painted
        int painted = 0;
        for(int j=1; j<=n; j++){
            if(arr[j] > 0) painted++;
        }

        //store one's in another array (which means only covered by a single painter)
        vi preones(n+1, 0);  // the number of such sections a painter will have
        for(int j=1; j<=n; j++){
            preones[j] = preones[j-1] + (arr[j]==1) ;
        }

        //remove another painter 
        int notpainted = 1e9;
        for(int k=0; k<q; k++)
        {
            if(k == i) continue;
            int ones = preones[R[k]] - preones[L[k]-1];
            notpainted = min(notpainted, ones); // min sections that won't be painted
        }

        ans = max(ans, painted - notpainted);

        // restore first painter
        for(int j=L[i]; j<=R[i]; j++){
            arr[j]++;
        }
        
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
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}