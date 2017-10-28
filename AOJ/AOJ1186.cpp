#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define debug(x) cout << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

const int INF = 1e9;
const ll LINF = 1e16;

/* -----  2017/10/28  Problem: ICPC2013国内予選 A / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1186  ----- */
/* ------問題------

整長方形
高さhと幅wがともに整数である長方形を考えよう．そのような長方形を整長方形と呼ぶ．以下，この問題では横長の整長方形，すなわち w > h である整長方形のみを考える．
横長整長方形の大小関係を次のように定めよう．
対角線の長さが短いほうが小さい．
対角線の長さが同じならば，高さの低いほうが小さい．
与えられた横長整長方形に対し，それより大きい最小の横長整長方形を求めよ．

Input

-----問題ここまで----- */
/* -----解説等-----

kim
全探索ｂ

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (1) {
		int h, w;
		cin >> h >> w;
		if (h == 0 && w == 0) break;
		int base = h*h + w*w;

		pii ans_pair;
		int Min = INF;

		for (int i = 1; i < 150; i++) {
			for (int j = i + 1; j < 150; j++) {
				if (i*i + j*j > base) {


					if (Min > i*i + j*j - base) {
						Min = i*i + j*j - base;
						ans_pair.first = i;
						ans_pair.second = j;
					}
				}
				if (i * i + j*j == base) {
					if (i*i + j*j == base) {
						if (i > h && Min != -1) {
							ans_pair.first = i;
							ans_pair.second = j;
							Min = -1;
						}
					}
				}
			}
		}

		cout << ans_pair.first << " " << ans_pair.second << endl;

	}

	return 0;
}
