#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
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

/* -----  2017/07/07  Problem: ukuku09_contest D  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */
ll n, Q;

int ans;

struct mergebitsetTree {
	ll N;
	vector<bitset<1005>>tree;

	mergebitsetTree(int _N) {
		N = 1;
		while (N < _N)N *= 2;
		tree.resize(2 * N - 1, 0);
	}

	bitset<1005> merge_set(bitset<1005>&a, bitset<1005>&b) {
		return a | b;
	}

	void update(int k, int val) {
		k += N - 1;
		tree[k].set(val);
		while (k) { // 根まで再帰的に上る
			k = (k - 1) / 2;
			//tree[k].set(val);
			tree[k] = merge_set(tree[k * 2 + 1], tree[k * 2 + 2]);// merge
		}
	}

	// 区間[a,b)の評価
	bitset<1005> query(int a, int b, int k, int l, int r) {
		//if (r == -1)r = N;
		if (r <= a || b <= l)return bitset<1005>(0); // 区間が被らない 
		if (a <= l&&b >= r) {
			return  tree[k]; // 値を返す
		}
		bitset<1005> v1 = query( a, b, k * 2 + 1, l, (l + r) / 2);
		bitset<1005>v2 = query( a, b, k * 2 + 2, (l + r) / 2, r);
		return merge_set(v1, v2); //merge
	}
	inline bitset<1005> query(int a, int b) {
		return query( a, b, 0, 0, N);
	}

};

int main() {

	scanf("%lld %lld", &n, &Q);
	mergebitsetTree settree(1000006);
	//	settree.init(1000000);
	FOR(i, 0, Q) {
		int num; scanf("%d", &num);
		if (num == 1) {
			int a, b; scanf("%d %d", &a, &b);
			settree.update(a, b);
		}
		else if (num == 2) {
			int l, r; scanf("%d %d", &l, &r);
			bitset<1005> a;
			a=settree.query( l, r + 1);
			printf("%d\n", a.count());

		}
	}

	return 0;
}