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


void solve()
{
    int n, m; cin >> n >> m;
    vi arr(n); 
    map<int, int> cnt;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    vi vis(m+1, 0);
    vi mxx(m+1, 0);
    vi brr(n+1, -1);
    brr[0] = arr[0];
    vis[arr[0]] = 1;
    mxx[arr[0]] = 1;
    int mxcnt = 1;
    map<int, int> cur;
    cur[arr[0]]++;
    // set<int> mx = {arr[0]};

    for(int j=1; j<n; j++){
        int num = arr[j];

        if(mxx[num]){
            for(int i=1; i<=m; i++){
                if(!vis[i]){
                    vis[i] = 1;
                    brr[j] = i;
                    cur[i]++;
                    if(mxcnt == cur[i]){
                        mxx[i] = 1;
                    }
                    // db(j) db(mxcnt)
                    break;
                }
            }
            if(brr[j] == -1){
                for(int i=1; i<=m; i++){
                    if(mxx[i] == 0){
                        brr[j] = i;
                        cur[i]++;
                        if(cur[i] == mxcnt){
                            mxx[i] = 1;
                        }
                        break;
                    }
                }
            }
            if(brr[j] == -1){
                brr[j] = arr[j];
                cur[arr[j]]++;
                db(j) db(cur[arr[j]]) db(mxcnt)
                if(cur[arr[j]] > mxcnt){
                    mxcnt = cur[arr[j]];
                    mxx.assign(m+1 , 0);
                    mxx[arr[j]] = 1;
                }
            }
        }
        else{
            brr[j] = arr[j];
            cur[arr[j]]++;
            if(!vis[arr[j]]) vis[arr[j]] = 1;
            db(j) db(arr[j]) db(cur[arr[j]]) db(mxx[arr[j]])
            if(mxcnt == cur[arr[j]]) mxx[arr[j]] = 1;
            db(mxx[arr[j]])
        }
    }
    give(brr, n);
    
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