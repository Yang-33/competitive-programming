#include <bits/stdc++.h>
using namespace std;


/* -----  2017/11/26  Problem: tcs_codevita_2017_round2 E / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

おぼえてないけどクラスカル法を書くだけ

----解説ここまで---- */

const int maxn = 200000 + 5;

struct node {
	int x;
	int y;
	long long v;
}r[maxn];

int n, m;
int f[maxn];

bool cmp(node a, node b) {
	return a.v < b.v;
}

int find(int x) {
	if (f[x] == x)return x;
	else return f[x] = find(f[x]);
}

long long Kruskal() {
	long long ans = 0;
	for (int i = 1; i <= n; i++)f[i] = i;
	sort(r + 1, r + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int x = find(r[i].x), y = find(r[i].y);
		if (x != y) {
			ans += r[i].v;
			f[x] = y;
		}
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)scanf("%d%d%lld", &r[i].x, &r[i].y, &r[i].v);
	long long ans = Kruskal();
	printf("%lld\n", ans);
}
//int main() {
//	cin.tie(0);
//	ios_base::sync_with_stdio(false);
//
//	int N;  int M;
//	cin >> N>>M;
//	vector<edge> eg;
//	FOR(i, 0, M) {
//		edge e1,e2;
//		int a, b, c;
//		cin >> a >> b >> c;
//		a--; b--;
//		e1.f = a;
//		e1.t = b;
//		e1.c = c;
//		e2.f = b;
//		e2.t = a;
//		e1.c = c;
//		eg.push_back(e1);
//		eg.push_back(e2);
//	}
//	KRUSKAL kr;
//	cout << kr.kruskal(N, M, eg) << endl;;
//
//	return 0;
//}
