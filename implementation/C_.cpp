#include <bits/stdc++.h>
using namespace std;

long long mod = 998244353;
long long fac(long long n)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans * i) % mod;
        ans %= mod;
    }
    return ans % mod;
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long count = 0;
        int i = 0, j = 1;
        while (i < s.length() && j < s.length())
        {
            if (s[i] == s[j])
            {
                count++;
                j++;
            }
            else
            {
                i = j;
                j++;
            }
        }


        long long ans = 0;
        i = 0, j = 1;
        long long temp = 1;

        while (i < s.length() && j < s.length())
        {
            if (s[i] == s[j])
            {
                temp++;
                j++;
            }
            else
            {
                if (temp > 1)
                {
                    ans += temp;
                    temp = 1;
                }

                i = j;
                j++;
            }
        }


        if (temp > 1)
        {
            ans += temp ;
            temp = 1;
        }

        cout << count << " " << fac(ans) << endl;

    }

    return 0;
}