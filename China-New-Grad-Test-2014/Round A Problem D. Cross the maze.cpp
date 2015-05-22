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
 * Google Code Jam - China New Grad Test 2014 - Round A Problem D. Cross the maze
 * Type : search
 */

int x[] = {-1, 0, 1, 0};
int y[] = {0, 1, 0, -1};
string dir[] = {"N", "E", "S", "W"};

void run() {
    int t, n;
    int cases = 1;

    cin >> t;
    while (t--) {
        int stx, sty, edx, edy, tmpdir, tmpx, tmpy;
        int cnt = 0;
        bool moveok = true;
        string res;

        cin >> n;
        vector<string> maze(n);
        for (int i = 0; i < n; ++i)
            cin >> maze[i];
        cin >> stx >> sty >> edx >> edy;
        stx--, sty--, edx--, edy--;
        if (sty == edx && sty == edy) {
            cout << "Case #" << cases++ << ": 0" << endl;
            continue;
        }
        tmpdir = (stx == 0) ? 0 : 2;
        tmpx  = stx, tmpy = sty;
        while (true) {
            int pnextx, pnexty;
            bool ok = false;
            for (int i = tmpdir; i < tmpdir + 4; ++i) {
                pnextx = tmpx + x[i % 4];
                pnexty = tmpy + y[i % 4];
                if (pnextx < 0 || pnextx == n || pnexty < 0 || pnexty == n || maze[pnextx][pnexty] == '#')
                    continue;
                tmpx = pnextx;
                tmpy = pnexty;
                tmpdir = (i - 1 + 4) % 4;
                ok = true;
                break;
            }
            if (!ok || (++cnt > 10000)) {
                moveok = false;
                break;
            }
            res += dir[(tmpdir + 1) % 4];
            if (tmpx == edx && tmpy == edy)
                break;
        }
        if (!moveok)
            cout << "Case #" << cases++ << ": Edison ran out of energy." << endl;
        else {
            cout << "Case #" << cases++ << ": " << res.size() << endl;
            cout << res << endl;
        }
    }
}

int main() {
    freopen("D-large-practice.in", "r", stdin);
    freopen("result.out", "w", stdout);
    run();

    return 0;
}
