#include <bits/stdc++.h>
using namespace std;


#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/12/14  Problem: neerc_regional_2016_a / Link: __CONTEST_URL__  ----- */
/* ------問題------

大文字は略語にできれば略語にする問題

-----問題ここまで----- */
/* -----解説等-----

引退
連続するかをかくにんすればよい

----解説ここまで---- */

bool iskugiri(char c) {
	return (c == ' ' || c == '.' || c == ',');
}
bool check(string &s) {
	int f = 0;
	FOR(i, 0, SZ(s)) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			if (i == 0)f = 1;
			else f = 2;
		}
	}
	return f == 1;
}

int main() {

	freopen("abbreviation.in", "r", stdin);
	freopen("abbreviation.out", "w", stdout);

	string ss;
	while (getline(cin, ss)) {
		//ss += string(1, '\n');
		vector<string>vs;
		string t = "";
		FOR(i, 0, SZ(ss)) {
			if (iskugiri(ss[i])) {
				if (t.size() > 0)vs.push_back(t);
				t = "";
				string a = string(1, ss[i]);
				vs.push_back(a);
			}
			else {
				t += string(1, ss[i]);
			}
		}
		if (t.size() > 0)vs.push_back(t);
		int  N = SZ(vs);
		vector<int>ryaku(N, 0);

		FOR(i, 0, N) {
			int cnt = 0;
			while (i < N&&check(vs[i]) && vs[i].size() > 1) {
				ryaku[i] = ++cnt;
				i += 2;
			}
		}

		FOR(i, 0, N) {
			if (ryaku[i] > 0) {
				int j;
				string s;
				s += string(1, vs[i][0]);
				int f = 0;
				for (j = i + 1; j < N; j++) {
					if (vs[j][0] == ' ') {
						if (f > 0)break;
						f ++;
					}
					else if (iskugiri(vs[j][0])) {
						break;
					}
					else {
						if (ryaku[j] <= 1)break;
						else s += string(1, vs[j][0]), f = 0;;
					}
				}if (s.size() > 1) {
					cout << s << " (";
				}
				for (int k =i; k < i+SZ(s)*2 - 1; k++) {
					cout << vs[k];
				}
				i = i + SZ(s) * 2 - 1 - 1;;
				if (s.size() > 1) {
					cout << ")";
				}

			}
			else {
				cout << vs[i];
			}
		}

		cout << endl;
	}

	return 0;
}
