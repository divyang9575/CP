#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	while(t--)
	{
	    int  n; cin >> n;
        
        int maxbit = log2(n);
	    
	    cout << max((int)pow(2, maxbit-1), n - (int)pow(2, maxbit) + 1) << endl;
	}
	return 0;
}
