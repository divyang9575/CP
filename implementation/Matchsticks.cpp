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

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

 
class sparseTable {
    private:
        int n, k = 20;
        vector<vector<int>> ST1, ST2;
        vector<int> lg;
    public:
        vector<int> arr;
        sparseTable(int nn){
            n = nn;
            arr.resize(n);
            ST1.resize(k, vector<int>(n+1));
            ST2.resize(k, vector<int>(n+1));
            lg.resize(n+1);
        }

        // int combine(int &a, int &b) {
        //     return __gcd(a, b);
        // }

        // ST[i][j] -> {j, j + 2^i - 1} 
        void sparse(){
            for(int j=0; j<n; j++) ST1[0][j] = ST2[0][j] = arr[j];
            for(int i=1; i<k; i++){
                for(int j=0; j + (1<<i) <= n; j++){
                    if(j + (1<<(i-1)) < n){
                    ST1[i][j] = min(ST1[i-1][j], ST1[i-1][j + (1<<(i-1))]);
                    ST2[i][j] = max(ST2[i-1][j], ST2[i-1][j + (1<<(i-1))]);
                    }
                }
            }
        }

        void calclog(){
            for(int i=1; i<=n; i++){
                lg[i] = log2(i);
            }
        }

        pi query(int l, int r){
            int i = lg[r - l + 1];
            int mn = min(ST1[i][l], ST1[i][r - (1<<i) + 1]);
            int mx = max(ST2[i][l], ST2[i][r - (1<<i) + 1]);
            return {mn, mx};
        }

        // int query(int l, int r){
        //     int ans = 0;
        //     for(int i=k-1; i>=0; i--){
        //         if((1<<i) <= r - l + 1){
        //             combine(ans, ST[i][l]);
        //             l += (1<<i);
        //         }
        //     }
        //     return ans;
        // }
};

void solve()
{
    int n; cin >> n;
    sparseTable st(n);
    for(int i=0; i<n; i++){
        cin >> st.arr[i];
    }
    st.sparse();
    st.calclog();

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;

        pi val = st.query(l, r);
        int mn = val.first, mx = val.second ;

        int left = 0;
        if(l-1 >= 0) left = st.query(0, l-1).second ;
        int right = 0;
        if(r+1 < n) right = st.query(r+1, n-1).second ;

        double ans = double(mn) + max({double(mx - mn) / 2, double(left), double(right)});
        precise(1);
        cout << ans << endl;
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
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}