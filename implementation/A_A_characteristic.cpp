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

int fact(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;

    return fact(n-1)+fact(n-2);
}

lli nC2(lli n)
{
    long long ans = n*(n-1)/2;
    return ans;
}

void solve()
{
    lli n,k;
    cin >> n,k;

    int count1 = 0;
    rfo(i,n,2)
    {
        if(nC2(i) <= k)
        {
            count1 = nC2(i);
            break;
        }
    }
    if(count1 = 0)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES\n";
    int count0 = n-count1;

    fo(i,1,count1)
    {
        cout << 1 << " " ;
    }
    fo(i,1,count0)
    {
        cout << -1 << " ";
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