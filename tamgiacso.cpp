#include <bits/stdc++.h>
using namespace std;

int a[105][105];
int dp[105][105];
int trace[105][105];

int main() {
   
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];

    dp[1][1] = a[1][1];

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                dp[i][j] = dp[i-1][j] + a[i][j];
                trace[i][j] = 1;
            } else if (j == i) {
                dp[i][j] = dp[i-1][j-1] + a[i][j];
                trace[i][j] = 0;
            } else {
                if (dp[i-1][j-1] > dp[i-1][j]) {
                    dp[i][j] = dp[i-1][j-1] + a[i][j];
                    trace[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + a[i][j];
                    trace[i][j] = 1;
                }
            }
        }
    }

    int best = dp[n][1], col = 1;
    for (int j = 2; j <= n; j++) {
        if (dp[n][j] > best) {
            best = dp[n][j];
            col = j;
        }
    }

    cout << best << '\n';

    vector<pair<int,int>> path;
    int i = n, j = col;

    while (i >= 1) {
        path.push_back({i, j});
        if (i == 1) break;
        if (trace[i][j] == 0) j = j - 1;
        i--;
    }

    reverse(path.begin(), path.end());
    for (auto &p : path)
        cout << p.first << " " << p.second << '\n';

    return 0;
}
