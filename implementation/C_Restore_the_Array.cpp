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
    int n;
    cin >> n;

    int a[n], b[n];
    fo(i,1,n-1) cin >> b[i];

    int i = 1;
    a[0] = b[1];

    while(i <= n-1)
    {
        if(b[i+1] <= b[i] && i+1 <= n-1)
        {
            a[i] = b[i+1];
            i++;
        }
        else 
        {
            a[i] = b[i];
            i++;

            // a[i] = b[i];
            // i++;
        }
    }

    fo(i,0,n-1)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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