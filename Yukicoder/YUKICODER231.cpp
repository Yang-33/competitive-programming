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

/* -----  2018/08/24  Problem: yukicoder 231  / Link: http://yukicoder.me/problems/no/231  ----- */
/* ------問題------

ちゃろー、センパイ！
悩んでる顔してるって？
なんかセンパイにしては妙に鋭いですねー…。
今ようやくちょうどぴったりレベル 98 になったところで経験値 0 なんですけど、明日のGvまでにレベルカンストして威厳を保ちたいなって思ってるんですけど、デスペナもきついし、どこの狩場がいいのかなーって…。
例えば、この狩場だと、経験値効率 200k/h ぐらい出るんですけど、1 時間あたりに 3 回ぐらい死んじゃうんですよねー…。
え、何言ってるかわからないですか？
センパイにもわかるように説明しますね！
どのダンジョンでレベル上げするかって話なんですけど、N 個のダンジョンがあって、ダンジョン i だと 1 時間あたりに経験値が Gi ぐらいもらえるんです。
それはいいんですけど、死んじゃうとそのたびにレベル 98 からレベル 99 になるのに必要な経験値の 1%、つまり経験値が 30000 だけ無くなるんですよー！
で、ダンジョン i だと、多分 1 時間あたりに Di 回ぐらい死んじゃうんですよね…。
だから、ダンジョン i で 1 時間レベル上げしたら Gi−30000Di ぐらい経験値が得られるんですね。
持続時間が 1 時間のアイテム使いながらレベル上げするので、1 時間は同じダンジョンでレベル上げをしたいんです。
今日の夜から明日の朝まで、6 時間ぐらいはプレイするつもりなので、1 時間のレベル上げを 6 セットするつもりなんですけど、どのダンジョンに行けば明日の朝までにレベルが上がりますかね？
必要経験値は、「ちょうど」もしくは「超えれば」OKである。必要経験値は、30000が1%であることを利用してください。
複数回同じダンジョンに行ってもOKです。
下の文に出てくる気分転換はしなくても良いです。
6回以内にレベルアップしても6回ダンジョンに行くようにしてください。

-----問題ここまで----- */
/* -----解説等-----

めぐるちゃんごめん

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;  cin >> N;
	vector<PLL> a(N);
	FOR(i, 0, N) {
		LL G, D; cin >> G >> D;
		a[i] = PLL(G - 30000 * D, i + 1);
	}
	RSORT(a);
	LL sum = a[0].first * 6;
	if (sum < 3000000) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		FOR(i, 0, 6) {
			cout << a[0].second << endl;
		}
	}

	return 0;
}
