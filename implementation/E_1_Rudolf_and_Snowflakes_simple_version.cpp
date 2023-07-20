#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define cntbits(x) __builtin_popcount(x)
#define nl '\n'
#define sz(a) a.size()
#define int long long int
#define M (int)1e18
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

#define yes cout << "YES" << endl
#define no cout << "NO" << endl

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 


// int power(int a, int n){ // a^n
//   int res = 1;

//   while(n){
//     if(n%2 == 0){ // power is even
//     //   if(a > 1e9) return -1;
//       a = (a *a ); // square base 
//       n = n/2; // half the power
//     }
//     else{
//     //   if(res > 1e18/a) return -1;
//       res = (res *a );
//       n--;
//     }
//   }
//   return res;
// }

// we can actually binary search the values of no of terms(max 60).
// coz for a particular term lets say 3 terms = 1 + k + k^2
// it is always a increasing function for increasing k.

int gp(int k, int n){
    int a = 1;
    int ans = 1;
    fo(i,1,n-1){     // calculating sum of n terms
        if(a > 1e18/k || ans > 1e18-a){
            return 2e18;
        }
        a *= k; 
        ans += a;
    }
    return ans ;
}

void solve()
{
    int n; cin >> n;
    if(n < 7){
        no;
        return ;
    }
    
    fo(terms, 3, 60) // 1e18 ~ 2^60
    {
        int lo = 2, hi = 1e9, k;
        while(lo <= hi){
            k = (lo+hi) / 2;
            
            if(gp(k, terms) > n){
                hi = k-1;
            }
            else if(gp(k, terms) < n){
                lo = k+1;
            }
            else if(gp(k, terms) == n){
                yes;
                return;
            }
        }
    }

    no;
}

int32_t main()
{fast

    int64_t t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}