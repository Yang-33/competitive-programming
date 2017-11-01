#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int i = s;i<e;i++)
#define debug(x) cout << #x << " : " << x << endl

const int INF = (1 << 30);
const ll LINF = (1LL << 60);
/* -----  2017/11/01  Problem: AOJ1357  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1357  ----- */
/* ------問題------

円柱が倒された状態である。これを順序を保った時に、左右の幅はどれだけになるか。

-----問題ここまで----- */
/* -----解説等-----

N<=500なので一つ円を追加したときにこれが前のものと比べてどのような関係になっているかをチェックすればよい。
ここでは(0からのx距離、y距離、id)を保持して各円柱の右端の位置を計算できるようにした。

----解説ここまで---- */
int N;
double r[502];
double f(int a, int b) {// a,bの中心からのx距離
	double res = sqrt(pow(r[a] + r[b], 2) - pow(abs(r[a] - r[b]), 2));
	return res;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		cin >> r[i];
	}
	using Ty = tuple<double, int, int>;
	vector<Ty>v;
	FOR(i, 0, N) {
		double xmax = r[i];
		FOR(j, 0, i) {
			double x; int  y, id;
			tie(x, y, id) = v[j];
			xmax = max(xmax, x + f(i, j));
		}
		v.push_back(Ty(xmax, r[i], i));

	}
	double ans = 0;
	FOR(i, 0, N) {
		double x; int  y, id;
		tie(x, y, id) = v[i];
		ans = max(ans, x + r[id]);
	}
	cout << fixed << setprecision(10) << ans << endl;

}