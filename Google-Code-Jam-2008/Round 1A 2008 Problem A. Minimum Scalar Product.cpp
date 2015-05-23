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
 * Google Code Jam - Google Code Jam 2008 - Round 1A 2008 Problem A. Minimum Scalar Product
 * Type : math
 */

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))

bool cmp(int a, int b) {
    return a > b;
}

void run() {
    int t, n;
    int cases = 1;

    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> A(n, 0), B(n, 0);
        FOR(i, 0, n)
            cin >> A[i];
        FOR(i, 0, n)
            cin >> B[i];
        sort(A.begin(), A.end());
        sort(B.begin(), B.end(), cmp);
        long long sum = 0;
        FOR(i, 0, n)
            sum += A[i] * B[i];
        cout << "Case #" << cases++ << ": " << sum << endl;
    }
}

int main() {
    freopen("A-large-practice.in", "r", stdin);
    freopen("result.out", "w", stdout);
    run();

    return 0;
}

