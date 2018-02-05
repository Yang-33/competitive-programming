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

/* -----  2018/02/05  Problem: AOJ 1569 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1569  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

これクエリをソートすればBITいらないね

----解説ここまで---- */
struct BIT { // 1-index
	int N;
	int nn;
	//vector<LL> data;
	map<LL,int>data;
	BIT(int n) {
		N = n + 1;
		//data = vector<LL>(n + 1, 0);
		nn = 1;
		while (nn * 2 <= N)nn *= 2;
	}
	void add(int i, LL w) { // a[i] += w
		for (int x = i; x <= N; x += x & -x) {
			data[x] += w;
		}
	}
	LL sum(int i) { // iまでの和 [1,i]
		LL ret = 0;
		for (int x = i; x > 0; x -= x & -x) {
			ret += data[x];
		}
		return ret;
	}
	// [l, r]
	LL sum(int l, int r) {
		if (l > r) return 0;
		return sum(r) - sum(l - 1);
	}

	//[l,r] に一様加算
	void range_add(BIT &bity, int l, int r, LL val) {
		add(l, -val*(l - 1));
		bity.add(l, val);
		add(r + 1, val*r);
		bity.add(r + 1, -val);
	}
	// [1,i]までの和
	LL range_sum(BIT &bity, int i) {
		return sum(i) + bity.sum(i)*i;
	}
	// 一様加算後の[l,r]の和
	LL range_sum(BIT &bity, int l, int r) {
		return range_sum(bity, r) - range_sum(bity, l - 1);
	}
	/*	BIT 上で二分探索
	二分木の分かれ方に従って二分探索する
	左の子に進むか右の子に進むかを知るためには，左の子の範囲の和がわかればよい
	ちょうど BIT がもっている情報，O(1) 時間で得られる	*/
	int lower_bound(int w) {//  w≦[1,x]以上となる最小のindex,x
		if (w <= 0) return 0;
		int x = 0;
		for (int k = nn; k > 0; k /= 2) {
			if (x + k <= N && data[x + k] < w) {
				w -= data[x + k];
				x += k;
			}
		}
		return x + 1;
	}
};

LL N,Q;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>Q;
	VL q(Q),k(Q);
	BIT X(N*(N+1)/2+1);
	BIT X2(N*(N+1)/2+1);
	BIT Y(N*(N+1)/2+1);
	BIT Y2(N*(N+1)/2+1);
	BIT Z(N*(N+1)/2+1);
	BIT Z2(N*(N+1)/2+1);

	LL migihashi = (N*(N+1))/2;
	FOR(i,0,Q){
		// 閉区間
		cin>>q[i]>>k[i];
		if(q[i]==0){// x
			LL ret = xad(k[i],N);
			ans += ret*ret;
			ans -= Y.range_sum(Y2,1,ret);
			ans -= Z.range_sum(Z2,1,ret);
			Y.range_add(Y2,1,ret,1);
			Z.range_add(Z2,1,ret,1);
		}else if(q[i] ==1){// y
			LL ret = yad(k[i],N);
			ans += ret;
			ans -= X.range_sum(X2,migihashi-ret+1,migihashi);
			ans -= Z.range_sum(Z2,);
			X.range_add(X2,,,1);
			Z.range_add(Z2,,,1);
		}else if(q[i] == 2){// z

		}
	}
	cout << ans << "\n";

	return 0;
}
