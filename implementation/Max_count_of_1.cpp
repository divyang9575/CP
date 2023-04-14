#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int size; cin>>size;

	    string s; cin>>s;

	    string x1="0";
	    int count1 = 0;

	    string x2="1";
	    int count2 = 1;
	    
	    for(int i=1;i<s.length();i++)
        {
	        int a = s[i-1]-'0';
	        int b = x1[i-1]-'0';
	        int c = a^b;

	        if(c==1) count1++;
	        x1 += to_string(c);
	        
	        b = x2[i-1]-'0';
	        c = a^b;

	        if(c==1) count2++;
	        x2 += to_string(c);
	    }
	    
	    cout << max(count1,count2) << endl;
	    
	}
	return 0;
}