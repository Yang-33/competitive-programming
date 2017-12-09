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

/* -----  2017/12/09  Problem: colocon-qual2018 B / Link: https://colopl2018-qual.contest.atcoder.jp/tasks/colopl2018_qual_b  ----- */
/* ------問題------

あなたは、「すぬけそだて」のチュートリアルをプレイしています。チュートリアルでは、あなたがすぬけ君を拾うに至った経緯が語られます。
始業時刻に遅刻し、昼食をひっくり返し、書いたプログラムはバグだらけ、挙句の果てに先輩を「パパ」と呼んでしまう……失意のどん底に陥っていたあなたは、人気のない暗い路地で、 にゃーにゃーと鳴くか細い声を耳にします。
最初は無視を決め込んでいたあなたでしたが、翌日も、その翌日も、あなたは同じ場所で同じ声を聴くのでした。
気になったあなたは、声のする方向に近づいてみました。草むらの中に広がっていた光景……それには説明の必要はないでしょう。
こうして、あなたとすぬけ君との共同生活が幕を開けたのです！
と、このような心温まるお話を見るのも、もう 10 回目です。「すぬけそだて」では、最初にランダムなゲームアイテム「マタタビ」がもらえるのですが、 あなたは好きな「マタタビ」がもらえるまでチュートリアルをやり直すことにした、というのがその理由です。
お話の内容を完全に覚えてしまったあなたは、素早くチュートリアルを終わらせることに集中することにしました。
チュートリアルは、N 個のフェイズに分かれています。各フェイズは「ローディング」か「ストーリー」のいずれかであり、文字列 S の i 文字目が 0 のとき i 個目の フェイズが「ローディング」であることを、1 のとき i 個目のフェイズが「ストーリー」であることを表します。また、i 個目のフェイズにかかる時間は、最初 Ti 秒です。
「ストーリー」のフェイズでは、開始直後にスキップボタンを押すことでそのストーリーをちょうど X 秒で終わらせることができます。スキップボタンを押さない場合、 このストーリーにかかる時間は Ti 秒のままです。「ローディング」のフェイズでは、進行を速めることはできません。
適切にボタンを押したとき、最小で何秒でチュートリアルを終わらせることができるでしょうか。

-----問題ここまで----- */
/* -----解説等-----

問題文が長すぎる。
要はsが1なら、tをXに変えることができるだけ。

----解説ここまで---- */

LL N,X;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>X;
	string S; cin >> S;
	VL t(N);
	FOR(i, 0, N) {
		cin >> t[i];
		if (S[i] == '1') {
			ans += min(X, t[i]);
		}
		else ans += t[i];
	}

	cout << ans << "\n";

	return 0;
}
