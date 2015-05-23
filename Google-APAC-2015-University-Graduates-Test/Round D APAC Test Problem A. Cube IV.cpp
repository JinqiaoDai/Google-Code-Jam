#include <iostream>
#include <map>
#include <fstream>
#include <vector>
using namespace std;

/*
 * Google Code Jam - Google APAC 2015 University Graduates Test - Round D APAC Test - Problem A. Cube IV
 * Type : DFS
 */
 
int x[] = {-1, 0, 1, 0};
int y[] = {0, 1, 0, -1};

int dfs(vector<vector<int> > &maze, vector<vector<int> > &cnt, int r, int c, int &n) {
    if (cnt[r][c] != 0)
        return cnt[r][c];
    int maxcnt = 1;
    for (int i = 0; i < 4; ++i) {
        if (r + x[i] < n && r + x[i] >= 0 && c + y[i] < n && c + y[i] >= 0) {
            if (maze[r + x[i]][c + y[i]] == maze[r][c] + 1)
                maxcnt = max(maxcnt, dfs(maze, cnt, r + x[i], c + y[i], n) + 1);
        }
    }
    return cnt[r][c] = maxcnt;
}

void run() {
    int t, n, cases = 1;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int> > maze(n + 1, vector<int>(n + 1, 0));
        vector<vector<int> > cnt(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> maze[i][j];
        int maxcnt = -1, val = -1;
        for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            dfs(maze, cnt, i, j, n);
            if (maxcnt == cnt[i][j] && val > maze[i][j]) {
                val = maze[i][j];
            } else if (maxcnt < cnt[i][j]) {
                maxcnt = cnt[i][j];
                val = maze[i][j];
            }
        }
        cout << "Case #" << cases++ << ": " << val << " " << maxcnt << endl;
    }
}

int main() {
    freopen("A-large-practice.in", "r", stdin);
    freopen("res.out", "w", stdout);
    run();
    return 0;
}
