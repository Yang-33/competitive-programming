#include <bits/stdc++.h>
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

/* -----  2018/01/31  Problem: AOJ 0283 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0283  ----- */
/* ------問題------

プログラマー養成校のアカベ高校には、生徒自身で運営するユニークな勉強会があります。プログラマーは新しい技術を常に取り入れることが大切なので、この勉強会を通して自学自習の習慣を身につけることがこの活動のねらいです。
生徒は全部でN人おり、それぞれが入学時のプログラミングコンテストの結果で得られたスコアを持っています。勉強会ではN人の生徒のうち何人かがリーダーになり、各リーダーがそれぞれのグループを運営するとともに、自らの運営するグループに参加します。
リーダー以外の生徒は、自分のスコアよりも低いスコアのリーダーが運営するグループには参加できません。また、0以上のある値rを１つ決め、グループに参加する生徒とリーダーのスコアの差がr以内となるようにしています。つまり、グループのリーダーのスコアがsのとき、自分のスコアがsを超えているか、あるいは s - r 未満ならば、そのグループには参加できません。
あなたは勉強会の実行委員長であり、運営準備のためにシミュレーションを行うことにしました。シミュレーションでは、リーダーが誰もいない状態から始め、以下の操作を何回か繰り返します。
生徒をリーダーに加える。
生徒をリーダーから外す。
要求時点でのリーダーの組み合わせについて、どのグループにも参加できない生徒がx人以下になるような、最小のrを求める。
このようなシミュレーションを行うプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

取り込んだ人数について二分探索。
リーダーはsetで持っておけばadd,removeに対してlogQでできる。
あとは取り込んだ人数が重複しないように更新すればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

// 距離x以下に何人いるか
int f(int x, set<int>&pos, VI & scores) {

	int cnt = 0;
	int curpos = -1;
	for (set<int>::iterator it = pos.begin(); it != pos.end(); it++) {
		int posid = (*it);

		int lw = max(scores[posid] - x, curpos + 1);
		int up = scores[posid];
		if (lw > up)continue;
		int L = lower_bound(ALL(scores), lw) - scores.end();
		int R = upper_bound(ALL(scores), up) - scores.end();
		cnt += R-L;
		curpos = max(curpos, up);
	}
	//debug(cnt);
	return cnt;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int Q;
	cin >> N >> Q;
	int score;
	vector<PII> sd(N);
	VI scores(N);
	FOR(i, 0, N) {
		cin >> score;
		scores[i] = score;
		sd[i] = PII(score, i);
	}
	SORT(scores);
	SORT(sd);
	VI IdToPos(N);
	FOR(i, 0, N) {
		IdToPos[sd[i].second] = i;
	}
	string str;
	int x;
	set<int>idset;
	FOR(q, 0, Q) {
		cin >> str >> x; x--;
		if (str == "ADD") {
			idset.insert(IdToPos[x]);
		}
		else if (str == "REMOVE") {
			idset.erase(IdToPos[x]);
		}
		else {
			int L = -1;
			int R = INF+100000;
			int mid;
			x++;
			while (R - L > 1) {
				mid = (L + R) >> 1;
				//cout << "L:" << L << " R:" << R << endl;
				if (f(mid, idset, scores) + x >= N) {// 距離mid以内でx人以下ならOK
					R = mid;
				}
				else L = mid;
			}
			if (R == INF+100000)cout << "NA" << "\n";
			else cout << R << "\n";
		}
	}

	return 0;
}
