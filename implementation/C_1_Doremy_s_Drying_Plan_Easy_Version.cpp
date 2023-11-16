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


void calcpres(vi &pre, vi &cnt1, vi& cnt2, int n){
    for(int i=0; i<=n; i++){
        if(i) {
            pre[i] += pre[i-1];
            cnt1[i] += cnt1[i-1];
            cnt2[i] += cnt2[i-1];
        }
        if(pre[i] == 1) cnt1[i]++;
        if(pre[i] == 2) cnt2[i]++;
    }
}

pair<int, int> mxseg(vpi &lr, vi&cnt1, int m, int prev){
    int mx = 0, ind = -1;
    for(int i=0; i<m; i++){
        if(i == prev) continue;
        int l = lr[i].first, r = lr[i].second;
        int ones = cnt1[r] -  (l-1 >= 0 ? cnt1[l-1] : 0) ;
        if(ones > mx){
            ind = i;
            mx = ones;
        }
    }
    return {ind, mx};
}

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    int ans = 0;
    vpi lr(m);
    vi pre(n+1, 0);
    for(int i=0; i<m; i++){
        int l, r; cin >> l >> r; l--, r--;
        lr[i] = {l, r};
        pre[l]++, pre[r+1]--;
    }
    vi temppre = pre;
    vi cnt1(n+1, 0), cnt2(n+1, 0);
    vi tempcnt1 = cnt1;
    vi tempcnt2 = cnt2;
    sort(all(lr));
    calcpres(pre, cnt1, cnt2, n);
    for(int i=0; i<n; i++) ans += (pre[i] == 0);

    db(pre) db(cnt1) db(cnt2)
    int tempans = 0;

    int ind = mxseg(lr, cnt1, m, -1).first;
    int mx = mxseg(lr, cnt1, m, -1).second;
    if(ind != -1){
        tempans += mx;
        //remove segment
        int l = lr[ind].first, r = lr[ind].second;
        temppre[l]--, temppre[r+1]++;
        calcpres(temppre, tempcnt1, tempcnt2, n);

        int idx = mxseg(lr, cnt1, m, ind).first;
        int mx2 = mxseg(lr, cnt1, m, ind).second;
        if(idx != -1){
            tempans += mx2;
        }
    }

    // case 2 : intersecting segments
    int mx2 = 0;
    for(int i=0; i<m; i++){
        int l = lr[i].first, r = lr[i].second;
        bool f = true;
        for(int j=i+1; j<m; j++)
        {
            int l1 = lr[j].first, r1 = lr[j].second;
            if(l1 > r) break;

            int R = min(r1, r), L = l1;
            if(R == r) f = false;
            int twos = cnt2[R] - (L-1 >= 0 ? cnt2[L-1] : 0 );

            R = max(r, r1), L = l;
            int oness = cnt1[R] - (L-1 >= 0 ? cnt1[L-1] : 0 );
            mx2 = max(mx2, twos + oness);
            if(f == false) break;
        }
    }

    cout << ans + max(tempans, mx2) << endl;
    
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