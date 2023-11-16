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

const int N = 3e5 + 5;
int arr[N], freq[N], freqOfFreq[N]; // saved tle
// vi arr(N), freq(N), freqOfFreq(N);
struct Q {
    int i, l, r;
};
int block, curmx;

bool cmp(Q a, Q b){
    if(a.l / block == b.l / block) return a.r < b.r ;
    return a.l < b.l;
}

void add(int pos){
    int pre = freq[arr[pos]];
    freqOfFreq[pre]--;

    freq[arr[pos]]++;
    int cur = freq[arr[pos]];
    freqOfFreq[cur]++;

    if(freq[arr[pos]] > curmx) curmx = freq[arr[pos]];
}
void remove(int pos){
    int pre = freq[arr[pos]];
    freqOfFreq[pre]--;

    freq[arr[pos]]--;
    int cur = freq[arr[pos]];
    freqOfFreq[cur]++;

    while(freqOfFreq[curmx] == 0 && curmx) curmx--;
}

void MOsAlgo(){
    int n, q; cin >> n >> q;
    vector<Q> quer(q);
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<q; i++){
        int l, r; 
        cin >> l >> r;
        l--, r--;
        quer[i].i = i;
        quer[i].l = l;
        quer[i].r = r;
    }
    double val = sqrtl(double(n));
    block = (int)val + (val>2.5) ; // block size
    sort(all(quer), cmp);

    // start algorithm
    vector<int> ans(q);
    int curL = 0, curR = -1;
    curmx = 0;
    for(auto it : quer){
        int i = it.i, l = it.l, r = it.r;

        while(curL > l) {
            add(--curL);
        }
        while(curR < r){
            add(++curR);
        }
        while(curL < l){
            remove(curL++);
        }
        while(curR > r){
           remove(curR--);
        }
        
        int total = r - l + 1;
        int half = (total + 1) / 2;
        if(curmx <= half) ans[i] = 1;
        else ans[i] = 2 * curmx - total;
    }
    for(int i=0; i<q; i++){
        cout << ans[i] << endl;
    }
}

// class segTree {
//     public :
//         int n;
//         vector<int> tree, arr;
//         vector<vector<int>> occ;

//         segTree(int nn){
//             n = nn;
//             tree.resize(4*n+5);
//             arr.resize(n+1);
//             occ.resize(n+1);
//         }

//         int cnt(int l, int r, int node){
//             return upper_bound(occ[node].begin(), occ[node].end(), r)
//                 - lower_bound(all(occ[node]), l);
//         }

//         #define mid ((lo + hi)>>1)
//         void build(int i, int lo, int hi){
//             if(lo == hi) tree[i] = arr[lo];
//             else{
//                 build(2*i+1, lo, mid);
//                 build(2*i+2, mid+1, hi);
//                 int one = cnt(lo, hi, tree[2*i+1]);
//                 int two = cnt(lo, hi, tree[2*i+2]);
//                 tree[i] = one > two ? tree[2*i+1] : tree[2*i+2];
//             }
//         }

//         int query(int i, int lo, int hi, int l, int r){
//             if(l <= lo && r >= hi) return cnt(l, r, tree[i]);
//             else if(r < lo || l > hi) return 0;
//             return max(query(2*i+1, lo, mid, l, r), query(2*i+2, mid+1, hi, l, r));
//         }
// };

// void solve()
// {
//     int n, q; cin >> n >> q;
//     segTree t(n);
//     for(int i=0; i<n; i++){
//         cin >> t.arr[i];
//         t.occ[t.arr[i]].push_back(i);
//     }

//     t.build(0, 0, n-1);

//     while(q--){
//         int l, r; cin >> l >> r;
//         l--, r--;

//         int mx = t.query(0, 0, n-1, l, r);
//         int subs = 2 * mx - (r - l + 1);
//         cout << max(1ll, subs) << endl;
//     }
    
// }

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
        // solve();
        MOsAlgo();
    }
    return 0;
}