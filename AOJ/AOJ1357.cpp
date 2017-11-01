#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int i = s;i<e;i++)
#define debug(x) cout << #x << " : " << x << endl

const int INF = (1 << 30);
const ll LINF = (1LL << 60);
/* -----  2017/11/01  Problem: AOJ1357  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1357  ----- */
/* ------���------

�~�����|���ꂽ��Ԃł���B�����������ۂ������ɁA���E�̕��͂ǂꂾ���ɂȂ邩�B

-----��肱���܂�----- */
/* -----�����-----

N<=500�Ȃ̂ň�~��ǉ������Ƃ��ɂ��ꂪ�O�̂��̂Ɣ�ׂĂǂ̂悤�Ȋ֌W�ɂȂ��Ă��邩���`�F�b�N����΂悢�B
�����ł�(0�����x�����Ay�����Aid)��ێ����Ċe�~���̉E�[�̈ʒu���v�Z�ł���悤�ɂ����B

----��������܂�---- */
int N;
double r[502];
double f(int a, int b) {// a,b�̒��S�����x����
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