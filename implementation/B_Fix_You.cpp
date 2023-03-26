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
        int n ,m;
        cin >> n >> m;

        string str[n];
        for(int i = 0; i<n ; i++)
        {
            cin >> str[i];   
        }

        int lastdown = n-1;
        int rightmost = m-1;

        int count = 0;

        for(int i=0; i<n ; i++)
        {
            if(str[i][rightmost] == 'R')
            {
                str[i][rightmost] = 'D';
                count++;
            }
            if(i == n-1)
            {
                for(int j=0; j<m; j++)
                {
                    if(str[i][j] == 'D')
                    {
                        str[i][j] = 'R';
                        count++;
                    }
                }
            }
        }
        cout << count<< endl;
    }
    return 0;
}