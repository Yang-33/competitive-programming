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

/* -----  2018/09/26  Problem: yukicoder 284  / Link: http://yukicoder.me/problems/no/284  ----- */
/* ------問題------

かつて、kamipeipaa君の家の庭には3本しか竹はありませんでした。
今や1列に並んだN本の竹からなる竹林があります。i番目の竹の高さはAiです。

kamipeipaa君は
・竹の本数がM(3≤M)本、i番目の竹の高さがBiであるときに、1<i<MについてBi−1,Bi,Bi+1が全て異なり、3つの要素の中でBiが最大または最小
・竹が1本も存在しない。
のどちらかの条件を満たすようにしたいと考えています。
kamipeipaa君は"ある竹を1本選んで消滅させる"魔法を繰り返し使うことで、この条件を満たすようにしたいと考えています。
この条件を満たすように0本以上の竹を消滅させたとき、最大で何本の竹を残すことが可能かkamipeipaa君に教えてあげてください。

-----問題ここまで----- */
/* -----解説等-----

https://speakerdeck.com/camypaper/yukicoder-no-284
これ大変すぎる
門松列として、l,m,rと列があるとする。
dp[m][r] = chmax(dp[l][m]+1) (条件付き)となる。
maxを考えると、適当なセグ木でできそう。
しかし考えると、結局門松列は最適値について、top2つだけ持っておけば良いとわかる。

更に、2つだけアレばいいということから、左について、dp(l1)[m] , dp(l2)[m]とでき、
dp[m] = ((mx1,l1),(mx2,l2))みたいにできる。
これで列を作ることができ、2本セグ木、ノードは最悪をして、マージも最悪をすればできそうとなる。

更に、updateする際はtop2もinsertしないとダメなので、あるm以外の部分からtop2を持ってこないといけない。
きびしーーーーーーー
結局、dpのO(N*3)->O(NlogN)まで持ってくことができる。これすごい！

----解説ここまで---- */


struct Data {
	int length, last, lastprv;
	Data(int a = 0, int b = -1, int c = -1) :length(a), last(b), lastprv(c) {}
	bool operator < (const Data & x)const { return length < x.length; }
	bool operator > (const Data & x)const { return length > x.length; }
};
struct Node {
	Data d[2];
	Node() {}
	Data fetch(int sec) {
		return d[0].lastprv != sec ? d[0] : d[1];
	}
};

struct SegTreeG {
	inline Node merge(Node &a, Node &b) { // dataのmerge
		Node ret;
		if (a.d[0] > b.d[0]) {
			ret.d[0] = a.d[0];
			if (a.d[1] > b.d[0]) {
				ret.d[1] = a.d[1];
			}
			else if (ret.d[0].lastprv != b.d[0].lastprv) {
				ret.d[1] = b.d[0];
			}
			else {
				ret.d[1] = max(a.d[1], b.d[1]);
			}
		}
		else {
			ret.d[0] = b.d[0];
			if (b.d[1] > a.d[0]) {
				ret.d[1] = b.d[1];
			}
			else if (ret.d[0].lastprv != a.d[0].lastprv) {
				ret.d[1] = a.d[0];
			}
			else {
				ret.d[1] = max(a.d[1], b.d[1]);
			}
		}
		return ret;
	}

	int N;	vector<Node> dat;
	SegTreeG(int _N) {
		N = 1;
		while (N < _N)N *= 2;
		dat = vector<Node>(N * 2 - 1);
	}

	void update(int k, Node &val) {
		k += N - 1;
		dat[k] = val; // !
		while (k) {
			k = (k - 1) / 2;
			dat[k] = merge(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}
	Node query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return Node();
		if (a <= l && b >= r)return dat[k];
		Node v1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
		Node v2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return merge(v1, v2);
	}

	inline Node query(int a, int b) {
		return query(a, b, 0, 0, N);
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;  cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VI b = a;
	SORT(b);
	UNIQ(b);
	FOR(i, 0, N) {
		a[i] = lower_bound(ALL(b), a[i]) - b.begin();
	}
	SegTreeG up(SZ(a));
	SegTreeG dw(SZ(a));

	FOR(i, 0, SZ(a)) {
		Data dwMax = dw.query(0, a[i]).fetch(a[i]);
		Data upMax = up.query(a[i] + 1, SZ(a)).fetch(a[i]);

		if (dwMax.length > 0) {
			Data dwSecondL = dw.query(0, dwMax.last).fetch(a[i]);
			Data dwSecondR = dw.query(dwMax.last + 1, a[i]).fetch(a[i]);
			Data dwSecondTop = max(dwSecondL, dwSecondR);
			Node n; n.d[0] = Data(dwMax.length + 1, a[i], dwMax.last);
			n.d[1] = Data(dwSecondTop.length + 1, a[i], dwSecondTop.last);
			up.update(a[i], n);
		}
		else {
			Node n; n.d[0] = Data(1, a[i], -1);
			n.d[1] = Data();
			up.update(a[i], n);
		}
		if (upMax.length > 0) {
			Data upSecondL = up.query(a[i] + 1, upMax.last).fetch(a[i]);
			Data upSecondR = up.query(upMax.last + 1, SZ(a)).fetch(a[i]);
			Data upSecondTop = max(upSecondL, upSecondR);
			Node n; n.d[0] = Data(upMax.length + 1, a[i], upMax.last);
			n.d[1] = Data(upSecondTop.length + 1, a[i], upSecondTop.last);
			dw.update(a[i], n);
		}
		else {
			Node n; n.d[0] = Data(1, a[i], -1);
			n.d[1] = Data();
			dw.update(a[i], n);
		}
	}
	int ans = max(up.query(0, SZ(a)).d[0].length, dw.query(0, SZ(a)).d[0].length);

	if (ans <= 2)ans = 0;
	cout << ans << "\n";

	return 0;
}
