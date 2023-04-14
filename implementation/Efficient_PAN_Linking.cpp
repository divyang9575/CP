#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	while(t--)
	{
	    string n;
	    cin >> n;
	    
	    int len = n.length();
	    
	    string s = "";
	    
        if(len > 1){
            s += n[len-2];
            s += n[len-1];
        }
        else{
            s+= n[len-1];
        }
	    // cout  << s << endl;
	    int num = stoi(s);
	    // cout << num << endl;
	    int ans = num%20;
	    
	    cout << ans << endl;
    }
	    return 0;
}
