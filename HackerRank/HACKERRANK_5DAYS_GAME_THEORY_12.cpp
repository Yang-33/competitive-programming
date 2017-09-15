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

/* -----  2017/09/15  Problem: hackerrank_5days_game_theory_12  / Link:   ----- */
/* ------問題------

長さNの配列A,Bがある。このなかから両者は順にiを選択し選択した人が1ならA[i],2ならB[i]を手に入れる。
このとき最適な行動を合わせてN回するとどちらが勝つか。

-----問題ここまで----- */
/* -----解説等-----

最初は両者が得られる最大なものを貪欲にとるのでA,Bのセグ木をもって検索＆削除かなあとおもったけど無理そうだった。
この考えは間違っていて、自分の得るポイントよりも、相手の取るポイントもつぶすことができる。
このことから得点の絶対値が大きいものをとっていけばよいことになる(相手にうれしいものと自分にうれしいものの得点は一緒)。
ノリなのでしっくりこない。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int A[1003];
string ansS[3] = { "First","Second","Tie" };

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	using tp = tuple<int, int, int>;
	int T; cin >> T;
	FOR(t, 0, T) {
		int n; cin >> n;
		vector<tp>v;

		FOR(i, 0, n) {
			cin >> A[i];
		}int B;
		FOR(i, 0, n) {
			cin >> B;
			v.PB(tp(A[i] + B, A[i], B));
		}
		RSORT(v);
		int val = 0;
		int a, b, c;
		FOR(i, 0, n) {
			tie(a, b, c) = v[i];
			//cout << a << " " << b << " " << c << endl;
			if (i%2==0) { val += b; }
			else { val -= c; }
		}

		if (val != 0) {
			ans = (val > 0 ? 0 : 1);
		}
		else ans = 2;
		cout << ansS[ans] << "\n";
	}

	return 0;
}
