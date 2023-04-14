#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define lli long long int
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
    int n,m; cin >> n >> m;

    int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;

    if(x1 == 1 && y1 == 1 || x1 == 1 && y1 == m || x1 == n && y1 == 1 || x1 == n && y1 == m )
    {
        cout << 2 << endl;
        return;
    }
    if(x2 == 1 && y2 == 1 || x2 == 1 && y2 == m || x2 == n && y2 == 1 || x2 == n && y2 == m )
    {
        cout << 2 << endl;
        return;
    }
    if(min(x2,x1) == 1 || min(y2,y1) == 1 || max(x1,x2) == n || max(y1,y2) == m)
    {
        cout << 3 << endl;
        return;
    }
    else{ cout << 4 << endl; return;}

}

int main()
{fast
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}