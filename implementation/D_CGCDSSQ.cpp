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
        vector<vector<int>> ST;
        vector<int> lg;
    public:
        vector<int> arr;
        sparseTable(int nn){
            n = nn;
            arr.resize(n);
            ST.resize(k, vector<int>(n+1));
            lg.resize(n+1);
        }

        int combine(int &a, int &b) {
            return __gcd(a, b);
        }

        // ST[i][j] -> {j, j + 2^i - 1} 
        void sparse(){
            for(int j=0; j<n; j++) ST[0][j] = arr[j];
            for(int i=1; i<k; i++){
                for(int j=0; j + (1<<i) <= n; j++){
                    ST[i][j] = combine(ST[i-1][j], ST[i-1][j + (1<<(i-1))]);
                }
            }
        }

        void calclog(){
            for(int i=1; i<=n; i++){
                lg[i] = log2(i);
            }
        }

        int query(int l, int r){
            int i = lg[r - l + 1];
            return combine(ST[i][l], ST[i][r - (1<<i) + 1]);
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
    db(st.arr)

    map<int, int> mp;

    for(int i=0; i<n; i++){ // for all L's find R's
        int L = i;
        db(L)
        while(L < n){
            int curg = st.query(i, L);
            int l = L;
            int r = n-1;
            int R = -1;
            db(curg)

            while(l <= r){
                int mid = (l+r) / 2;
                db(mid)
                if(st.query(i, mid) == curg){
                    R = mid;
                    l = mid+1;
                }
                else r = mid-1;
                db(l)db(r) db(R)
            }
            db(R)
            mp[curg] += R - L + 1;
            L = R + 1;
        }
    }


    int q; cin >> q;
    db(q)
    while(q--){
        int val; cin >> val;
        db(val)
        cout << mp[val] << endl;
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