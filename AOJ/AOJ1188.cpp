#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define debug(x) cout << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

const int INF = 1e9;
const ll LINF = 1e16;

/* -----  2017/10/28  Problem: ICPC2013国内予選 C / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1188  ----- */
/* ------問題------

階層民主主義
デモクラティア共和国の大統領は，以下のような複数段階の選挙により選ばれる．
大統領選挙の候補者は2名である．
第1段階の選挙では，有権者は選挙区ごとに投票する．有権者の過半数の票を得た候補者がその選挙区の勝者となる．有権者が投票するのはこの第1段階だけである．
第k段階 (k > 1) の選挙区は，複数の第k − 1段階の選挙区を含む．一方，第k − 1段階の各選挙区は，ちょうど一つの第k段階の選挙区に含まれる．そして，第k段階の選挙区の勝者は，この選挙区に含まれる第k − 1段階の選挙区のうち過半数で勝った候補者である．
最終段階の選挙区は全国区であり一つしかない．ここでの勝者が大統領に選ばれる．
この国の大統領選挙では，以下の仮定が成り立つ．
すべての有権者が，それぞれ一票を投じる．
第1段階の各選挙区の有権者数は奇数である．
第k段階 (k >1) の各選挙区に含まれる第k − 1段階の選挙区の数も奇数である．
したがって，すべての段階のすべての選挙区で，必ずどちらかの候補が勝つ (引き分けはない)．
あなたの仕事は，なるべく少ない得票数で大統領選挙に勝つ方法を求めるプログラムを作成することである． たとえば，最終段階の選挙区がちょうど三つの第1段階の選挙区を含んでおり，これらの第1段階の選挙区の有権者数がそれぞれ123名，4567名，89名だったとする． この場合，最初の選挙区で62票，3番目の選挙区で45票の計107票を獲得するのが，最も少ない得票数で勝つ方法になる． この場合，仮にもう一人の候補が2番目の選挙区で4567票すべてを獲得したとしても，敗者となることは避けられない． 不公平な選挙制度だと思うかもしれないが，これも現実として受け止めて欲しい．

-----問題ここまで----- */
/* -----解説等-----

kim.
実装ゲ—。頑張る。
過半数の票になるように最小の方をとればよい。

----解説ここまで---- */

ll getnum(int& j, string& S) {
	ll num = 0;
	while (S[j] >= '0' && S[j] <= '9') {
		num *= 10;
		num += S[j] - '0';
		j++;
	}
	return num;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		string S; cin >> S;
		string T_S, TT_S;
		vector<ll> v;
		vector<ll> vv;
		bool f = false;

		while (1) {
			for (int j = 0; j < S.size(); j++) {
				if (S[j] == '[') {
					if (S[j + 1] >= '0' && S[j + 1] <= '9') {
						v.clear();
						j++;
						for (; j < S.size(); j++) {
							v.push_back(getnum(j, S));
							if (S[j + 1] == '[') {
								j++; continue;
							}
							else {
								break;
							}
						}

						sort(v.begin(), v.end());
						if (!f) {
							int sum = 0;
							for (int k = 0; k < v.size() / 2 + 1; k++) {
								sum += (v[k] + 1) / 2;
							}
							vv.push_back(sum);
							T_S += to_string(sum);
							continue;
						}
						else {
							int sum = 0;
							for (int k = 0; k < v.size() / 2 + 1; k++) {
								sum += v[k];
							}
							vv.push_back(sum);
							T_S += to_string(sum);
							continue;
						}
					}
				}
				TT_S += S[j];
				T_S += S[j];
			}

			if (!f) f = true;

			if (TT_S.size() == 2) {
				/*
				cout << T_S << endl;
				cout << TT_S << endl;
				*/
				cout << vv[0] << endl;
				break;
			}
			S = T_S;
			vv.clear();
			T_S.clear();
			TT_S.clear();
		}
		/*
		cout << T_S << endl;
		for (auto o : vv) {
			cout << o << " ";
		}
		cout << endl;
		*/
	}


	return 0;
}