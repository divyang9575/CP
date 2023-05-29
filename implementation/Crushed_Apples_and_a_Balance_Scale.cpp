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

void solve()
{
    int m,n; cin >> m >>n;

    if(n > m)
    {
        cout << "NO\n";
        return;
    }
    if(n == m)
    {
        cout << "YES\n";
        return;
    }

    bool flag = false;

    for(int i = m; i/2 > 0; i /= 2)
    {
        int a = i/2;
        int b = (i+1)/2;
        
        if(a != b)
        {
            break;
        }

        if(n % a == 0)
        {
            
            flag = true;
            break;
        }


    }

    if(flag)
    {
        cout << "YES\n";
    }
    else cout << "NO\n";
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