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

string lexoTrim(string &s, int delchars) 
{
    int n = s.size();

    vector<int> del(n, 0);
    stack<int> last;

    for(int i=0; i<n-1; i++){
        last.push(i);
        while(last.size() && s[i+1] < s[last.top()] && delchars > 0){
            del[last.top()] = 1;
            last.pop();
            delchars--;
        }
        if(delchars == 0) break;
    }

    last.push(n-1);
    while(delchars > 0 && last.size() > 0){
        del[last.top()] = 1;
        last.pop();
        delchars--;
    }

    string ans ;
    for(int i=0; i<n; i++){
        if(!del[i]) ans += s[i];
    }
    return ans;
}

void solve()
{
    string s; cin >> s;
    int k ; cin >> k;
    int n = s.size();

    int len = n, delchars = 0;
    while(k > len){
        k -= len;
        len--;
        delchars++;
    }

    string small = lexoTrim(s, delchars) ;
    cout << small[k-1] ;
}

// void solve()
// {
//     string s; cin >> s;
//     int k ; cin >> k ;

//     int n = s.size() ;
//     vi vis(n, 0) ;

//     if(k <= n){
//         cout << s[k-1] ;
//         return ;
//     }

//     int i=0; 
//     int size = n;
//     while(i < n){
//         if(k <= size){
//             break;
//         }
//         if(i < n-1 && s[i] > s[i+1]){
//             vis[i] = 1 ;
//             k -= size ;
//             size--;

//             if(k <= size) break;
            
//             int a = i-1, b = i+1;
//             if(a != -1){
//                 while(a >= 0 && k > size && s[a] > s[b]){
//                     if(vis[a] == 1){
//                         a--; continue;
//                     }
//                     k -= size;
//                     size--;
//                     vis[a] = 1;
//                     a--;
//                 }
//             }
//             if(k <= size){
//                 break;
//             }
//             i++ ;
//         }
//         else{
//             if(i == n-1){
//                 while( k > size ){
//                     if(vis[i] == 1){
//                         i--;
//                         continue;
//                     }
//                     k -= size;
//                     size--;
//                     vis[i] = 1;
//                     i--;
//                 }
//                 break;
//             }
//             i++ ;
//         }
//     }

//     int c=0;
//     for(int j = 0; j<n; j++){
//         if(vis[j] == 0){
//             c++;
//             if(c == k){
//                 cout << s[j];
//                 return;
//             }
//         }
//     }
    
// }

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