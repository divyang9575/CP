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


void solve(int tc)
{
    string s; cin >> s;
    int n = s.size();

    vvi pref(26, vi(n+1, 0));
    for(int i=0; i<n; i++){
        pref[s[i]-'a'][i+1]++;
        for(int j=0; j<26; j++){
            pref[j][i+1] += pref[j][i] ;
        }
    }

    int q ; cin >> q;
    for(int qr = 1; qr <= q; qr++) {
        int l, r; cin >> l >> r;
        vi cnt;
        for(int i=0; i<26; i++) {
            if(pref[i][r] - pref[i][l-1] > 0)
                cnt.push_back(pref[i][r] - pref[i][l-1]) ;
        }

        // if(qr == 75){
        //     string st = s.substr(l-1, r-l+1 );
        //     cerr<< st << endl;
        //     cout << st << endl;
        // }
        
        if(cnt.size() > 1) yes;
        else if(l == r) yes;
        else no;
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
    for(int tc = 1; tc <= t; tc++){
        solve(tc);
    }
    // cin >> t;
    // while(t--){
    //     solve();
    // }
    return 0;
}