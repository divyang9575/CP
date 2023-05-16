#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

void solve()
{
    int n,x,y;
    cin >> n >> x >> y;

    vi a(n+2); fo(i,1,n) cin >> a[i];
    a[0] = INT_MAX; a[n+1] = INT_MAX;

    int cntx = 0; int cnty = 0;
    int ans = -1;
    fo(i,1,n)
    {
        int flag = true;
        for(int j = i+1; j<=(i+y<=n ? i+y:n) ; j++)
        {
            if(a[j] < a[i])
            {
                flag = false;
            }
        }
        for(int j = i-1; j>=(i-x>0 ? i-x:1) ; j--)
        {
            if(a[j] < a[i])
            {
                flag = false;
            }
        }

        if(flag)
        {
            ans = i;
            break;
        }
    }

    cout << ans ;
}

int32_t main()
{fast
    solve();
    return 0;
}