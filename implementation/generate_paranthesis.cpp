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

vector<vi> v;

void subsets(vi &temp,int i, vi &a, int n)
{
    if(i == n){
        v.pb(temp);
        return;
    }

    subsets(temp, i+1, a, n);

    temp.pb(a[i]);
    subsets(temp, i+1, a, n);
    temp.pop_back();
}

int main()
{fast
    
    int size; cin >> size;
    vi a(size); fo(i,0,size-1) cin >> a[i];

    vi temp;

    subsets(temp,0, a, size);

    for(auto sett : v)
    {
        for(auto ele : sett)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}