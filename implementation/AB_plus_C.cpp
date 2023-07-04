#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main() {
	// your code goes here
	int t; cin >> t;
	while(t--)
	{
	    int x; cin >> x;
	    if(x == 1) cout << -1 << endl;
	    else{
            int m = 1000000;
	        if(x <= m)
	        {
	            cout << x << " " << x-1 << " " << 1 << endl;
	        }
	        else if(x%m != 0){
	            cout << m << " " << x/m << " " << x%m << endl;
	        }
            else{
                cout << m-1 << " " << x/(m) << " " << x/(m) << endl;
            }
	    }
	}
	return 0;
}
