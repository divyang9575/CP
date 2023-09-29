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
    vi arr(n); int sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum%n != 0){
        cout << "No\n";
        return;
    }
    multiset<int> S, T;
    
    int target = sum / n;
    vi vis(n, 0);
    for(int i=0; i<n; i++){
        if(arr[i] == target) continue;
        bool f = false;

        if(target > arr[i]){ // target - a = 2^y - 2^x
            int need = target - arr[i];
            for(int x=0; x<=31; x++){
                for(int y=x+1; y<=31; y++){
                    int val = pow(2, y) - pow(2, x);
                    // if(val > need) break;
                    if(val == need){
                        S.insert(x);
                        T.insert(y);
                        f=true;
                        break;
                    }
                }
                if(f) break;
                // else{
                //     cout <<"No\n";
                //     return;
                // }
            }
        }
        else if(arr[i] > target){
            int need = arr[i] - target ;
            for(int y=0; y<=31; y++){
                for(int x=y+1; x<=31; x++){
                    int val = pow(2, x) - pow(2, y);
                    // if(val > need) break;
                    if(val == need){
                        S.insert(x);
                        T.insert(y);
                        f = true;
                        break;
                    }
                }
                if(f) break;
                // else{
                //     cout <<"No\n";
                //     return;
                // }
            }
        }
    }
    db(S) db(T)
    if(S == T){
        cout << "Yes\n";
    }
    else cout << "No\n";

    
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