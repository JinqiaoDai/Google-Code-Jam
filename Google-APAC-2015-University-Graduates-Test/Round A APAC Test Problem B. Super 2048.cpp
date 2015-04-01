#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

ifstream fin("B-small-practice.in");
ofstream fout("res.txt");

/*
 * Google Code Jam - Google APAC 2015 University Graduates Test - Round A APAC Test - Problem B. Super 2048
 * Type : Coding
 */
void run() {
	int t, n, number = 1;
	string dir;
	fin >> t;
	while (t--) {
		fin >> n >> dir;
		vector<vector<int> > vvdata(n, vector<int>(n, 0)), vvres(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			fin >> vvdata[i][j];
		int s = 0, e = n;
		if (dir == "down" || dir == "right") {
			s = n - 1;
			e = -1;
		}
		for (int j = 0; j < n; ++j) {
			int cnt = 0;
			for (int i = s; i != e;) {
				if (dir == "up" || dir == "down") {
					while (i != e && vvdata[i][j] == 0)
						(i < e) ? ++i : --i;
				} else {
					while (i != e && vvdata[j][i] == 0)
						(i < e) ? ++i : --i;
				}
				if (i == e)
					break;
				int next = (i < e) ? i + 1 : i - 1;
				if (dir == "up" || dir == "down") {
					while (next != e && vvdata[next][j] == 0)
						(next < e) ? ++next : --next;
				} else {
					while (next != e && vvdata[j][next] == 0)
						(next < e) ? ++next : --next;
				}
				if (dir == "up" || dir == "down") {
					if (next != e && vvdata[i][j] == vvdata[next][j]) {
						if (dir == "up")
							vvres[cnt++][j] = vvdata[i][j] * 2;
						else
							vvres[n - 1 - cnt++][j] = vvdata[i][j] * 2;
						i = (next < e) ? next + 1 : next - 1;
					} else {
						if (dir == "up")
							vvres[cnt++][j] = vvdata[i][j];
						else
							vvres[n - 1 - cnt++][j] = vvdata[i][j];
						i = next;
					}
				} else {
					if (next != e && vvdata[j][i] == vvdata[j][next]) {
						if (dir == "left")
							vvres[j][cnt++] = vvdata[j][i] * 2;
						else
							vvres[j][n - 1 - cnt++] = vvdata[j][i] * 2;
						i = (next < e) ? next + 1 : next - 1;
					} else {
						if (dir == "left")
							vvres[j][cnt++] = vvdata[j][i];
						else
							vvres[j][n - 1 - cnt++] = vvdata[j][i];
						i = next;
					}
				}
			}
		}
		fout << "Case #" << number++ << ":" << endl;
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			fout << vvres[i][j];
			if (j == n - 1)
				fout << endl;
			else
				fout << " ";
		}
	}
}

int main() {
	run();
	return 0;
}
