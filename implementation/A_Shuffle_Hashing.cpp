#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
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
    string p,h;
    cin >> p>>h;

    vi cntp(26);
    fo(i,0,p.size()-1)
    {
        cntp[p[i] - 'a']++;
    }

    fo(i,0,h.size()-1)
    {
        vi cnth(26);

        fo(j,i,h.size()-1)
        {
            cnth[h[j] - 'a']++;

            if(cntp == cnth)  // both array equal at some point
            {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
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