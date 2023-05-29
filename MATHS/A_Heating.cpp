#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define sort(a,all) sort(a.begin(), a.end())
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
    int sections, sum; cin >> sections >> sum;

    if(sum <= sections)
    {
        cout << sum << endl;
        return;
    }
    if(sections == 1)
    {
        cout << sum*sum << endl;
        return;
    }

    int minSections = sum / sections;
    
    int sectionsLeft = sum % sections;

    int ans;
    if(sectionsLeft > 0)
    {
        ans = pow(minSections + 1, 2) * sectionsLeft + pow(minSections , 2) * (sections - sectionsLeft);
    }
    else{
        ans = pow(minSections, 2) * sections;
    }

    cout << ans << endl;
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