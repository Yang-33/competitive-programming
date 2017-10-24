#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

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
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/10/18  Problem: 20_e  / Link: http://joi2009ho.contest.atcoder.jp/tasks/joi2009ho_e  ----- */
/* ------問題------

あなたは Just Odd Inventions 社を知っているだろうか? この会社の業務は「ただ奇
妙な発明 (just odd inventions)」をすることである．ここでは略して JOI 社と呼ぶ．
JOI 社には 2 つの事務所があり，それぞれ同じ大きさの正方形の部屋がマス目状に
並んでできている．辺で接しているすべての部屋の間に，身分証による認証機能の
付いた扉がある．JOI 社では様々なレベルの機密情報を扱っているため，部屋ごとに
機密レベルという正の整数が設定されており，身分証の事務所ごとに定められた非
負整数の認証レベルが，機密レベル以上でないとその部屋に入室することができな
い．各事務所の出入り口は唯一あるエレベーターホールのみで，エレベーターホー
ルの部屋の機密レベルは最低の 1 である．その事務所についての認証レベルが 0 の
ときはエレベーターホールに入ることさえできない．
JOI 社では，社長の突発的な提案で，一般の人に社内を見学してもらうツアーを実
施することになった．あなたは見学者に渡す身分証の認証レベルの組み合わせを決
める必要がある．見学者は開けられる扉を見つけると必ず開けて中に入る (同じ部屋
を何度も訪れることも可能である)．そのため，必要以上に見学者の身分証の認証レ
ベルを高くしたくはない．しかし，ツアーに魅力を持たせるため，ツアーではエレ
ベーターホールの部屋を含め 2 つの事務所であわせて R 個以上の部屋を訪れること
ができるようにする必要がある．身分証の認証レベルを低くしすぎると，この条件
を満たすことができないかもしれない．
JOI 社には事務所が 2 個あり，第 k 事務所 (k = 1, 2) の部屋は東西方向に Wk 個，南
北方向に Hk 個並んでおり，全部で Wk × Hk 個ある．西から i 番目，北から j 番目の
部屋を (i, j)k で表すことにする．
Wk と Hk と R の値，エレベーターホールの位置 (Xk
, Yk)k ，各部屋の機密レベルが
与えられたとき，見学者が 2 つの事務所であわせて R 個以上の部屋を訪れることが
できるための，見学者の身分証の認証レベルの和の最小値を求めるプログラムを作
成せよ．
なお，JOI 社が「ただ奇妙な発明」をすることでどうやって利益を得ているかは，
社内でも最高機密であり社長以外の誰も知らない．

-----問題ここまで----- */
/* -----解説等-----

二分探索は片側しか無理
三分探索の中身が二分探索？
訪問数がR-2以上になるようなa1,a2の組を二分探索
うそ

なんか常に共通なので、
これを上手に持ってくる？

解法：許容レベルを緩和していくことを考える。
このとき毎回二分探索を行うのも無駄で、緩和したときに周囲4マス(正確には前の緩和点と連結なので3)
をチェックしていけばよい。これはpriorityQueueなどで簡単に管理ができるので、
やります
そうすることで緩和レベルの数列が二つできるので、
あとは半分全列挙みたいなノリをつきつければ最小値をとることができる。

----解説ここまで---- */

LL R, N;
LL W[2], H[2];
LL X[2], Y[2];
LL ans = 0LL;
int masu[2][501][501];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> R;
	FOR(i, 0, 2) {
		cin >> W[i] >> H[i] >> X[i] >> Y[i];
		X[i]--, Y[i]--;
		FOR(h, 0, H[i]) {
			FOR(w, 0, W[i]) {
				cin >> masu[i][h][w];
			}
		}
	}
	using tp = tuple<LL, PLL>;
	priority_queue<tp, vector<tp>, greater<tp>>q[2];
	VL v[2];
	VVI used[2];
	FOR(i, 0, 2)used[i] = VVI(501, VI(501, 0));

	FOR(i, 0, 2)q[i].push(tp(1, PLL(Y[i], X[i]))),used[i][Y[i]][X[i]]=1;

	FOR(i, 0, 2) {
		while (!q[i].empty()) {
			int r, y, x; PLL a;
			tie(r, a) = q[i].top(); q[i].pop();
			y = a.first, x = a.second;
			v[i].push_back(r);

			FOR(k, 0, 4) {
				int nx, ny; ny = y + DY[k]; nx = x + DX[k];
				if (nx < 0 || nx >= W[i] || ny < 0 || ny >= H[i])continue;
				if (used[i][ny][nx] == 0) {
					q[i].push(tp(masu[i][ny][nx], PLL(ny, nx)));
					used[i][ny][nx] = 1;
				}
			}
			while(!q[i].empty()) {//rで緩和したあと
				int rr, yy, xx; PLL aa;
				tie(rr, aa) = q[i].top(); //q[i].pop();
				yy = aa.first; xx = aa.second;
				if (rr <= r) {
					q[i].pop();
					v[i].push_back(r);
					FOR(kk, 0, 4) {
						int nx, ny; ny = yy + DY[kk]; nx = xx + DX[kk];
						if (nx < 0 || nx >= W[i] || ny < 0 || ny >= H[i])continue;
						if (used[i][ny][nx] == 0) {
							q[i].push(tp(masu[i][ny][nx], PLL(ny, nx)));
							used[i][ny][nx] = 1;
						}
					}

				}
				else break;
			}
		}
		/*FOR(k, 0, SZ(v[i])) {
			cout << v[i][k] << " ";
		}cout << endl;*/
	}
	ans = LINF;
	FOR(i, 0, min((int)R,SZ(v[0]))) {//R個以上になるものの列挙＆チェック
		LL num = v[0][i];//i+1個
		int want = R - (i + 1);
		//cout << num << " " << want << endl;
		if (SZ(v[1])>=want&&want >= 1) {
			LL num2 = v[1][want - 1];
			ans = min(ans, num + num2);
		}
		else if(want==0){
			ans = min(ans, num);
		}
	}


	cout << ans << "\n";

	return 0;
}