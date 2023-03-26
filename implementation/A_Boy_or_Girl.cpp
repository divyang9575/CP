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

int main()
{fast
    
    string user;
    cin >> user;

    set<char> s;
    fo(i,0,user.length()-1)
    {
        s.insert(user[i]);
    }

    int count = 0;
    for(auto &str : s)
    {
        count++;
    }

    if(count % 2 == 0) cout << "CHAT WITH HER!\n";
    else cout <<"IGNORE HIM!\n";
    
    return 0;
}