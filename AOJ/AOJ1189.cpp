#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define debug(x) cout << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

const int INF = 1e9;
const ll LINF = 1e16;

/* -----  2017/10/28  Problem: ICPC2013国内予選 D / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1189  ----- */
/* ------問題------

素数洞穴
砂漠の中の巨大な崖の中腹に，石窟寺院が残されているのを国際調査隊が発見しました．垂直にそびえ立つ崖のちょうど真ん中あたりに，
無数の洞穴が縦横にきれいに並んでおり，それぞれの中に仏像が残されていたのです．
さらにすごいことに，いくつかの洞穴には仏教の教典が隠されていました．千年以上も前に書かれたと見られる教典の価値は，それこそ計り知れません．
調査隊の隊長は，できるだけ多くの教典を持ち帰ることを決めました．ただ，洞穴は崖の中ほどにあるため，簡単には入れません．
唯一の方法は，あなたの体をヘリコプターで吊るして1つの洞穴に入って調査をし，その洞穴から縄を使ってすぐ下にある3つの洞穴(直下の洞穴か，直下の洞穴の右または左に隣り合う洞穴)のどれかに降りるということを繰り返して降りてくるというものです．最後の洞穴からは長い縄を使って地面に降りることができます．
一度に何個かの洞穴を調査できるとは言うものの，どの洞穴を調査すればよいのでしょうか?
そんな折，数学者のメンバーが予備調査の結果から教典が隠された洞穴にはある規則性があることを見つけました．
彼によれば(1)洞穴には，中央のものに1番，そこから図D-1のように外向きに渦を巻くように番号を付けると，
(2)教典が隠されているのは図中丸で囲まれているような素数番目の洞穴(以降素数洞穴と呼びます)に他ならない，というのです．
次回からはあなたが最初の洞穴に入ったら，素数洞穴を最も多く調査するように降りてくることができるでしょう．

-----問題ここまで----- */
/* -----解説等-----

ぐるぐるしている部分は１を中心に「右、上、左、下」の動きを繰り返す。
その過程で1,1,2,2,3,3,4,4,と二回値を加算するとカウンタが一増える。
これによって盤面を作成可能。
また、これが素数のとき、印をつけておき(prime)、加えて探索開始地点にも印をつける(=0)。
あとは探索地点からｄｐをして下っていき、最大値を持つ中での最大の素数をもう一度探索すればよい。
masu[][]の未使用点を-1で設定していたのにも関わらず、prime[masu[][]]をしてバグらせたり、
探索開始位置がn=1のときの判定を書いていなかったりしてバグを量産してしまい、
実行前に自分でコーナーをチェックする癖をもう一度確認しないといけないと思った。
dp + 全探索 でOK

----解説ここまで---- */

bool prime[1000010];

void Prime_init() {
	prime[0] = 0;
	prime[1] = 0;

	prime[2] = true;

	for (int i = 3; i < 1000010; i += 2) {
		bool f = false;
		for (int j = 3; j*j <= i; j += 2) {
			if (i%j == 0) {
				f = true;
				break;
			}
		}
		if (!f) {
			prime[i] = true;
		}
	}
}
int masu[4000][4000];
int dp[4000][4000];
int makemasu(int m, int n) {
	bool up = 1;
	bool right = 1;
	bool f = 0;
	int cnt = 1;
	int X = 2000;
	int Y = 2000;
	int nextp = 1;
	masu[Y][X] = cnt;
	if (n == cnt)dp[Y][X] = 0;
	cnt++;
	for (;;) {
		if (f == 0) {
			if (right == 1) {
				FOR(i, 0, nextp) {
					if (cnt > m)return 0;
					masu[Y][X + 1] = cnt;
					if (cnt == n) {
						dp[Y][X + 1] = 0;
						if (prime[cnt] == 1)dp[Y][X + 1] = 1;
					}
					X++;
					cnt++;
				}
				right = !right;
				f = !f;
			}
			else {
				FOR(i, 0, nextp) {
					if (cnt > m)return 0;

					masu[Y][X - 1] = cnt;
					if (cnt == n) {
						dp[Y][X - 1] = 0;
						if (prime[cnt] == 1)dp[Y][X - 1] = 1;
					}
					X--;
					cnt++;
				}
				right = !right;
				f = !f;

			}
		}
		else {
			if (up == 1) {
				FOR(i, 0, nextp) {
					if (cnt > m)return 0;

					masu[Y - 1][X] = cnt;
					if (cnt == n) {
						dp[Y - 1][X] = 0;
						if (prime[cnt] == 1)dp[Y - 1][X] = 1;
					}
					cnt++;
					Y--;
				}
				up = !up;
				nextp++;
				f = !f;

			}
			else {
				FOR(i, 0, nextp) {
					if (cnt > m)return 0;

					masu[Y + 1][X] = cnt;
					if (cnt == n) {
						dp[Y + 1][X] = 0;
						if (prime[cnt] == 1)dp[Y + 1][X] = 1;
					}
					cnt++;
					Y++;
				}
				up = !up;
				nextp++;
				f = !f;

			}
		}
	}

}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	Prime_init();

	while (1) {
		int n, m;
		cin >> m >> n;
		if (n == 0 && m == 0)break;
		FOR(i, 0, 4000)FOR(j, 0, 4000)masu[i][j] = -1, dp[i][j] = -10000;
		makemasu(m, n);


		

		FOR(i, 0, 4000) {
			FOR(j, 0, 4000) {
				if (masu[i][j] == -1)continue;
				FOR(k, -1, 2) {
					int pp = 0;
					if (j + k >= 0 && j + k < 4000) {
						if (masu[i + 1][j + k] == -1)continue;
						if (prime[masu[i + 1][j + k]] == 1)pp = 1;
						dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + pp);
					}
				}

			}
		}


		int ans = -1;
		int ansb = 1;
		FOR(i, 0, 4000) {
			FOR(j, 0, 4000) {
				if (dp[i][j] > ans)ansb = masu[i][j];

				if (dp[i][j] >= ans) {
					ans = dp[i][j];
					if (masu[i][j] != -1)
						if (prime[masu[i][j]])
							ansb = max(ansb, masu[i][j]);
				}

			}
		}
		if (ans <= 0) ans = 0, ansb = 0;
		cout << ans << " " << ansb << endl;
	}



	return 0;
}