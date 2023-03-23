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
    int n,m;
    cin>>n>>m;

    bool hash = false;

    fo(i,0,n-1)
    {
        fo(j,0,m-1)
        {
            if(i%2 == 0){
                cout << "#";
                continue;
            }
            if(hash == false)
            {
                if(j == m-1) {
                    cout << "#";
                    hash = true;
                }
                else cout << ".";
            }
            else if(hash == true)
            {
                if( j == 0) cout << "#";
                else cout << ".";

                if(j == m-1) hash = false;
            }

        }
        cout << endl;
    }
    return 0;
}