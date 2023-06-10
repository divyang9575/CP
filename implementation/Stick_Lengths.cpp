// #include<bits/stdc++.h>
// using namespace std;

// #define M 1000000007
// #define PI 3.1415926535897932384626433832795
// #define endl '\n'
// #define vi vector<long long>
// #define all(a) a.begin(), a.end()
// #define vpi vector<pair<long long,long long>>
// #define pb push_back
// #define pi pair<long long,long long>
// #define ff first
// #define ss second
// #define fo(i,s,e) for(long long i=s; i<=e; i++)
// #define rfo(i,e,s) for(long long i=e; i>=s; i--)
// #define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

//  // binary search ? dp ? change observation.. 
//  // edge cases ? overflow ? limits ? 

// // O(1)
// long long mincost(long long x, int index, vi&a, vi &pre, long long size)
// {
//     // long long ind = lower_bound(a.begin()+1, a.end(), x) - a.begin();
//     long long firstK = index - 1; long long secondK = size - firstK;
//     long long sum1 = pre[firstK]; long long sum2 = pre[size] - pre[firstK];

//     long long cost = (firstK * x - sum1) + (sum2 - secondK * x) ;
//     return cost;
// }
// void solve()
// {
//     long long n; cin >> n;
//     vi a(n+1); fo(i,1,n) cin >> a[i];
//     vi pre(n+1);
//     sort(a.begin()+1, a.end());
//     pre[0] = 0;
//     fo(i,1,n)
//     {
//         pre[i] = pre[i-1] + a[i];
//     }
    
//     long long ans = INT64_MAX;
//     // long long mn = a[1], mx = a[n];
//     // cout << mn << mx ;
//     fo(i, 1, n)
//     {
//         if(mincost(a[i],i, a, pre, n) <= ans)
//         {
//             ans = mincost(a[i], i, a, pre, n);
//         }
//         else break;
//     }
//     cout << ans;
// }

// int main()
// {fast
//     long long t = 1;
//     // cin >> t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }

///////////////////////////////////.........................//////////////////////////////////////////////////////////
// SOLUTION SECOND (LESS TIME AND SIMPLE) //

//CONCEPT OF MEDIAN

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 


void solve()
{
    int n; cin >> n;
    vi a(n); fo(i,0,n-1) cin >> a[i];
    sort(all(a));
    
    int median = a[n/2]; //for zero based indexing it is true for both even and odd

    int cost = 0;
    fo(i,0,n-1) cost += abs(a[i] - median);

    cout << cost;
}

int32_t main()
{fast
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}