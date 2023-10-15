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
// #define int long long int
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

class SGTree {
    public:
        vector<int> seg, lazy;
        SGTree(int sz){
            seg.resize(4 * sz + 1);
            lazy.resize(4 * sz + 1);
        }

        // Complete function to combine childs
        int combine(int a, int b) ;

        void build(int i, int lo, int hi, vector<int> &arr){
            if(lo == hi) {
                seg[i] = arr[lo];
                return;
            }
            int mid = (lo + hi) / 2 ;
            build(2*i+1, lo, mid, arr);
            build(2*i+2, mid+1, hi, arr);

            // complete the tree here
            seg[i] = combine(seg[2*i+1] , seg[2*i+2]); // sum
        }


        void lazyUpdates(int i, int lo, int hi, int l, int r, int val, vector<int> &arr) {
            if(lazy[i] != 0) {
                seg[i] += (hi - lo + 1) * lazy[i];
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
                lazy[i] = 0;
            }

            // low high l r or l r low high
            if(r < lo || l > hi) return;

            // l low high r
            if(lo >= l && hi <= r){
                seg[i] += (hi - lo + 1) * val;
                if(lo != hi){
                    lazy[2*i+1] += val;
                    lazy[2*i+2] += val;
                }
                return;
            }

            int mid = (lo + hi) / 2; 
            lazyUpdates(2*i+1, lo, mid, l, r, val, arr);
            lazyUpdates(2*i+2, mid+1, hi, l, r, val, arr);
            seg[i] = combine(seg[2*i+1] , seg[2*i+2]);

        }

        void pointUpdate(int i, int lo, int hi, int idx, int val, vector<int> &arr){
            if(lo == hi){
                arr[idx] += val;
                seg[i] += val;
                return;
            }

            int mid = (lo + hi) / 2 ;
            if(idx <= mid) pointUpdate(2*i+1, lo, mid, idx, val, arr);
            else pointUpdate(2*i+2, mid+1, hi, idx, val, arr);
            seg[i] = combine(seg[2*i+1] , seg[2*i+2]);
        }

        int query(int i, int lo, int hi, int l, int r, vector<int> &arr){
            if(lazy[i] != 0){
                seg[i] += (hi - lo + 1) * lazy[i];
                if(lo != hi){
                    lazy[2*i+1] = lazy[i];
                    lazy[2*i+2] = lazy[i];
                }
                lazy[i] = 0;
            }

            // l low high r
            if(lo >= l && hi <= r){
                return seg[i];
            }

            // l r lo hi or lo hi l r
            if(r < lo || l > hi) return 0; // changes can be made

            int mid = (lo + hi) / 2 ;
            int left = query(2*i+1, lo, mid, l, r, arr) ;
            int right = query(2*i+2, mid+1, hi, l, r, arr) ;
            return combine(left, right) ;
        }
};

// const int N = 100005;
// int seg[4 * N], arr[N];
// int n, q;



void solve()
{
    int n, q; vi arr(n);
    cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    SGTree sgt(n);

    sgt.build(0, 0, n-1, arr);
    
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, r; cin >> l >> r;
            l--, r-- ;
            cout << sgt.query(0, 0, n-1, l, r, arr) << endl;
        }
        else{
            // int i, val; cin >> i >> val;
            // i--;
            int l, r, val; cin >> l >> r >> val;
            l--, r--;
            sgt.lazyUpdates(0, 0, n-1, l, r, val, arr);
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

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}