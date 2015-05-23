#include <iostream>
#include <map>
#include <fstream>
#include <vector>
using namespace std;

/*
 * Google Code Jam - Google APAC 2015 University Graduates Test - Round D APAC Test - Problem C. Sort a scrambled itinerary
 * Type : Coding
 */
 
void run() {
    int t, n, p, x, cases = 1;
    cin >> t;

    while (t--) {
        cin >> n;
        string st, ed;
        map<string, int> mpcnt;
        map<string, string> mpkv;
        for (int i = 0; i < n; ++i) {
            cin >> st >> ed;
            mpcnt[st] = mpcnt[st] + 1;
            mpcnt[ed] = mpcnt[ed] + 1;
            mpkv[st] = ed;
        }
        cout << "Case #" << cases++ << ":";
        for (map<string, int>::iterator it = mpcnt.begin(); it != mpcnt.end(); ++it) {
            if (mpcnt[it->first] == 1 && mpkv.find(it->first) != mpkv.end()) {
                string tmpkey = it->first;
                while (mpkv.find(tmpkey) != mpkv.end()) {
                    cout << " " << tmpkey << "-" << mpkv[tmpkey];
                    tmpkey = mpkv[tmpkey];
                }
                cout << endl;
                break;
            }
        }
    }
}

int main() {
    freopen("C-large-practice.in", "r", stdin);
    freopen("res.out", "w", stdout);
    run();
    return 0;
}
