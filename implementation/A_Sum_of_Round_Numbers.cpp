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

void printv(vi v){
    for(int i = 0; i<v.size(); i++){
        cout << v[i] << " ";
    }
}
int main()
{fast
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;

        vi ans;

        int factor = 1;
        while(n){

            int rem = n%10;

            if(rem != 0) ans.pb(rem*factor);

            n = n/10;

            factor = 10*factor;
        }

        cout << ans.size() << endl;
        printv(ans) ;
        cout << endl;
    }
    return 0;
}