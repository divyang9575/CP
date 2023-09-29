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

bool cmp(pi a, pi b){
    return a.first >= b.first;
}


void solve()
{
    int n; cin >> n; db(n)
    vi indeg(n, 0), visited(n, 0);
    vi arr(n), c(n); 
    for(int i=0; i<n; i++) {
        cin >> arr[i] ;
        arr[i]--;
        indeg[arr[i]]++;
    }
    for(int i=0; i<n; i++) {
        cin >> c[i];
    }

    vi sell;
    for(int i=0; i<n; i++){
        int node = i;
        while(indeg[node] == 0 && !visited[node]){   // no one afraid off this 'node'
            sell.push_back(node);
            visited[node] = 1;
            indeg[arr[node]]--;
            node = arr[node];
            db(sell)
        }
    }

    // the not visited elements are the ones which have cycles
    for(int i=0; i<n; i++){
        if(!visited[i]){
            vpi costWiseNodes;
            int node = i;
            while(!visited[node]){
                costWiseNodes.push_back({c[node], node});
                visited[node] = 1;
                node = arr[node]; 
            }

            // sort(all(costWiseNodes), cmp);
            int mn = 1e9, mnind = -1;
            for(int j=0; j<costWiseNodes.size(); j++){
                if(costWiseNodes[j].first < mn){
                    mn = costWiseNodes[j].first;
                    mnind = j;
                }
            }

            for(int k = mnind+1 ; k < costWiseNodes.size(); k++){
                sell.push_back(costWiseNodes[k].second);
            }
            for(int k=0; k<=mnind; k++){
                sell.push_back(costWiseNodes[k].second);
            }
        }
    }
    
    for(int i=0; i<sell.size(); i++){
        cout << sell[i]+1 << " ";
    }
    cout << endl;
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