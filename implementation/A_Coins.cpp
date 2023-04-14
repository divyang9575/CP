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
    long long int n,k;

    cin >> n >> k;

    bool flag;

    if(n ==1 && k == 1)
    {
        flag = true;
    }
    else if ( n%2 == 0){
        flag = true;
    }
    else if (k%2 != 0){
        flag = true;
    }
    else {
        flag = false;
    }

    if(flag ) cout << "YES\n";
    else cout << "NO\n";
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