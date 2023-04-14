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
    int n;
    cin >> n;

    string s;
    cin >> s;

    int first =  s[0];
    char ans = '0';
    int index;
    fo(i,1,s.size()-1)
    {
        if(int(s[i]) <= first)
        {
            ans = s[i];
            index = i;
        }
    }
    if(ans == '0'){
        cout << s << endl;
        return;
    }
    
    s.erase(index);
    cout << s << endl;
    string snew = "";
    snew.push_back(ans);
    snew = snew + s;

    cout << snew << endl;

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