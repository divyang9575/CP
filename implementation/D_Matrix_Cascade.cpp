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
    vector<vector<char>> grid(n+2, vector<char>(n+2));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> grid[i][j];
        }
    }

    vvi dpLD(n+2, vector<int>(n+2, 0));
    vvi dpRD(n+2, vector<int>(n+2, 0));
    vvi affect(n+2, vector<int>(n+2, 0));
    int ans = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){

            bool changed = 0; // weather current element changes or not.
            //main DP
            if(i==1 ){ // base case
                if((grid[i][j]=='1')) {
                    affect[i][j] = 1;
                    changed = 1;
                    ans++;
                }
            }
            else {
                int uparWaleChanges = affect[i-1][j] + dpLD[i-1][j-1] + dpRD[i-1][j+1];

                if(uparWaleChanges % 2 == 1){ // 0 - 1 
                    affect[i][j] = (grid[i][j]=='0') + uparWaleChanges ; 

                    if(grid[i][j]=='0') {
                        changed = 1;
                        ans++;
                    }
                }
                else{ // 1 - 0 - 1
                    affect[i][j] = (grid[i][j]=='1') + uparWaleChanges ;

                    if(grid[i][j]=='1') {
                        changed = 1;
                        ans++;
                    }
                }
            }

            // states of diagonals
            dpLD[i][j] = dpLD[i-1][j-1] + changed ;
            dpRD[i][j] = dpRD[i-1][j+1] + changed ;
        }
    }
    
    cout << ans << endl;
    
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