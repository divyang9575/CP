#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define sort(a,all) sort(a.begin(), a.end())
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

bool isPossible(vi &pnts, int n, int cows, int mid)
{
    int lastPlacedCow = pnts[0];
    int minDist = mid;
    int noOfCows = 1;

    for(int i = 1; i<n; i++)
    {
        if(pnts[i] - lastPlacedCow >= minDist)
        {
            lastPlacedCow = pnts[i];
            noOfCows++;
        }
    }

    if(noOfCows >= cows)
    {
        return true;
    }
    else return false;
}

void solve()
{
    int n, cows; cin >> n >> cows;
    vi pnts(n); fo(i,0,n-1) cin >> pnts[i];
    
    sort(pnts, all);

    int low = 1, high = pnts[n-1] - pnts[0];
    int ans = -1;
    while(low <= high)
    {
        int mid = high - (high - low)/2;

        if(isPossible(pnts,n, cows, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans << endl;
}

int32_t main()
{fast
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}