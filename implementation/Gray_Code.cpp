#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define a(all) a.begin(), a.end()
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

vector<string> func(int n)
{
    if(n == 1)
    {
        return {"0", "1"};
    }

    vector<string> ans;

    vector<string> temp = func(n-1);

    fo(i,0,temp.size()-1)
    {
        ans.push_back("0" + temp[i]);
    }
    rfo(i,temp.size()-1,0)
    {
        ans.push_back("1" + temp[i]);
    }
    return ans;
}
void solve()
{
    int n; cin >> n;

    vector<string> ans = func(n);
    for(auto it : ans)
    {
        cout << it << endl;
    }
}

int32_t main()
{fast
    solve();
    return 0;
}