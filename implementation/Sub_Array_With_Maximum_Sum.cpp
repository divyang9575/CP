#include<bits/stdc++.h>
// #include<iostream>
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
#define db(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define db(x)
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


void solve()
{
    int n; cin >> n;
    vi a(n+1), b(n+1); 
    a[0] = -2e9, b[0] = -2e9;
    int minn = 2e9, mnind = -1;
    fo(i,1,n) {
        cin >> a[i];
        if(a[i] < minn){
            minn = a[i];
            mnind = i;
        }
        else if(a[i] == minn){
            if(abs(n/2 - i) < abs(n/2 - mnind)){
                mnind = i;
            }
        }
    }
    fo(i,1,n) {
        cin >> b[i];
        if(b[i] < minn){
            minn = b[i];
            mnind = i;
        }
        else if(b[i] == minn){
            if(abs(n/2 - i) < abs(n/2 - mnind)){
                mnind = i;
            }
        }
    }
    db(n) db(a) db(b) db(minn) db(mnind)

    vi c(2*n + 1, 0); c[0] = -2e9;

    // alice moves
    if(mnind <= n/2){
        c[2*(mnind)] = minn;
        c[2*(mnind) - 1] = (minn == a[mnind]) ? b[mnind] : a[mnind];
    }
    else{
        c[2*(mnind) - 1] = minn;
        c[2*(mnind)] = (minn == a[mnind]) ? b[mnind] : a[mnind];
    }
    db(c)

    // bob
    fo(i,1,n){
        if((c[2*i] != 0 && c[2*i - 1] != 0)){
            continue;
        }

        if(a[i] >= 0 && b[i] >= 0){
            c[2*i - 1] = a[i];
            c[2*i] = b[i];
        }
        else if(a[i] < 0 && b[i] < 0){
            c[2*i - 1] = a[i];
            c[2*i] = b[i];
        }
        else
        { // important case
            if(i == 1 || c[2*(i-1)] < 0){  // prev negative
                if(a[i] < 0){
                    c[2*i - 1] = a[i];
                    c[2*i] = b[i];
                }
                else{ // b[i] < 0
                    c[2*i - 1] = b[i];
                    c[2*i] = a[i];
                }
            }
            else{ // prev positive
                if(a[i] > 0){
                    c[2*i - 1] = a[i];
                    c[2*i] = b[i];
                }
                else{ // b[i] > 0
                    c[2*i - 1] = b[i];
                    c[2*i] = a[i];
                }
            }
        }
    }
    db(c)

    // kadane's algo to find the subarray sum
    int cursum = 0, sum = 0;
    fo(i,1,2*n){
        cursum += c[i];
        if(cursum < 0) {
            cursum = 0;
        }
        else{
            sum = max(cursum, sum);
        }
    }
    cout << sum << nl;
    
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