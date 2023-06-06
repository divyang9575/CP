#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	while(t--)
	{
	    int n,k,l; cin >>n >>k >> l;
	    vector<pair<int, int>> song(n);
	    for(int i = 0; i<n; i++)
	        cin >> song[i].first >> song[i].second;
	        
	    int ans = 0;
	    sort(song.begin(), song.end(), greater<>());

        for(auto it : song)
        {
            if(it.second == l && k > 0)
            {
                ans += it.first;
                k--;
            }
        }
        if(ans == 0 || k > 0) cout << -1 << endl;
        else cout << ans << endl;
    }
	    
	return 0;
}
