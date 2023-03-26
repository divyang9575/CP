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
    int m;
    cin >> m;

    vector<vector<int>> inp;

    for(int i=0 ; i<m; i++)
    {
        int n;
        cin >> n;

        vi v(n);
        fo(i,0,n-1) cin >> v[i];

        inp.pb(v);
    }

    vector<set<int>> ans;

    fo(i,0,inp.size()-1)
    {
        set<int> s;

        fo(j,0,inp[i].size()-1)
        {
            s.insert(inp[i][j]);
            for(int k = i-1 ; k>= 0; k--){
                if(ans[k].find(inp[i][j]) != ans[k].end())
                {
                    ans[k].erase(inp[i][j]);
                }
            }
        }
        ans.pb(s);
    }
    bool flag = true;
    for(int i = 0 ; i<ans.size(); i++)
    {
        if(ans[i].empty())
        {
            flag = false;
        }
    }

    if(flag)
    {
        for(auto x : ans)
        {
            cout << *x.begin() << " ";
        }
    }
    else {
        cout << -1;
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