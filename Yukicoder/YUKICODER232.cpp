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

/* -----  2018/08/24  Problem: yukicoder 232  / Link: http://yukicoder.me/problems/no/232  ----- */
/* ------問題------

ちゃろー、センパイ！
このゲームですか？
今は、めぐる、昔のクラシックなRPGをやってます！
懐かしいですよね！
裏技辞典みたいな本に載ってる裏技を試そうとしてるんですけど、条件がややこしいんですよね…。
勇者たちは十字キーで動かすんですけど、10 フレームに一度押されているキーに対応して動くんですね。
この渦に飛び込むと、砂漠の真ん中にワープして、それから 10T フレーム後、つまり、T 回だけ移動した後に、ちょうどあるマスに到着しないといけないんですよー！
途中で止まると、今何フレーム目かわからなくなるので、ずっと動き続けたいんですけど、そんなことできるのかなーって…。
センパイ、助けてください！
もうちょっと詳しく状況を説明しますね。
十字キーは、上下左右の 4 つのキーが有るんですけど、上と下、右と左は同時に押せないんですけど、上と右とかは同時に押せますからね。
T 回移動するのは、上キーを押していると上方向に 1 歩だけ、右キーを押していると右に 1 歩だけ動くって感じで、上も右も両方押していると上にも右にも 1 歩ずつ進んだ場所に移動しますよ！
ワープする場所は砂漠の真ん中で障害物も何もない場所なので自由に移動できますからね。
そうそう、目的地は、砂漠の真ん中から、上に A 歩、右に B 歩だけ進んだ場所ですからね！
え、目的地に移動してずっと待っておけばいいじゃないかって？
ちょうど 10T フレーム後に、別のマスからそのマスに「到着」しないとダメなんですよね…。
あーもぉ、なんで昔のゲームってこうなんでしょうね？

-----問題ここまで----- */
/* -----解説等-----

>> てきとーになんかやって，えいやってつじつま合わせれば良いです．

ゆるさん
コーナーを除けばそんなに難しくはない。
判定は最大値がT以下のときで、無駄行動をして時間を稼げば良い。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T, A, B;
	cin >> T >> A >> B;
	// """到達"""
	if ((T == 1 && A == 0 && B == 0) || A > T || B > T) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		vector<string> v(T);
		FOR(i, 0, A) {
			v[i] += "^";
		}
		int p = A;
		while (p <= T / 2 && p <= T - 2) {
			v[p++] += "^";
			v[p++] += "v";
		}
		FOR(i, 0, B) {
			v[T - 1 - i] += ">";
		}
		p = B;
		while (p <= T / 2 && p <= T - 2) {
			v[T - 1 - p++] += ">";
			v[T - 1 - p++] += "<";
		}
		FOR(i, 0, T) {
			cout << v[i] << endl;
		}
	}

	return 0;
}
