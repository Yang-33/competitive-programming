#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)

/* -----  2017/05/20  Problem: ARC 074 B / Link: http://arc074.contest.atcoder.jp/tasks/arc074_b  ----- */
/* ------問題------

長さ3Nの数列について、N個の要素を取り出し、残った2Nこの数列で、(a前半N要素の総和)−(a後半N要素の総和)
を最大化したい。最大値は。
N≦10^5

-----問題ここまで----- */
/* -----解説等-----

A/Bの境界を決定して、自分のサイドの領域で好きな数をとればよい。
A/Bの境界をN回探索してこれについての最適値を求めていると間に合わない。

一つ境界をずらしたときに行う動作は要素が一つ移動してAでは大きいものならば採用、最小を排出
Bでは最小なら採用、最大を排出、を行っている。
これはpriority_queueでこの操作を再現できる。
左右からA/Bの動作をし、最適値同士を組み合わせればよい。

----解説ここまで---- */


ll N;

ll ans = LLONG_MIN;
ll a[300030];
ll b[300030];
ll res[300030];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;

	FOR(i, 0, 3 * N) {
		cin >> a[i];
	}
	priority_queue<ll, vector<ll>, greater<ll>>qa;
	priority_queue<ll>qb;
	ll asum = 0;
	ll bsum = 0;
	FOR(i, 0, 3 * N) {
		qa.push(a[i]);
		asum += a[i];
		if (qa.size() > N) {
			asum -= qa.top(); qa.pop();
		}
		res[i] = asum;
	}
	FORR(i, 3 * N - 1, -1) {
		qb.push(a[i]);
		bsum += a[i];
		if (qb.size() > N) {
			bsum -= qb.top(); qb.pop();
		}
		if(i>=1)
		res[i-1] -= bsum;
	}

	ans = res[N - 1];
	FOR(i, N, 2 * N) {
		ans = max(ans, res[i]);
	}


	cout << ans << endl;

	return 0;
}
