#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define arr(all) arr.begin(), arr.end()
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

int n,m;

bool isPossible(int operations,  vector<int> &a)
{
    int ans = 0;
    fo(i,0,n-2)
    {
        if(a[i] <= a[i+1]) continue;
        else
        ans = max(ans, min(m-a[i], a[i]-a[i+1]) );
    }
    if(ans <= operations) return true;
    else return false;
}
void solve()
{
     cin >>n>>m;
     vi a(n);
     fo(i,0,n-1) cin >> a[i];

    int ans = 0;
    int s = 0, e = 3e5+1;
    while(s <= e)
    {
        int mid = e-(e-s)/2;
        if(isPossible(mid, a))
        {
            ans = mid;
            e = mid-1;
        }
        else s = mid+1;
    }
    cout << ans ;
}

int32_t main()
{fast
    solve();
    return 0;
}