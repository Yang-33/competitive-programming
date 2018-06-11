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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/06/11  Problem: AOJ 2232 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2232  ----- */
/* ------問題------

縁日に来たうさぎが, ある出店のゲームの景品がキャロットケーキであるのを見つけた. このゲームのルールは以下の通りである.

縦h マス× 横w マスの格子状のフィールドがあり, 各マスにつき高々1 個のブロックが置かれる. 各ブロックにはアルファベット大文字(‘A’ - ‘Z’) のいずれかで表される色がついている. 同色のブロックが縦または横に一直線上にn 個以上連続して並ぶと, それらのブロックは消滅する.

参加者は横に隣り合う2 つのマスを選んで, それらの状態を互いに入れ替える操作ができる. ブロックの入れ替え, 消滅, 落下によってブロックの有るマスの1 つ下のマスにブロックが無くなると, このブロックは落下する. このときふたたび同色のブロックがn 個以上並ぶと消滅する. ただし, ブロックの消滅は, 落下するブロックが存在する間は起こらず, すべてのブロックの落下が終了したタイミングで同時に起こる.

1 回の操作でフィールド上のすべてのブロックを消滅させると, このゲームは成功となり景品のケーキを得ることができる. うさぎは1 回分の参加費で確実にケーキを手に入れたく, それができない場合は参加したくない. ゲーム開始時のフィールドの状態から, うさぎがこのゲームに参加すべきであるか答えよ.

-----問題ここまで----- */
/* -----解説等-----

やるしかないので書く

----解説ここまで---- */

void fall(vector<string>& vs) { // swapして落ちるときもあるわね
	int H = SZ(vs); int W = SZ(vs[0]);
	FOR(j, 0, W) {
		for (int i = H - 1; i >= 0; i--) {
			if (vs[i][j] == '.') {
				for (int k = i - 1; k >= 0; k--) {
					if (vs[k][j] != '.') {
						swap(vs[k][j], vs[i][j]);
						break;
					}
				}
			}
		}
	}
}

// うんちなので消す
int unchi(vector<string>& vs, int N) {
	int H = SZ(vs); int W = SZ(vs[0]);
	vector<vector<int>>check(H, vector<int>(W, 0));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (vs[i][j] == '.')continue;
			{// 右
				int cnt = 1;
				FOR(k, j + 1, W) {
					if (vs[i][k] == vs[i][j])cnt++;
					else break;
				}
				if (cnt >= N) {
					FOR(k, j, W) {
						if (vs[i][k] == vs[i][j])check[i][k] = 1;
						else break;
					}
				}
			}
			{// 下
				int cnt = 1;
				FOR(k, i + 1, H) {
					if (vs[k][j] == vs[i][j])cnt++;
					else break;
				}
				if (cnt >= N) {
					FOR(k, i, H) {
						if (vs[k][j] == vs[i][j])check[k][j] = 1;
						else break;
					}
				}
			}
		}
	}

	// check を消す
	int UNCHI = 0;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (check[i][j])vs[i][j] = '.', UNCHI = 1;
		}
	}
	return UNCHI;
}

// 全部消えるか
int simi(vector<string> vs, int N) {
	int H = SZ(vs); int W = SZ(vs[0]);

	int update = 1;
	while (update) {
		update = 0;
		fall(vs);
		update |= unchi(vs, N);
		fall(vs);
	}

	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (vs[i][j] != '.')return 0;
		}
	}
	return 1;
}

// swapを全部シュミレーションする
void solve() {
	int W, H, N;
	cin >> H >> W >> N;
	vector<string>vs(H);
	FOR(i, 0, H) {
		cin >> vs[i];
	}
	int flag = 0;
	FOR(i, 0, H) {
		FOR(j, 0, W - 1) {
			swap(vs[i][j], vs[i][j + 1]);
			flag |= simi(vs, N);
			swap(vs[i][j], vs[i][j + 1]);
		}
	}
	cout << (flag ? "YES" : "NO") << endl;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();
	return 0;
}