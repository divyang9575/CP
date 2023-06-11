#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define all(a) a.begin(), a.end()
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
int w, h, n; 

bool ok(int side)
{
    int minW = (side / w); 
    int minH = (side / h);
    if(minH*1LL*minW >= n) return true;
    else return false;
}
void solve()
{
    cin >> w >> h >> n;
    
    int s = 0, e = 1;
    while(ok(e) == false) e *= 2;
    while(s+1 < e)
    {
        int m = e-(e-s)/2;
        if(ok(m))
        {
            e = m;
        }
        else s = m;
    }
    cout << e;
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