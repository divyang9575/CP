#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
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
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

string rec;
int nb, ns, nc;
int prb, prs, prc;
int rub;
int bread = 0, sausage = 0, cheese = 0;

bool makeburgir(int m)
{
    int needB = (m * bread - nb) > 0 ? (m * bread - nb) : 0 ;
    int needS = m * sausage - ns > 0 ? m * sausage - ns : 0 ;
    int needC = m * cheese - nc > 0 ? m * cheese - nc : 0 ;

    int paisa = prb * needB + prs * needS + prc * needC;
    
    return paisa <= rub;
}

void solve()
{
    cin >> rec;
    cin >> nb >> ns >> nc;
    cin >> prb >> prs >> prc;
    cin>> rub;

    fo(i,0,sz(rec)-1){
        if(rec[i] == 'B')bread++;
        if(rec[i] == 'S')sausage++;
        if(rec[i] == 'C')cheese++;
    }

    int s=0, e = 1e15, m; // max burgers can be 1e14 when nb = 100 and rub = 1e12 //
    while(s+1 < e)
    {
        m = (s+e)/2;
        if(makeburgir(m))
        {
            s = m;
        }else{
            e = m;
        }
    }
    cout << s;
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

    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}