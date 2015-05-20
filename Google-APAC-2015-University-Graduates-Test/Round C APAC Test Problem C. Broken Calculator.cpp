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
 * Google Code Jam - Google APAC 2015 University Graduates Test - Round C APAC Test Problem C. Broken Calculator
 * Type : DP
 */

const int INF = 1e9;

void run() {
    int t, n;
    int cases = 1;
    cin >> t;
    while (t--) {
        vector<int> used(10, 0);
        for (int i = 0; i < 10; ++i)
            cin >> used[i];
        cin >> n;
        vector<int> cnt(n + 1, INF);
        for (int i = 1; i <= n; ++i) {
            int tmp = i, tmpcnt = 0;
            bool valid = true;
            while (tmp != 0) {
                if (used[tmp % 10] == 0) {
                    valid = false;
                    break;
                }
                ++tmpcnt;
                tmp /= 10;
            }
            if (valid)
                cnt[i] = tmpcnt;
        }
        for (int i = 2; i <= n; ++i) {
            for (int k = 2; k * k <= i; ++k) {
                if (i % k == 0)
                    cnt[i] = min(cnt[i], cnt[k] + cnt[i / k] + 1);
            }
        }

        if (cnt[n] == INF)
            cout << "Case #" << cases++ << ": Impossible" << endl;
        else
            cout << "Case #" << cases++ << ": " << cnt[n] + 1 << endl;
    }
}

int main() {
    freopen("C-large-practice.in", "r", stdin);
    freopen("result.out", "w", stdout);
    run();

    return 0;
}
