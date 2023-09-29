#include<bits/stdc++.h>
#include<iostream>
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
    vi arr(n); 
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    bool flag = false;
    vi prefix_product(n+1, 1);
    vi presum(n+1, 0);
    vi segments;
    for(int i=0; i<n; i++) {
        if((prefix_product[i]  > 1e18 / arr[i])){
            flag = true; break;
        }
        prefix_product[i+1] = prefix_product[i] * arr[i];
        presum[i+1] = presum[i] + arr[i];
        if(arr[i] > 1) segments.push_back(i+1);
    }

    if(segments.empty()){
        cout << 1 << " " << 1 << endl;
        return;
    }

    if(flag){      // this means that the product is sufficienty larger than any possible sum

        // don't include prefix and suffix ones in the range
        int L = 0, R = n-1;
        while(arr[L] == 1) L++;
        while(arr[R] == 1) R--;
        cout << L+1 << " " << R+1 << endl;
        return;
    }

    // if not, means there can be atmost 60 2's which will keep the product less than 2^60
    // brute force iterate through all 60 value segents in n^2 time, n <= 60
    int mx = -1e9;
    int l = -1, r = -1;
    for(int L = 0; L<segments.size(); L++){
        for(int R = L; R < segments.size(); R++){
            int sumBeforL = presum[segments[L] - 1];
            int sumAfterR = presum[n] - presum[segments[R]];
            int productOfRange = prefix_product[segments[R]] / prefix_product[segments[L]-1];

            int total = sumBeforL + sumAfterR + productOfRange ;
            if(total > mx){
                mx = total;
                l = segments[L], r = segments[R];
            }
        }
    }
    cout << l << " " << r << endl;
    
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