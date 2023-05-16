#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int


void solve()
{
    int a,b; cin >> a >> b;
    int bahar = 1; 

    // if(a%10 == 0)
    // {
    //     cout << 0 << endl;
    //     return;
    // }

    while(b > 0)
    {
        if(b&1) 
        {
            bahar = (a*bahar) % 10;
        }
        
        b = b / 2;
        a = (a * a) % 10;
    }

    cout << bahar << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}