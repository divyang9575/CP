#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define cntbits(x) __builtin_popcount(x)
#define nl '\n'
#define sz(a) a.size()
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) a.begin(), a.end()
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define memset(dp) memset(dp , -1, sizeof(dp))
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define yes cout << "YES" << endl
#define no cout << "NO" << endl

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

class med{
    public:
        int days, index;
        int cure = 0, effect = 0;

        med(int d, string c, string e, int i){
            days = d; index = i; 
            int n = sz(c);
            fo(i,0,n-1){
                cure += ((c[i]-'0' )<< (n-i-1));
            }
            fo(i,0,n-1){
                effect += ((e[i]-'0' )<< (n-i-1));
            }
        };
};

int f(int sym ,int din, vector<med> &dawai, int m, set<int> &st)
{
    if(sym == 0) return din;
    if(st.size() == m) return (int)1e9;

    int ans = 1e9;
    fo(i,0,m-1){
        if(st.find(dawai[i].index) != st.end()) continue;
        
        st.insert(dawai[i].index);
        int temp = sym;
        temp = (temp & (~dawai[i].cure)) | dawai[i].effect;
        ans = min(ans,  f(temp, dawai[i].days + din, dawai, m, st));
        st.erase(dawai[i].index);
    }
    if(ans >= 1e9) return -1;
    else return ans;
}


void solve()
{
    int n, m; cin >> n >> m;
    string s; cin >> s;
    int sym = 0;
    fo(i,0,n-1){
        sym += ((s[i]-'0' )<< (n-i-1));
    }
    debug(sym)

    vector<med> dawai;
    fo(i,0,m-1){
        int d; cin >> d;
        string a, b; cin >> a >> b;
        med newitem(d, a, b, i+1);
        dawai.pb(newitem);
    }

    set<int> st;
    int ans = f(sym, 0, dawai, m, st);
    cout << ans << nl;
    
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