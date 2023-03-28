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
    int donotcost,donots,boxcost;

    cin >> donotcost >> donots >> boxcost;

    if(boxcost <= donotcost){
        if(donots > 1){
            cout << -1 << " " << 2 << endl;
        }
        else cout << -1 << " " << -1 << endl;
    }
    else if(double(boxcost/donots) >= double(donotcost))
    {
        cout << 1 << " " << -1 << endl;
    }
    else
    {
        cout << 1 << " " << donots << endl;
    }
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