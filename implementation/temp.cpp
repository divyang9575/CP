#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD1 998244353
#define MOD 1000000007
#define PI 3.141592653589793238462
#define INF 1e18

#define nline "\n"
#define nl "\n"
#define py cout<<"Yes\n";
#define pn cout<<"No\n";
#define pyy cout<<"YES\n";
#define pnn cout<<"NO\n";
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define fs(x) fixed<<setprecision(x)
#define set_bits __builtin_popcount
#define sz(x) (int)(x.size())

/*pair input*/template<typename F,typename S>istream& operator>>(istream& istream,pair<F,S>& p){cin>>p.first>>p.second;return istream;}
/*pair output*/template<typename F, typename S>ostream& operator<<(ostream& ostream,pair<F,S>& p){cout<<p.first<<" "<<p.second;return ostream;}
/*vector input*/template<typename T>istream& operator>>(istream& istream,vector<T>& v){for(auto& element:v){cin>>element;}return istream;}
/*vector output*/template<typename T>ostream& operator<<(ostream& ostream,vector<T>& v){for(auto& element:v){cout<<element<<" ";}return ostream;}
/*vvl output (just added endl)*/template<typename T>ostream& operator <<(ostream& ostream, vector<vector<T>>& v){for(auto& row : v){for(auto& cell : row){cout << cell << " ";}cout << "\n";}return ostream;}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << "\n";
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long  ull;
typedef long double         ld;
typedef pair<ll, ll>        pl;
typedef pair <int,int>      pi;
typedef vector<int>         vi;
typedef vector<ll>          vl;
typedef vector<string>      vs;
typedef vector<pi>          vpi;
typedef vector<pl>          vpl;
typedef vector<vi>          vvi;
typedef vector<vl>          vvl;
typedef priority_queue<int, vector<int>, greater<int>>  min_heap32;
typedef priority_queue<ll, vector<ll>, greater<ll>>     min_heap64;
typedef priority_queue<int>                             max_heap32;
typedef priority_queue<ll>                              max_heap64;
typedef unordered_map<int, int>                         umap32;
typedef unordered_map<ll, ll>                           umap64;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
/*  find_by_order() and order_of_key() */

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "["; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "["; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
ll ETF(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0)n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //(coprimes less than n){n*pi(1-1/prime)}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) {return (a*b)/gcd(a,b);}
ll expo(ll a, ll b, ll mod){ll r=1;while(b){if(b&1)r=(r*a)%mod;a=(a*a)%mod;b=b>>1;}return r;}//iterative(binary bits b are only multiplied) 

// void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
// ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} 
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

int isPrime(int N){if(N<2 || (!(N&1) && N!=2))return 0;for(int i=3; i*i<=N; i+=2){if(!(N%i))return 0;}return 1;}

vector<ll> primeFactors(ll n){vector<ll>factors;while(n%2==0){factors.push_back(2);n=n/2;}for(int i=3;i<=sqrt(n);i=i+2){while(n%i==0){factors.push_back(i);n=n/i;}}if(n>2)factors.push_back(n);return factors;}
vector<ll> allFactors(ll n)/*unsorted*/{vector<ll> factors;for(int i=1;i<=sqrt(n);i++){if(n%i==0){factors.push_back(i);if(n/i!=i)factors.push_back(n/i);}}return factors;}

void printBinary(int num){for(int i=25;i>=0;--i){cout<<((num>>i)&1);}cout<<endl;}

template<typename T>
ll vsum(vector<T> v){ll s=0;for(int i=0;i<v.size();i++)s+=v[i];return s;}
void presum(vl &a){ll n=a.size();for(int i=1;i<n;i++){a[i]+=a[i-1];}}
string tostring(ll n){string s;while(n){s+=(n%10)+'0';n/=10;}reverse(all(s));return s;}
vl tobinary(ll n){vl t;while(n){t.pb(n%2);n=n/2;}ll s=t.size();for(int i=s;i<64;i++){t.pb(0);}reverse(all(t));return t;}
/*--------------------------------------------------------------------------------------------------------------------------*/
const int MAX_SIZE = 2800001;
// const int MAX_SIZE = 300100;
// const int MAX_SIZE = 10;
vector<int>isprime(MAX_SIZE , true);
vector<int> idx(MAX_SIZE);
vector<int> prime;
vector<int>SPF(MAX_SIZE);
void manipulated_seive(int N) 
{
    isprime[0] = isprime[1] = false ;
    for (int i = 2; i < N ; i++) 
    {
        if (isprime[i]) 
        {
            prime.push_back(i);
            SPF[i] = i;
        }
        for (int j = 0; j < (int)prime.size() && i * prime[j] < N && prime[j] <= SPF[i]; j++) 
        {
            isprime[i * prime[j]] = false;
            SPF[i * prime[j]] = prime[j] ;
        }
    }
    for (int i = 0; i < (int)prime.size(); i++) 
    {
        idx[prime[i]] = i + 1;
    }
}
vector<ll> getFactorization(ll x)
{
    vector<ll> ret;
    while (x != 1)
    {
        ret.push_back(SPF[x]);
        x = x / SPF[x];
    }
    return ret;
}

vl primeFactors_sieve(ll a) 
{
    vl p;
    for (auto i : prime) {
        if (i*i > a)
            break;
        if (a % i == 0) {
            p.pb(i);
            while (a % i == 0) {
                a /= i;
            }
        }
    }
    if(a!=1) p.pb(a);
    // debug(p)
return p;
}

// float logBase(ll a, ll b)
// {
//     return (float)log(a) / (float)log(b);
// }

class DSU {
public:
    ll n, components;
    vector<ll> parent, siz;

    DSU(ll n) {
        this->n = n;
        for (ll i = 0; i < n; ++i) {
            parent.push_back(i);
            siz.push_back(1);
        }
        components = n;
    }

    ll find_par(ll v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_par(parent[v]); // path compression
    }

    ll getSiz(ll node) {
        return siz[find_par(node)];
    }

    set<ll> getParents() {
        set<ll> s;
        for (ll i = 0; i < n; i++) s.insert(find_par(i));
        return s;
    }

    void union_sets(ll a, ll b) 
    {
        a = find_par(a);
        b = find_par(b);

        if (a == b) return ;

        if (siz[a] > siz[b]) swap(a, b);
        parent[a] = b;
        siz[b] += siz[a];

        components--;
        return ;
    }
};
/**********************************************************/
vector<ll> fac(int(1e6+10),0);
void calfac(ll M){
    fac[0]=1;
    fac[1]=1;
    for(int i=2;i<1e6+10;i++){
        fac[i]=i*fac[i-1];
        fac[i]%=M;
    }
}
ll NPR(ll a,ll b,ll M){
  ll nu=fac[a];
  ll de=fac[a-b];
  de%=M;
  return mod_div(nu,de,M);
}
ll NCR(ll a,ll b,ll M){
  if(a<0||b<0||b>a)return 0;
  ll nu=fac[a];
  ll de=fac[b]*fac[a-b];
  de%=M;
  return mod_div(nu,de,M);
}

/**********************************************************/
void presolve(){
    // manipulated_seive(1e6+100);
    calfac(MOD1);
}
/**********************************************************/
void solve(int tc){
    ll n;
    cin>>n;
    vl a(n);
    cin>>a;
    ll ans=0;
    ll p=0;
    if(n==1){
        cout<<max(a[0],0LL)<<nl;
        return;
    }
    for(int i=n-1;i>1;i--){
        
            if(a[i]>0){
                p+=a[i];
            }
    }
        ans=max(ans,p);//for sure 
        ans=max(ans,a[0]+p);
        ans=max(ans,a[0]+a[1]+p);
    cout<<ans<<nl;
}


void setIO(string name, bool includeout=false) { 
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main()  
{
    fastio();
    // setIO("perimeter", true);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    auto start1 = high_resolution_clock::now();
    int tc=1;
    presolve();
    cin>>tc;    
    for(int i=1;i<=tc;i++)
    { 
        // cout << "Case " << i << ": "; 
        // oops your are dead now 
        solve(i);
    }   
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() / 1000 << endl;
    #endif
    return 0;
}



   

/*
>  vector is slow than array and try to make it global

>  s.lower_bound(x) [better for sets (non linear data structure)] vs  lower_bound(all(a),x)
>  ordered_multiset : s.erase(--s.lower_bound(x)) || s.erase(s.upper_bound(x))
                   https://codeforces.com/blog/entry/88193
                   or use pair{val,ind} 

   find_by_order(k)  returns iterator to kth element starting from 0;
   order_of_key(k) returns count of elements strictly smaller than k;
 
>  sometimes int may save you from getting tle even if your code is not optimized 
>  cerr does not gives the output in answer file but is considered as 
   an operation therfore will give tle 
*/

////  gcd (a,b) = gcd(a-b,b) 