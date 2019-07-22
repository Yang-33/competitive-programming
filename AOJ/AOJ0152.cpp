#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/07/23  Problem: AOJ 0152 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0152  ----- */


stringstream deletecommma(string line) {
	istringstream ss(line);
	string s;
	stringstream input;
	while (getline(ss, s, ' ')) {
		input << s; input << " ";
	}
	return input;
}

int main() {
	int M;
	while (cin >> M, M) {
		auto scoref = [](const VI &a) {
			int len = SZ(a);
			int score = 0, sum = 0;
			int p = 0, n = 0;

			FOR(i, 0, len) {
				if (p >= 9) {
					p++;
					score += a[i];
				}
				else {
					if (a[i] == 10 && n == 0) {
						score += a[i] + a[i + 1] + a[i + 2];
						p++;
					}
					else {
						n++;
						sum += a[i];
						if (n == 2) {
							n = 0;
							score += sum;
							if (sum == 10) {
								score += a[i + 1];
							}
							p++;
							sum = 0;
						}
					}
				}
			}
			return score;
		};
		vector<PII>a;
		FOR(i, 0, M) {
			int id; cin >> id;
			string in; getline(cin, in);
			VI seq; {
				auto input = deletecommma(in);
				int num;
				while (input >> num) {
					seq.emplace_back(num);
				}
			}
			a.emplace_back(scoref(seq), id);
		}
		sort(ALL(a), [](const PII& L, const PII& R) {
			if (L.first == R.first)return L.second < R.second;
			else return L.first > R.first;
		});
		for (auto it : a) {
			cout << it.second << " " << it.first << "\n";
		}
	}
}