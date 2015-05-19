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
 * Google Code Jam - Google APAC 2015 University Graduates Test - Round C APAC Test Problem A. Minesweeper
 * Type : DFS
 */

const int x[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int y[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool isok(vector<string> &mapmine, int r, int c, int &n) {
    for (int k = 0; k < 8; ++k)
        if (r + x[k] >= 0 && r + x[k] < n && c + y[k] >= 0 && c + y[k] < n && mapmine[r + x[k]][c + y[k]] == '*')
            return false;
    return true;
}

void dfs(vector<string> &mapmine, int r, int c, int &n) {
    for (int k = 0; k < 8; ++k)
        if (r + x[k] >= 0 && r + x[k] < n && c + y[k] >= 0 && c + y[k] < n) {
            if (mapmine[r + x[k]][c + y[k]] == '1')
                continue;
            mapmine[r + x[k]][c + y[k]] = '1';
            if (isok(mapmine, r + x[k], c + y[k], n))
                dfs(mapmine, r + x[k], c + y[k], n);
        }
}

void run() {
    int t, n;
    int cases = 1;
    string str;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<string> mapmine;
        for (int i = 0; i < n; ++i) {
            cin >> str;
            mapmine.push_back(str);
        }
        int cnt = 0;
        // one pass
        for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (mapmine[i][j] == '*' || mapmine[i][j] == '1')
                continue;
            if (isok(mapmine, i, j, n)) {
                mapmine[i][j] = '1';
                dfs(mapmine, i, j, n);
                ++cnt;
            }
        }
        // another pass
        for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (mapmine[i][j] == '.')
                ++cnt;
        }

        cout << "Case #" << cases++ << ": " << cnt << endl;
    }
}

int main() {
    freopen("A-large-practice.in", "r", stdin);
    freopen("result.out", "w", stdout);
	run();

	return 0;
}
