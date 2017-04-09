#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/04/08  Problem: ARC 071 C / Link: http://arc071.contest.atcoder.jp/tasks/arc071_c  ----- */
/* ------問題------

A, B からなる文字列に対して、次の操作を考えます。

文字列中の 1 文字を選ぶ。それが A なら BB で、 B なら AA で置き換える。
AAA か BBB であるような部分文字列を選び、消す。
例えば、ABA という文字列で 1 番目の操作を 1 文字目に対して行うと、 BBBA となります。 
また、BBBAAAA に対して 2 番目の操作を 4 文字目から 6 文字目に対して行うと、 BBBA となります。

これらの操作を何回でも好きな順で行うことができます。

文字列 S,T と q 個のクエリ ai,bi,ci,di が与えられます。
各クエリに対して、 S の部分文字列 SaiSai+1…Sbi を T の部分文字列 TciTci+1…Tdi にすることができるか判定してください。

-----問題ここまで----- */
/* -----解説等-----

操作を繰り返すと、AAA => "", BBB => "", AB=BA=""であるということに気が付く。
つまりA=1,B=2などとしたときにmod3 でうまく消えてくれそう。
区間のクエリにこたえたいので累積和か、セグ木で処理すればよい。

----解説ここまで---- */

ll N;

ll ans = 0LL;
string ss, tt;
#define MAX_N 300000
string ass[4] = { "AAA","BBB","AB","BA" };
ll gn;
class segtree {
public:
	ll n;
	string s[MAX_N];
	const int NON = -1;

	void init(int n) {
		while (gn < n) {
			gn *= 2;
		}
		FOR(i, 0, gn * 2 - 1) {
			s[i] = "";
		}
	}


	inline void fix(int  k) {
		// ノードkに対応する　値に修正
		//dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);//min/max
		f[k] = f[k * 2 + 1] + f[k * 2 + 2];//sum
		g[k] = g[k * 2 + 1] + g[k * 2 + 2] + R[k * 2 + 1] * L[k * 2 + 2];
		L[k] = L[k * 2 + 1];
		R[k] = R[k * 2 + 2];

	}

	void update(int k, string a) {
		k += gn - 1;
		s[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			s[k] = s[k * 2 + 1] + s[k * 2 + 2];
			FOR(i, 0, s[k].size()-3) {
				if (s[k].substr(i, 3) == ass[0])s[k].erase(i, 3);
				else if (s[k].substr(i, 3) == ass[1])s[k].erase(i, 3);
				else if (s[k].substr(i, 2) == ass[2])s[k].erase(i, 2);
				else if (s[k].substr(i, 2) == ass[3])s[k].erase(i, 2);
			}
		}
	}

};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> ss >> tt;
	// update
	segtree s, t;
	s.init(ss.size());
	t.init(tt.size());

	FOR(i, 0, ss.size()) {
		s.update(i, ss[i]);
	}
	FOR(i, 0, tt.size()) {
		t.rangefill(i, i + 1, tt[i], 0, 0, gn);
	}
	ll q;
	cin >> q;
	FOR(i, 0, q) {
		int l, r, b;
		cin >> l >> r >> b;
		// query    
		rangefill(l - 1, r, b, 0, 0, gn);
		lazy_push(l, 0, gn);
		cout << f[0] - g[0] << endl;
	}
	return 0;
}
