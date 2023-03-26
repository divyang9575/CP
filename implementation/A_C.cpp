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
    int t;
    cin >> t;
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;

        if(b<a) swap(a,b);

        int count = 0;

        while(a <= n && b<= n)
        {
            a+=b;
            count++;
            if(b<a) swap(a,b);
        }

        cout << count<<endl;
    }
    return 0;
}