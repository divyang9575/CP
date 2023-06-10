#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define all(a) a.begin(), a.end()
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


int rightind(int *a, int n, int val)
{
    int s=-1, e=n; //-infinity to +infinity
    int m;
    while(s+1 < e)
    {
        m = e-(e-s)/2;
        if(val >= a[m]) s = m;
        else e = m;
    }
    return s+1;
}
int leftind(int *a, int n, int val)
{
    int s=-1, e=n; //-infinity to +infinity
    int m;
    while(s+1 < e)
    {
        m = e-(e-s)/2;
        if(val > a[m]) s = m;
        else e = m;
    }
    return e+1;
}
int32_t main()
{
    int n; cin >> n ;
    int ar[n];
    for(int i=0; i<n; i++) cin >> ar[i];
    sort(ar, ar+n);
    int q; cin >>q;
    while( q-- > 0)
    {
        int a, b; cin >> a >> b;
        cout << rightind(ar,n,b) - leftind(ar, n, a) + 1 << " ";
    }
 
    return 0;
}