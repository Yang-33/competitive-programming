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

/* -----  2018/10/13  Problem: ARC 039 C / Link: http://arc039.contest.atcoder.jp/tasks/arc039_c  ----- */
/* ------問題------

無限に広がる二次元格子があります。原点 (0,0) から右に x、上に y 進んだ格子点の座標を (x,y) と表します。

幼稚園児の高橋君はこの格子上で好き放題に動くのが好きです。しかし、あまりにも好き勝手に動くせいで行方不明になってしまいました。 高橋君は以下の行動をしたことが調査により分かっています。

最初、高橋君は (0,0) にいました。
高橋君は好きな方向(上下左右)を決めて、その方向に直進します。そして、今までに訪問していない格子点を踏むまで直進し続けます。訪問していない格子点を踏むといったん止まります。
そして、高橋君は疲れるまで上記の操作を繰り返し、疲れると、その格子点で寝てしまいました。
保護者であるあなたは、高橋君がちょうど K 回方向を決めて直進したこと、そして各時点でどの方向に直進したかを知ることができました。 あなたは、プログラムを書いて高橋君が寝ている場所を突き止めることにしました。

-----問題ここまで----- */
/* -----解説等-----

賢い
4方向についてlinkを張り替えればよい。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N; cin >> N;
	string s; cin >> s;
	string URDL = "URDL";
	map<char, int>Map;
	FOR(i, 0, SZ(URDL))Map[URDL[i]] = i;
	using tp = tuple<int, int, int>;
	map<tp, PII>posMap;
	const int DY[] = { 1, 0,-1, 0, }; const int DX[] = { 0, 1,0, -1, };
	auto relink = [&posMap, &DY, &DX](int y, int x) {
		FOR(i, 0, 4) {
			if (posMap.find(tp(y, x, i)) == posMap.end()) {
				posMap[tp(y, x, i)] = PII(y + DY[i], x + DX[i]);
			}
		}
		FOR(i, 0, 4) {
			int rev = (i + 2) % 4;
			PII nx = posMap[tp(y, x, i)];
			posMap[tp(nx.first, nx.second, rev)] = posMap[tp(y, x, rev)];
		}

	};
	int y = 0, x = 0;
	relink(y, x);
	for (char c : s) {
		PII nx = posMap[tp(y, x, Map[c])];
		y = nx.first, x = nx.second;
		relink(y, x);
	}
	cout << x << " " << y << endl;
	return 0;
}
