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

/* -----  2018/01/15  Problem: AOJ 0343 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0343  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

ある得点以下に何人いるかを知るためには、
簡易SET,あるいは平衝二分木があればよい。
BITと座圧、あるいはmapでできる
mapのイテレータがit+=N/2とかできたら嬉しいと思ったけど、
ランダムアクセスじゃないからダメだった

と思ったけど誰の得点かわからないため、mapはだめそう

----解説ここまで---- */
typedef LL type;
struct BIT { // 0-index
	int N;
	int nn;
	vector<type> data;
	//動的はmap<int?,type>data
	BIT(int n) {
		N = n + 1;
		data = vector<type>(n + 1, 0);
		nn = 1;
		while (nn * 2 <= N)nn *= 2;
	}
	void add(int i, type w) { // a[i] += w
		i++;
		for (int x = i; x <= N; x += x & -x) {
			data[x] += w;
		}
	}
	type sum(int i) { // iまでの和 [0,i]
		i++;
		type ret = 0;
		for (int x = i; x > 0; x -= x & -x) {
			ret += data[x];
		}
		return ret;
	}
	/*	BIT 上で二分探索
	二分木の分かれ方に従って二分探索する
	左の子に進むか右の子に進むかを知るためには，左の子の範囲の和がわかればよい
	ちょうど BIT がもっている情報，O(1) 時間で得られる	*/
	int lower_bound(type w) {//  w≦[1,x]以上となる最小のindex,x
		if (w <= 0) return 0;
		int x = 0;
		for (int k = nn; k > 0; k /= 2) {
			if (x + k <= N && data[x + k] < w) {
				w -= data[x + k];
				x += k;
			}
		}
		return x;
	}
};



LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int Q;
	cin >> N >> Q;
	VI comd(Q);
	VL t(Q, 0), p(Q, 0);
	FOR(i, 0, Q) {
		cin >> comd[i];
		if (comd[i])cin >> t[i];
		else cin >> t[i] >> p[i];
		t[i]--;
	}
	VL team(N, 0);

	vector<PLL> comp;
	FOR(i, 0, N) {
		comp.push_back(PLL(0, -i));
	}

	FOR(i, 0, Q) {
		if (comd[i] == 0) {
			team[t[i]] += p[i];
			comp.push_back(PLL(team[t[i]], -t[i]));
		}
	}

	SORT(comp);
	UNIQ(comp);

	BIT bit(SZ(comp));
	VL teaminfo(N, 0);
	FOR(i, 0, N) {
		bit.add(i, 1);
	}
	//debug(ans);
	// comp (0,-2) (0,-1) (0,0),...,(6,2) (6,1)
	FOR(i, 0, Q) {
		if (comd[i]) { // print
			LL id = bit.lower_bound(N - t[i]); //　右からt[i]番目

			cout << -comp[id].second + 1 << " " << comp[id].first << endl;// rank,point
		}
		else { //change
			LL point = teaminfo[t[i]];
			point = lower_bound(ALL(comp), PLL(point, -t[i])) - comp.begin();
			bit.add(point, -1);
			teaminfo[t[i]] += p[i];
			point = lower_bound(ALL(comp), PLL(teaminfo[t[i]], -t[i])) - comp.begin();
			bit.add(point, 1);
		}
	}



	return 0;
}
