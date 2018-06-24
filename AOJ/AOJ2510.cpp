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

/* -----  2018/06/24  Problem: AOJ 2510 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2510  ----- */
/* ------問題------

双子のアミとマミが通う学校では早くも夏休みに突入し，今年もおびただしい量の宿題が出された． しかし，遊び盛りの2人は今日も宿題には一切手をつけずに外へ遊びに行こうとしていた． このままでは夏休み最終日に泣きを見るのは明らかなので，保護者役のあなたは，心を鬼にして今日は読書感想文の宿題が終わるまで2人を家から出さないことにした．
準備の良いあなたは既に図書館から全ての課題図書を借りてある． ただし，図書館の規則により各本は1冊ずつしか借りられていない． さて，教育上の理由から2人には互いに協力することなく，それぞれ全ての本を読み，感想を書いてもらう事にした． 加えて，本の返却期限が近いため，まずはなるべく早くすべての本を読み終えるようにしてもらう事にした． そして，あなたはその条件下でなるべく早く宿題が終わるような宿題の進め方を考えることにした． ここで，本を読み終えた時間，宿題を終えた時間は，それぞれ双子の両方が作業を終えた時間で考える．
各本は1冊ずつしかないため，2人が同時刻に同じ本を読むことはできない． 加えて，大人の事情により，ある本を読み始めたらそれを中断する事はできず，ある本についての感想文を書き始めたらそれを中断することもできない． 当然ながら，読んでいない本について感想を書くこともできない． なお，アミとマミは双子であるため，各本について読むのにかかる時間，感想文を書くのにかかる時間は2人で共通している．
例えば，3冊の本があり，それぞれ本を読むのにかかる時間，感想文を書くのにかかる時間が以下の通りであるとする．
様々な大人の事情を考慮しつつ，遊びに行きたがっている双子のためになるべく早く宿題が終わるような進め方を考えてあげよう．

-----問題ここまで----- */
/* -----解説等-----

結局readの時間に左右されることがわかる。
したがって次を考える。
- readのうち最も大きいものが全体の半分以上を占めていなければ必ず重複しない本の読み方が存在する。
これは容易に証明できる。
したがって半分を占めていないときはそのまま総和が答えになる。
次に重複する場合を考える。
readのmax値が1000なので、上の条件でない場合は2ndMax以下の総和が100以下のときのみ。
このとき、後で本を読む方に支配されるので2*readMax-readSumの時間でできるだけ課題をしたい。
値が小さいのでbool DPができる。この時間で最大の課題をこなせば後で時間を減らせるのでこれを調べれば良い。
自然に解けた。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	while (cin >> N, N) {
		VI r(N), w(N);
		int readMax = 0;
		FOR(i, 0, N) {
			cin >> r[i] >> w[i];
			readMax = max(readMax, r[i]);
		}

		LL readSum = accumulate(ALL(r), 0LL);
		LL writeSum = accumulate(ALL(w), 0LL);
		if (readSum >= 2 * readMax) {
			cout << readSum + writeSum << endl;
		}
		else { // 要素はたかだか1000以下
			VI dp(1010, 0);
			dp[0] = 1;
			FOR(i, 0, N) { // writeを2*readMax-readSum以下に一度分割する
				if (r[i] == readMax)continue;
				FORR(j, 1010 - w[i] - 1, 0 - 1) {
					dp[j + w[i]] |= dp[j];
				}
			}
			int fg = 0;
			FOR(i, 0, 2 * readMax - readSum + 1) {
				if (dp[i])fg = i;
			}
			cout << 2 * readMax + max(0LL, writeSum - fg) << endl;
		}
	}

	return 0;
}
