#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define a(all) a.begin(), a.end()
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

int n, k; 

int func()
{
    int ans = 0;
    n--;
    k--;
    
    while(n > 0 && k > 0)
    {
        n -= k;
        k--;
        ans++;
        
    }
    if(n > 0) return -1;
    else return ans;
}

void solve()
{
    cin >> n >> k;
    if(n == 0 || n == 1) cout << 0;
    if(n <= k) cout << 1;

    cout << func();
}

int32_t main()
{fast
    solve();
    return 0;
}