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

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 


void solve()
{
    int n; cin >> n;
    string s, t; cin >> s >> t;

    string ans = "YES\n";
    int type = 0;
    if(s[0] == t[0]) type = 1;  // same
    else type = 2; // different

    for(int i=1; i<n; i++){
        if(type == 1){
            if(s[i] != t[i]){
                ans = "NO\n";
                break;
            }
        }
        if(type == 2){
            if(s[i] == t[i]){
                ans = "NO\n";
                break;
            }
        }
    }

    if(ans == "NO\n"){
        cout << ans ;
        return;
    }
    else cout << ans ;

    if(type == 2){
        // inverse all
        for(int i=0; i<n; i++){
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
    }

    int cnt1 = 0, cnt0 = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '0') cnt0++;
        else cnt1++;
    }

    if(cnt1 == 0){
        cout << 0 << endl;
        return;
    }
    if(cnt0 == 0){
        if(cnt1 == 1){
            cout << "NO\n";
        }
        else{
            cout<< 2 << endl;
            cout << 1 <<" " << 1 << endl;
            cout << 2 <<" " << n << endl;
        }
        return;
    }

    if(cnt1 % 2 == 0){
        if(type == 2) cnt1++;
        cout << cnt1 << endl;
        cout << 1 << " " << 1 << endl;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                cout << i+1 << " " << i+1 << endl;
            }
        }
    }
    else if(cnt0 % 2 == 0){
        if(type == 2) cnt1++;
        cout << cnt0 + 2 << endl;
        cout << 1 << " " << 1 << endl;
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                cout << i+1 << " " << i+1 <<endl;
            }
        }
        cout << 1 << " " << 1 << endl;
        cout << 2 << " " << n << endl;
    }
    else{
        if(type == 2) cnt1++;
        cout << cnt0 + 1 << endl;
        cout << 1 << " " << 1 << endl;
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                cout << i+1 <<  " " << i+1 << endl;
            }
        }
        cout << 1 <<  " " << n << endl;
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
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}