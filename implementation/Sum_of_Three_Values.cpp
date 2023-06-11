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


void solve()
{
    int n, target; cin >> n >> target;
    vpi a; 
    fo(i,0,n-1) 
    {
        int x; cin >> x;
        a.pb({x, i});
    }
    sort(all(a));

    fo(i,0,n-2)
    {
        fo(j,i+1, n-1)
        {
            int pair = a[i].first + a[j].first;
            int s=j+1, e=n-1, m, ans=-1;
            while(s <= e)
            {
                m = e-(e-s)/2;
                // if(target-pair <= 0) break;
                if(a[m].first == (target - pair) && (m != i && m != j))
                {
                    ans = m;
                    break;
                }
                else if(a[m].first > (target-pair)){
                    e = m-1;
                }
                else s = m+1;
            } 
            if(ans == -1) continue;
            else{
                cout << a[i].second+1 << " " << a[j].second+1 << " " << a[m].second+1 ;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
    
}

int32_t main()
{fast
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}