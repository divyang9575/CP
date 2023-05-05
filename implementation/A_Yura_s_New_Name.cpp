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
    string s; cin >> s;

    int count = 0;
    bool dash = false;

    if(s.length() == 1 && s[0] == '^') {
        cout << 1 << endl;
        return;
    }
    if(s[0] == '_'){
        count++;
    }
    if(s[s.length()-1] == '_') count++;

    
    fo(i,0,s.length()-1)
    {
        if(s[i] == '_')
        {
            if(dash)
            {
                count++;
            }
            else dash = true;
        }
        else dash = false;
    }
    cout << count << endl;
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