#include <iostream>
#include <map>
#include <fstream>
#include <vector>
using namespace std;

/*
 * Google Code Jam - Google APAC 2015 University Graduates Test - Round D APAC Test - Problem B. GBus count
 * Type : Coding
 */
 
void run() {
    int t, n, p, x, cases = 1;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> bus(n * 2, 0);
        for (int i = 0; i < n; ++i) {
            cin >> bus[i * 2] >> bus[i * 2 + 1];
        }
        cout << "Case #" << cases++ << ": ";
        cin >> p;
        for (int i = 0; i < p; ++i) {
            cin >> x;
            int cnt = 0;
            for (int k = 0; k < n; ++k) {
                if (bus[k * 2] <= x && bus[k * 2 + 1] >= x)
                    ++cnt;
            }
            cout << " " << cnt;
        }
        cout << endl;
    }
}

int main() {
    freopen("B-large-practice.in", "r", stdin);
    freopen("res.out", "w", stdout);
    run();
    return 0;
}
