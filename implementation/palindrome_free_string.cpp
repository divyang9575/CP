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
const int N = 1e5 + 5;
int n;
string s;

bool ispal(string str){
    db(str)
    int sz = str.size();
    if(sz < 5) return false;
    int i1=0, i2 = 1, j=sz-1;
    bool f = true;
    while(i1 < j){
        if(str[i1++] != str[j--]) 
            f = false;
    }
    if(f) return true;

    if(sz > 5){
        f = true;
        j = sz-1;
        while(i2 < j) 
            if(str[i2++] != str[j--]) 
                f = false;
    }

    return f;
}

map<string, int> dp[N];
int f(int i, string str){
    if(str.size() > 6) str.erase(str.begin());

    if(i == n) return 1;
    if(dp[i].find(str) != dp[i].end()) return dp[i][str];

    int ans = 0;
    if(s[i] != '?') {
        str += s[i];
        if(!ispal(str)) ans += f(i+1, str);
        str.pop_back();
    }
    else{
        // let it be 0
        str += '0';
        if(!ispal(str)) ans += f(i+1, str);
        str.pop_back();
        
        str += '1';
        if(!ispal(str)) ans += f(i+1, str);
        str.pop_back();
    }
    return dp[i][str] = ans;
}

void solve()
{
    cin >> n;
    cin >> s;
    string str = "";
    int i=0;
    bool fl = true;
    int ans = 0;
    while(i < n){
        if(s[i] != '?'){
            str += s[i];
            if(str.size() > 6) str.erase(str.begin());
            if(str.size() > 4 && ispal(str) ) {
                fl = false; break;
            }
            else{
                i++;
            }
        }
        else{
            ans = f(i, str);
            break;
        }
    }
    if(f && ans){
        yes;
        cout << ans << endl;
    }
    else no;
    
    // str = "??????";
    // int ans = f(0, str);
    // cout << ans;

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