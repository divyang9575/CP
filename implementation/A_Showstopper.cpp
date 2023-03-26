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

    fo(i,0,n-1) cin >> a[i];
    fo(i,0,n-1) cin >> b[i];

    fo(i, 0, n-2)
    {
        if(a[i] > a[n-1])
        {
            if(b[i] <= a[n-1]) swap(a[i], b[i]);
        }
        else if(b[i] > b[n-1])
        {
            if(a[i] <= b[n-1]) swap(a[i], b[i]);
        }
        
    }
    int m1 = *max_element(a , a+n);
    int m2 = *max_element(b, b+n);

    if(m1 == a[n-1]  && m2 == b[n-1]) cout << "YES\n";
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