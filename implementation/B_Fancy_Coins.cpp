#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
 
void solve() {
    int m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    
    int t = max(0, min(m / k, (m - a1 + k - 1) / k));
    int ans = max(0, t - ak) + max(0, m - t * k - a1);
    
    std::cout << ans << "\n";
}
 
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}