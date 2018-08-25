#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using type = LL;

const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/08/25  Problem: ARC 101 B / Link: http://arc101.contest.atcoder.jp/tasks/arc101_b  ----- */
/* ------問題------

長さ M の数列 b の 中央値 を次のように定義します。
b を昇順にソートして得られる数列を b' とする。 このとき、b' の M⁄2+1 番目の要素の値を、b の中央値とする。 ここで、⁄ は小数点以下を切り捨てる除算である。
例えば、(10,30,20) の中央値は 20 であり、(10,30,20,40) の中央値は 30 であり、(10,10,10,20,30) の中央値は 10 です。

すぬけ君は次のような問題を思いつきました。
長さ N の数列 a があります。 各 (l,r) (1≤l≤r≤N) について、a の連続部分列 (al,al+1,…,ar) の中央値を ml,r とします。 すべての (l,r) に対する ml,r を並べ、新たに数列 m を作ります。 m の中央値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

中央値がM以上になる(左寄り)はこれ↓
https://yang33-kassa.jp/codeforces/cf496/
これはLRカウントを高速に解く、という解法だったので値をずらせば良いだけ。
これに二分探索をのせれば答えを求めることができる。

----解説ここまで---- */

struct BIT {
	int N;
	int nn;
	vector<type> data;
	BIT(int n) {
		N = n + 1;
		data = vector<type>(n + 1, 0);
		nn = 1;
		while (nn * 2 <= N)nn *= 2;
	}
	void add(int i, type w) {
		for (int x = i; x <= N; x += x & -x) {
			data[x] += w;
		}
	}
	type sum(int i) {
		type ret = 0;
		for (int x = i; x > 0; x -= x & -x) {
			ret += data[x];
		}
		return ret;
	}
	type sum(int l, int r) {
		if (l > r) return 0;
		return sum(r) - sum(l - 1);
	}
};

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)

LL solve(const vector<LL>&a, LL M) {
	int N = (int)a.size();
	LL ret = 0; BIT bit(2e5 + 20);
	int cur = 1e5 + 10;
	FOR(i, 0, N) {
		bit.add(cur, 1);
		if (a[i] < M)cur--;
		else cur++;
		ret += bit.sum(cur);
	}
	return ret;
}

int main() {
	LL N;
	cin >> N;
	vector<LL> a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	auto b = a;
	sort(b.begin(), b.end());

	int OK = 0; int NO = N;
	FOR(i, 0, 30) {
		int mid = (OK + NO) / 2;
		if (solve(a, b[mid]) * 4 >= N * (N + 1)) {
			OK = mid;
		}
		else NO = mid;
	}
	cout << b[OK] << endl;

	return 0;
}
