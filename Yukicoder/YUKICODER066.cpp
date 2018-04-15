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

/* -----  2018/04/15  Problem: yukicoder 066  / Link: http://yukicoder.me/problems/no/066  ----- */
/* ------問題------

太郎君は、「輝け☆全国たこやき杯」に参加することになりました。

この大会は、総勢2M人の選手が出場し、
トーナメント形式で戦い、勝った選手がさらに勝ち残った選手と戦う方式で
優勝者を決定するものになっています。

2M人の選手にはそれぞれ、N1～N2Mまでの選手番号が割り当てられており、
太郎君にはN1番が割り当てられました。

M=3の例：

トーナメントの1回戦では、N2j−1の選手とN2jの選手が戦います。 (1≤j≤2M−1)
そして、そのそれぞれの勝者を N′j とし、
次の2回戦では、N′2k−1の選手とN′2kの選手が戦うといったように、(1≤k≤2M−2)
合計でM回戦行うことにより、1人の優勝者が決まります。

2M人の選手はそれぞれ、強さパラメータSiを持っており、
とあるA選手とB選手が勝負するとき、それぞれの強さパラメータを Sa,Sb とすると
A選手が勝つ確率は Pa=Sa2/(Sa2+Sb2)、 B選手が勝つ確率は Pb=Sb2/(Sa2+Sb2)
で表されます。
選手ごとの相性など、上記以外の要素は勝敗に影響されません。

入力に2M人の選手の強さパラメータが与えられるので、
太郎君が優勝する確率を求めてください。

-----問題ここまで----- */
/* -----解説等-----

dp(i,j):-i回戦目で、jさんが勝つ確率として、DPをする。
遷移がちょっと詰めないとめんどくさそうと感じる。
区間[L,R)を下から処理していく際に、再帰っぽく書くととても楽にかける。(segtreeで自分の子をみてmergeするかんじ)

O(M*2^M*2^M)
----解説ここまで---- */

double pro(int A, int B, VI& S) {
	return 1.0*(S[A] * S[A]) / (1.0*S[A] * S[A] + S[B] * S[B]);
}

vector<double> solve(int l, int r, VI& S) { // [l,r)
	if (l == r - 1) {
		return vector<double>(1, 1);
	}
	int m = (l + r) / 2;
	vector<double>left = solve(l, m, S);
	vector<double>right = solve(m, r, S);
	vector<double>res(SZ(left) * 2);
	FOR(i, l, m) {
		FOR(j, m, r) {
			res[i - l] += pro(i, j, S)*left[i - l] * right[j - m];
			res[j - l] += pro(j, i, S)*left[i - l] * right[j - m];
		}
	}
	return res;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI S(1 << N);
	FOR(i, 0, 1 << N) {
		cin >> S[i];
	}
	vector<double> res = solve(0, 1 << N, S);
	double ans = res[0];
	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
