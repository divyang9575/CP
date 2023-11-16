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

class Solution {
public:
    const int M = 1e9+7;
    void modsum(int &a, int b) { a = (a%M + b%M + 0LL + M )%M;}
    void modmul(int &a, int b) { a = (a%M * b%M)%M;}

    int countSubMultisets(vector<int>& nums, int l, int r) {
        int n = nums.size();
        map<int, int> mp;
        int sum = 0;
        for(int i=0; i<n;i++){
            mp[nums[i]]++;
            sum += nums[i];
        }
        vector<int> arr;
        for(auto it : mp){
            if(it.first == 0) continue;
            arr.push_back(it.first);
        }

        n = arr.size();
        r = min(r, sum);
        vector<int> dp(r+1, 0);
        dp[0] = 1;

        
        for(int i=1; i<=n; i++){
            int num = arr[i-1];
            int freq = mp[arr[i-1]] ;
            vector<int> psum = dp ;
            for(int j=num; j<=r; j++){
                modsum(psum[j] , psum[ j - num ] );
            }

            for(int j=1; j<=r; j++){
                int st = j - num ;
                int end = j - (freq+1) * num;
                if(st >= 0) modsum(dp[j], psum[j - num]) ;
                if(end >= 0) modsum(dp[j], -psum[j - (freq+1) * num]);

                // for(int k=0; k<=freq ; k++){
                //     if(j - k*arr[i-1] >= 0)
                //     modsum(dp[i][j], dp[i-1][j - k*arr[i-1] ] );
                // }
            }
        }
        
        
        
        int ans = 0;
        for(int i=l; i<=r; i++){
            modsum(ans, dp[i]);
        }
        return (ans*1LL*(1 + mp[0])) % M;
    }
};

void solve()
{
    int n; cin >> n;
    vi arr(n); 
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int l, r; cin >> l >> r;

    Solution ob;
    cout << ob.countSubMultisets(arr, l, r);
    
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