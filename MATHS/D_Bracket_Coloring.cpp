#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
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
    int n; cin >> n;
    string s; cin >> s;

    if(n & 1)
    {
        cout << -1 << endl;
        return;
    }

    // if(s[0] == ')')
    // {
    //     reverse(s.begin(), s.end());
    // }

    stack<pair<char, int>> kets;

    fo(i,0,n-1)
    {
        if(s[i] == '(')
        {
            kets.push({s[i], i});
        }
        if(s[i] == ')')
        {
            if((kets.empty() != 1 ) && kets.top().first == '(')
            {
                kets.pop();
            }
            else{
                kets.push({s[i], i});
            }
        }
    }

    if(kets.empty())
    {
        cout << 1 << endl;
        fo(i,0,n-1)
        {
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }

    string rem = "";
    unordered_set<int> index;
    while(kets.empty() != 1)
    {
        rem += kets.top().first;
        index.insert(kets.top().second);

        kets.pop();
    }

    stack<char> check;
    fo(i,0,rem.length()-1)
    {
        if(rem[i] == '(')
        {
            check.push(rem[i]);
        }
        if(rem[i] == ')')
        {
            if((check.empty() != 1 ) && check.top() == '(')
            {
                check.pop();
            }
            else{
                check.push(rem[i]);
            }
        }
    }
    if(check.empty() != 1)
    {
        cout << -1 << endl;
    }
    else{
        if(rem.length() == n)
        {
            cout << 1 << endl;
        }
        else
            cout << 2 << endl;


        fo(i,0,n-1)
        {
            auto it = index.find(i);
            if( it != index.end())
            {
                cout << 1 << " ";
            }
            else cout << 2 << " ";
        }
        cout << endl;
    }
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