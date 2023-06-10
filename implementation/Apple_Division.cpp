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

int func(int ind, int s1, int s2, vi &a)
{
    if(ind == (int)a.size())
    {
        return abs(s1 - s2);       
    }                                       

    return min(func(ind+1, s1 + a[ind], s2 , a) , func(ind+1, s1, s2 + a[ind], a));

}

void solve()
{
    int n; cin >> n;
    vi a(n); fo(i,0,n-1) cin >> a[i];

    cout << func(0, 0 , 0 , a);
}

int32_t main()
{fast
    solve();
    return 0;
}