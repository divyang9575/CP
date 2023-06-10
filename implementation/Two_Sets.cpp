#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define a(all) a.begin(), a.end()
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
    int n; cin >> n;
    int sum = (n*(n+1))/2;

    if(sum & 1)
    {
        cout << "NO\n";
        return;
    }

    int req = sum/2;
    unordered_set<int> st;

    int i = n;
    int j = 1;
    int cursum = 0;
    while(cursum < req)
    {
        cursum += i;
        if(cursum <= req) st.insert(i);
        else break;
        i--;

        cursum += j;
        if(cursum <= req) st.insert(j);
        else break;
        j++;
    }
    cout << "YES\n";
    cout << st.size() << endl;
    for(auto it : st)
    {
        cout << it << " " ;
    }
    vi second;
    fo(x,1,n)
    {
        if(st.find(x) == st.end())
        {
            second.pb(x);
        }
    }
    cout << endl << second.size() << endl; 
    for(auto it : second)
    {
        cout << it << " ";
    }
}

int32_t main()
{fast
    solve();
    return 0;
}