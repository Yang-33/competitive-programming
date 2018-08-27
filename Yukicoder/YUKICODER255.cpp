#include <bits/stdc++.h>
using namespace std;
using LL = unsigned long long;
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
const LL MOD = 1000000000000000009;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/08/27  Problem: yukicoder 255  / Link: http://yukicoder.me/problems/no/255  ----- */
/* ------問題------

Splarrraaay ｽﾌﾟﾗｰﾚｪｰｰｲ はSplarraay ｽﾌﾟﾗﾚｪｰｲの続編であり、配列を塗りつぶすだけの簡単なゲームです。
プレイヤーはチームAとチームBとチームCとチームDとチームEに分かれ、それぞれのチームを表す色で 1 つの配列を塗りつぶし合います。
最終的なスコアはそのチームの色で塗りつぶされた要素の数と、後述するボーナスポイントの和で決まり、スコアが高いチームがゲームの勝者となります。
ルール

長さ N の、何色にも塗られていない配列が与えられる。つまり、全ての要素に対して、それぞれの色の厚みは 0 である。
5 つのチームは配列のある区間 [l,r] をそのチームの色で塗りつぶしていく。
その際、
何色にも塗られていなかった場合は、それのチームの色で塗られ、そのチームの色の厚みが 1 となり、
既にそのチームの色で塗られていた要素に関しては、その色の厚みが 1 だけ増え、
別のチームの色で塗られていた場合は、後から塗られた色で上書きされ、別のチームの色の厚みを 0 とした後、自分のチームの色の厚みが 1 となる。
不定期にボーナスチャンスが与えられる。
ボーナスチャンスでは区間 [l,r] が与えられ、その時点での区間 [l,r] でのチームXの色の厚みの和を Xlr（X=A,B,C,D,E）とすると、この値が最も大きい方のチームに max(Alr,Blr,Clr,Dlr,Elr) のボーナスポイントが与えられる。
値が最も大きい物が複数ある場合、どのチームにもボーナスポイントは与えられない。
時間制限が訪れゲームが終了したとき、配列の全区間 [0,N−1] での、そのチームの色の厚みの和と、それまでに得たボーナスポイントの和がそのチームのスコアとなる。
既にゲームは終了し、後はスコアを計算するだけです。各チームの行動の履歴とボーナスチャンスの詳細が時系列順に与えられるので、最終スコアを算出してください。

-----問題ここまで----- */
/* -----解説等-----

N...
これめんどい
まず区間が異常に広いので、座標圧縮して、区間に重みのあるセグ木を考える。
方針は2つある
1. 5つの要素をnodeに持って、気合をする(失敗した)
2. 5つsegtreeを持って、区間fill*addを書く これはそんなに難しくない。

----解説ここまで---- */

struct Node {
	Node() :sum(0), cc(0) {} // e
	Node(long long x) :sum(x), cc(x) {}
	LL sum, cc;
};
struct Lazy {
	Lazy() :set(0), Doclear(0), lazyval(0) {} // lazy e
	bool set;
	bool Doclear;
	int lazyval;
};

long long out_range = 0;

typedef long long ll;
struct LazySegTreeP {

	long long N;
	vector<Node>dat;
	vector<Lazy> lazy;
	
	inline Node merge(Node& a, Node& b) {
		Node node;
		(node.sum += (a.sum + b.sum) % MOD) %= MOD;
		(node.cc = (a.cc + b.cc) % MOD) %= MOD;
		return node;
	}

	void lazy_push(ll k, ll queryL, ll queryR) {
		if (lazy[k].set == 0)return;
		if (lazy[k].Doclear)dat[k].sum = 0;
		(dat[k].sum += (dat[k].cc*lazy[k].lazyval) % MOD) %= MOD;
		if (k < N - 1) {
			lazy_set(2 * k + 1, lazy[k]);
			lazy_set(2 * k + 2, lazy[k]);
		}
		lazy[k].Doclear = 0;
		lazy[k].lazyval = 0;
		lazy[k].set = 0;
	}

	inline void lazy_set(ll k, const Lazy& val) {
		lazy[k].set = 1;
		if (!val.Doclear) {
			(lazy[k].lazyval+=val.lazyval);
		}
		else {
			lazy[k].Doclear = val.Doclear;
			lazy[k].lazyval = val.lazyval;
		}
	}

	inline void fix(ll k) {
		dat[k] = merge(dat[k * 2 + 1], dat[k * 2 + 2]);
	}

	inline void kth_direct_update(ll id, LL c) {
		id += N - 1;
		dat[id].cc = c;
	}
	void build() { for (int i = N - 2; i >= 0; i--) dat[i] = merge(dat[2 * i + 1], dat[2 * i + 2]); }

	LazySegTreeP(int _N) {
		N = 1;
		while (N < _N)N *= 2;
		dat = vector<Node>(N * 2 - 1);
		lazy = vector<Lazy>(N * 2 - 1);
	}

	inline void lazy_update(ll queryL, ll queryR, const Lazy& val, ll k = 0, ll nodeL = 0, ll nodeR = -1) {
		if (nodeR == -1)nodeR = N;
		lazy_push(k, nodeL, nodeR);

		if (nodeR <= queryL || queryR <= nodeL) { return; }
		if (queryL <= nodeL && nodeR <= queryR) {
			lazy_set(k, val);
			lazy_push(k, nodeL, nodeR);
			return;
		}
		ll nodeM = (nodeL + nodeR) / 2;
		lazy_update(queryL, queryR, val, k * 2 + 1, nodeL, nodeM);
		lazy_update(queryL, queryR, val, k * 2 + 2, nodeM, nodeR);

		fix(k);
		return;
	}

	Node query(ll queryL, ll queryR, ll k, ll nodeL, ll nodeR) {

		lazy_push(k, nodeL, nodeR);

		if (nodeR <= queryL || queryR <= nodeL) { return Node(out_range); }
		if (queryL <= nodeL && nodeR <= queryR) { return dat[k]; }

		ll nodeM = (nodeL + nodeR) / 2;
		Node vl = query(queryL, queryR, k * 2 + 1, nodeL, nodeM);
		Node vr = query(queryL, queryR, k * 2 + 2, nodeM, nodeR);
		return merge(vr, vl);
	}
	inline Node query(int a, int b) {
		return query(a, b, 0, 0, N);
	}
};

LL cost[300005];
LL L[150005];
LL R[150005];
short int x[150005];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	long long N, Q; cin >> N >> Q;
	vector<LL> Ws;
	FOR(i, 0, Q) {
		cin >> x[i] >> L[i] >> R[i];
		R[i]++;
		Ws.push_back(L[i]); Ws.push_back(R[i]);
	}
	SORT(Ws);
	UNIQ(Ws);
	FOR(i, 0, SZ(Ws) - 1) {
		cost[i] = Ws[i + 1] - Ws[i];
	}
	FOR(i, 0, Q) {
		L[i] = lower_bound(ALL(Ws), L[i]) - Ws.begin();
		R[i] = lower_bound(ALL(Ws), R[i]) - Ws.begin();
	}
	vector<LazySegTreeP>segs;
	FOR(i, 0, 5) {
		segs.push_back(LazySegTreeP(SZ(Ws)));
		FOR(j, 0, SZ(Ws)) {
			segs[i].kth_direct_update(j, cost[j]);
		}
		segs[i].build();
	}

	vector<LL> points(5, 0);
	FOR(_, 0, Q) {
		//cout << L[_] << " " << R[_] << "cs:" << (long long)(wsum[R[_] - 1] - wsum[L[_]-1]) << endl;

		if (x[_] == 0) {// bonus 

			vector<LL>tops;
			FOR(i, 0, 5)tops.push_back(segs[i].query(L[_], R[_]).sum);
			LL maxVal = *max_element(ALL(tops));
			int cnt = 0, id = 0;
			FOR(i, 0, 5) {
				if (maxVal == tops[i])cnt++, id = i;
			}
			if (cnt == 1) {
				(points[id] += maxVal) %= MOD;
			}
		}
		else { // add 
			x[_]--;
			FOR(i, 0, 5) {
				Lazy lz;

				if (i == x[_])lz.Doclear = 0, lz.lazyval = 1;
				else lz.Doclear = 1;
				segs[i].lazy_update(L[_], R[_], lz);

			}
		}
	}


	FOR(i, 0, 5) {
		LL topNode = segs[i].query(0, SZ(Ws)).sum;
		(points[i] += topNode) %= MOD;
		long long ans = points[i];
		cout << ans << " \n"[i == 4];
	}

	return 0;
}
