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


void solve()
{
    int n, target; cin >> n >> target;
    vpi a(n+1);
    a[0] = {-1, -1};
    fo(i,1,n)
    {
        int x; cin >> x;
        a[i] = {x, i};
    }

    pi ans = {-1, -1};
    sort(a.begin()+1, a.end());
    int i=1, j=n;
    while(i < j)
    {
        if((a[i].ff + a[j].ff) == target)
        {
            ans = {a[i].ss, a[j].ss};
            i++, j--;
            break;
        }
        else if(a[i].ff + a[j].ff > target)
        {
            j--;
        }
        else i++;
    }

    if(ans.ff == -1) cout << "IMPOSSIBLE";
    else cout << ans.ff << " " << ans.ss;
}

int32_t main()
{fast
    solve();
    return 0;
}