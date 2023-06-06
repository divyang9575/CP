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


void solve()
{
    int row, col; cin >> row >> col;
    int val = max(row, col);
    int ans = val*val - (val-1);
    if(row == col)
    {
        cout << ans << endl;
        return;
    }
    if(row > col)
    {
        if(row & 1)
        {
            ans -= (row - col);
        }
        else{
            ans += (row - col);
        }
    }
    else{
        if(col & 1)
        {
            ans += (col - row);
        }
        else{
            ans -= (col - row);
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