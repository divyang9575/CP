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
    lli n , x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    if(x1 > n/2){
        x1 = n + 1 - x1;
    }
    if(y1 > n/2){
        y1 = n + 1 - y1;
    }
    if(x2 > n/2){
        x2 = n + 1 - x2;
    }
    if(y2 > n/2){
        y2 = n + 1 - y2;
    }

    lli belt1 = min(x1, y1);
    lli belt2 = min(x2, y2);

    cout << abs(belt2 - belt1) << endl;

    

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