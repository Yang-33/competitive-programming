#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i,s,e) for(int (i) = (s); (i) < (e); (i)++)
#define debug(x) cout  << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

const int INF = 1e9;
const ll LINF = 1e16;

/* -----  2017/06/27  Problem: ICPC国内予選2009A / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1159&lang=jp  ----- */
/* ------問題------

みて

-----問題ここまで----- */
/* -----解説等-----

シュミレーション。

----解説ここまで---- */

int main() {
	cin.tie(0); ios::sync_with_stdio(false);

	while (true) {

		int N, P; cin >> N >> P;
		if (N == 0 && P == 0)break;

		int a[55];
		FOR(i, 0, 55)a[i] = 0;
		int wan = P;
		int pos = 0;
		while (1) {

			if (wan != 0)wan--, a[pos]++;
			else if (wan == 0)wan += a[pos], a[pos] = 0;
			pos++;
			if (pos == N)pos = 0;
			if (wan == 0) {
				bool f = 1;
				vector<int >v;
				FOR(i, 0, N) {
					if(a[i]>0) v.push_back(i);
				}
				if (v.size() == 1) {
					cout << v[0] << endl;
					goto kim;
				}
			}
		}
	kim:;


	}
	return 0;
}