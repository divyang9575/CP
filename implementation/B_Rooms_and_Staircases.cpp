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
    int n; cin >> n;

    string s; cin >> s;

    int i = 0, j = n-1;
    int indi = -1;
    int indj = -1;
    while(i<=j)
    {
        if(s[i] == '1')
        {
            indi = i;
            break;
        }
        else i++;

        if(s[j] == '1')
        {
            indj = j;
            break;
        }
        else j--;
    }

    int gotcha;
    
    if(indi == -1 && indj == -1)
    {
        cout << n << endl;
        return;
    }
    else if(indj == -1)
    {
        gotcha = indi+1;
    }
    else if(indi == -1){
        gotcha = n - indj;
    }

    int ans = 2*n - (gotcha - 1)*2;

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