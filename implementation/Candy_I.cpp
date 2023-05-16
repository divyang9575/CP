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
    int n ; cin >> n;

    while(n != -1)
    {
        int sum = 0;
        vi v(n);
        fo(i,0,n-1) 
        {
            cin >> v[i];
            sum += v[i];
        }

        if(sum%n != 0)
        {
            cout << -1 << endl;
        }
        else{
            int factor = sum / n;
            int moves = 0;
            fo(i,0,n-1)
            {
                if(v[i] > factor)
                {
                    moves += (v[i] - factor);
                }
            }

            cout << moves << endl;

            v.erase(v.begin(), v.end());
        }

        cin >> n;
        
        
    }
}

int32_t main()
{fast
    solve();
    return 0;
}