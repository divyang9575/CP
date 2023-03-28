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
    int n,m;
    cin >> n >> m;

    if(m > n) cout << -1;
    
    else{
        int s;
        if(n%2 == 0){
            s = n/2;
        }
        else {
            s = n/2 + 1;
        }
        
        for(int i = s; i<=n; i++)
        {
            if(i%m == 0){ 
                cout << i;
                break;
            }
        }
    }
}

int main()
{fast
    solve();
    return 0;
}