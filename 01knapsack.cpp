#include <bits/stdc++.h> 
using namespace std;
 
int main(void)
{
    int n, u;
    cin >> n >> u;

    vector<int> w(n + 1), v(n + 1);

    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    vector<vector<int>> dp(n + 1, vector<int>(u + 1));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= u; j++)
        {
            if(w[i] > j) dp[i][j] = dp[i-1][j];

            else dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i-1][j]);
        }
    }
    cout << dp[n][u] << endl;
}