#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
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

vector<string> ans;

void func(string &s, int ind)
{
    int sz = s.size();
    if(ind == sz - 1)
    {
        ans.pb(s);
    }
    for(long unsigned int i = ind; i<s.size(); i++)
    {
        swap(s[i], s[ind]);
        func(s, ind+1);
        swap(s[i], s[ind]); // restore string
    }
}
void solve()
{
    string s; cin >> s;
    auto cpy= s;
    func(cpy, 0);
    sort(all(ans));

    vector<string> neww;
    neww.pb(ans[0]);
    for(auto it: ans)
    {
        if(it == neww.back()) continue;
        else neww.pb(it);
    }

    cout << neww.size() << endl;
    for(auto it : neww)
    {
        cout << it << endl;
    }
}

int32_t main()
{fast
    solve();
    return 0;
}