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

/* -----  2017/12/09  Problem: colocon-qual2018 A / Link: https://colopl2018-qual.contest.atcoder.jp/tasks/colopl2018_qual_a  ----- */
/* ------問題------

あなたは、育成シミュレーションゲーム「すぬけそだて」を入手しました。
「すぬけそだて」では、あなたはひょんなことから路地裏で世界一賢いねこ「すぬけ君」との運命の出会いを果たします。 拾いたてのすぬけ君はまだ体も貧弱で、ただにゃーにゃーと鳴いているばかりです。しかし成長するにつれ、すぬけ君のできることはどんどん増えていきます。
お手、ジャンプ、ネズミ取り、洗濯、引越し作業、競技プログラミング、ゲーム制作、確定申告、起業……すぬけ君の可能性は無限大です！　 賢くて、少し変わったねこと一緒の、夢のような生活があなたを待っています！
閑話休題。ところで、ゲームを始めるにあたって、あなたは自分の名前を決めなければいけません。名前として登録できるのは、A 文字以上 B 文字以下の英小文字からなる文字列です。
A,B とあなたの登録したい名前を表す文字列 S が与えられるので、その名前を登録できるかどうか判定してください。

-----問題ここまで----- */
/* -----解説等-----

isin?をする

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int A, B;
	string S;
	cin >> A>>B;
	cin >> S;

	if (A <= SZ(S) && SZ(S) <= B) {
		cout << "YES" << endl;
	}
	else cout << "NO" << "\n";

	return 0;
}
