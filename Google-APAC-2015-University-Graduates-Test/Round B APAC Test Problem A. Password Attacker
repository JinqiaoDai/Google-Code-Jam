#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

/*
 * Google Code Jam - Google APAC 2015 University Graduates Test - Round B APAC Test Problem A. Password Attacker
 * Type : DP
 */

const long long INF = 1000000007;

void combinations(vector<vector<int> > &comb) {
    for (int n = 1; n < 101; ++n)
    for (int m = 1; m < n; ++m) {
        comb[n][m] = (comb[n - 1][m] + comb[n - 1][m - 1]) % INF;
    }
}

void run(vector<vector<int> > &comb) {
    string str;
    int t, m, n, cases = 1;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        vector<vector<long long> > res(n + 1, vector<long long>(m + 1, 0));
        for (int i = 1; i <= n; ++i)
            res[i][1] = 1;
        for (int i = 2; i <= m; ++i)
        for (int j = i; j <= n; ++j) {
            for (int k = 1; k <= j - i + 1; ++k) {
                res[j][i] = (res[j][i] + (res[j - k][i - 1] * comb[j][k]) % INF) % INF;
            }
        }
        cout << "Case #" << cases++ << ": " << res[n][m] << endl;
    }
}

int main() {
    freopen("A-large-practice.in", "r", stdin);
    freopen("A-large-practice.out", "w", stdout);
    vector<vector<int> > comb(101, vector<int>(101, 1));
    combinations(comb);
	run(comb);
	return 0;
}
