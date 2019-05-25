#include <bits/stdc++.h>
#include<unordered_map>
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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/05/25  Problem: ABC 127 F / Link: http://abc127.contest.atcoder.jp/tasks/abc127_f  ----- */
template<typename type>
struct BIT0 { // 0-index
	int N;
	int nn;
	vector<type> data;
	//動的はmap<int?,type>data
	BIT0(int n) {
		N = n + 1;
		data = vector<type>(n + 1, 0);
		nn = 1;
		while (nn * 2 <= N)nn *= 2;
	}
	void add(int i, type w) { // a[i] += w
		i++;
		for (int x = i; x < N; x += x & -x) {
			data[x] += w;
		}
	}
	type sum(int i) { // iまでの和 [0,i)
		type ret = 0;
		for (int x = i; x > 0; x -= x & -x) {
			ret += data[x];
		}
		return ret;
	}
	// [l, r)
	type sum(int l, int r) {
		return sum(r) - sum(l);
	}

	/*	BIT 上で二分探索
	二分木の分かれ方に従って二分探索する
	左の子に進むか右の子に進むかを知るためには，左の子の範囲の和がわかればよい
	ちょうど BIT がもっている情報，O(1) 時間で得られる
	a[0] + a[1] + a[2] + a[3] + ... a[x] >= w となる最小のxを返す、ただしa[i] >= 0	*/

	int lower_bound(type w) {//  w≦[0,x]以上となる最小のindex,x
		if (w <= 0) return 0;
		int x = 0;
		for (int k = nn; k > 0; k /= 2) {
			if (x + k < N && data[x + k] < w) {
				w -= data[x + k];
				x += k;
			}
		}
		return x;
	}
};

void test(VI a) {
	int r = 20;
	VL b(r);
	int geta = r / 2;
	for (auto it : a) {
		FOR(i, 0, r) {
			int re = i - geta;
			b[i] += abs(re - it);
		}
		DD(De(b));
	}
}



int main() {
	//	DD(test({ 9,4,9,4,9,1,1 }););
	//DD(test({ 1,3,5,7,9 });); // つかめてきた
	//DD(test({ 1,3,-1,5,-3 }););
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int Q; cin >> Q;
	using tp = tuple<int, int, int>;
	vector<tp>a(Q);
	vector<LL>u;
	FOR(i, 0, Q) {
		int b; cin >> b;
		if (b == 1) {
			LL c, d; cin >> c >> d;
			a[i] = tp(b, c, d);
			u.push_back(c);
		}
		else {
			a[i] = tp(b, 0, 0);
		}
	}
	SORT(u);
	UNIQ(u);
	BIT0<LL>bit1(SZ(u));
	BIT0<LL>bit2(SZ(u));
	FOR(i, 0, Q) {
		int b, c, d;
		tie(b, c, d) = a[i];
		if (b == 1) {
			c = lower_bound(ALL(u), c) - u.begin();
			a[i] = tp(b, c, d);
		}
	}

	LL dsum = 0;
	int addcnt = 0;
	FOR(i, 0, Q) {
		LL b, c, d;
		tie(b, c, d) = a[i];
		if (b == 1) {
			bit1.add(c, 1);
			bit2.add(c, u[c]);
			dsum += d;
			addcnt++;
		}
		else {
			int mid = bit1.lower_bound((addcnt + 1) / 2);
			cout << u[mid] << " ";
			LL val = 0;
			LL Lsum = bit1.sum(0, mid + 1)* u[mid] - bit2.sum(0, mid + 1);
			LL Rsum = bit2.sum(mid + 1, SZ(u)) - bit1.sum(mid + 1, SZ(u))*u[mid];

			val += Lsum + Rsum + dsum;
			cout << val << endl;
			DD(de(addcnt, mid, u[mid], val));
		}

	}


	return 0;
}
