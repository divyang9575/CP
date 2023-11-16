#include<bits/stdc++.h>
using namespace std;

int solution(vector<int>&A){
    vector<int> mp((1<<10)+10,0);
    unordered_map<int ,int> ex;

    for(int i=0; i<A.size(); i++){
        set<int>s;
        string ss = to_string(A[i]);

        for(auto ch:ss){
            s.insert(ch-'0');
        }

        int mask=0;
        for(auto x:s){
            mask |=(1<<(x+1));
        }

        mp[mask]= max(mp[mask],A[i]);
        ex[mask]++;
    }

    int ans=-1;

    for(int i=0; i<mp.size();i++){
        if(ex.find(i)==ex.end()) continue;

        for(int j=0; j<mp.size();j++){
            if(ex.find(j)==ex.end()) continue;
            if(i&j) continue;
        
            ans = max(ans, mp[i]+mp[j]);
        }
    }
    return ans;
}

int main(){
    int n; cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    cout << solution(A);
}