#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int(i)=(s);(i) < (e);(i)++)
#define debug(x) cout << #x << ": " << x << endl

const int INF = 1e9;
const ll LINF = 1e16;
/* -----  2017/11/01  Problem:AOJ1153  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1153  ----- */
/* ------問題------

太郎と花子はそれぞれカードを何枚か持っている． 各カードには点数が書かれている．
太郎のカードと花子のカードを 1 枚ずつ交換して， それぞれの持つカードの合計点数が等しくなるようにしたい．
どのカードとどのカードを交換したらよいか．
ただし，カードを交換しなくても合計点数が等しい場合でも， 必ずカードの交換を行うものとする．
各データセットに対し， ふたつの数を 1 行にひとつの空白で区切って出力せよ．
最初の数は太郎が花子に渡すカードの点数， 2 番目の数は花子が太郎に渡すカードの点数である．
なお，合計を等しくするようなカードの交換の方法が複数ある場合は， 交換するカードの点数の和が最小となるものを出力すること．

カードの点数の合計を等しくするような交換が存在しない場合は -1 のみを含む 1 行を出力すること． 出力形式に従わない余計な文字を含んではならない．

-----問題ここまで----- */
/* -----解説等-----

実際にシュミレーションを行えばよい。
その際、(交換するカードの和,id,id)みたいなのがあるとうれしい。

----解説ここまで---- */

ll N, M;
ll ans1, ans2;
int a[120];
int b[120];

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0)break;
		FOR(i, 0, 120)a[i] = b[i] = INF;


		ll asum = 0;
		ll bsum = 0;
		FOR(i, 0, N) {
			cin >> a[i];
			asum += a[i];

		}
		FOR(i, 0, M) {
			cin >> b[i];
			bsum += b[i];
		}
		sort(a, a + N);
		sort(b, b + M);
		vector<pair<int, pii>>v;
		FOR(i, 0, N) {
			FOR(j, 0, M) {
				if (asum - a[i] + b[j] == bsum + a[i] - b[j]) {
					v.push_back(make_pair(a[i] + b[j], make_pair(a[i], b[j])));
				}
			}
		}
		sort(v.begin(), v.end());
		if (v.size() == 0) {
			cout << "-1" << endl;
		}
		else {
			ans1 = v[0].second.first;
			ans2 = v[0].second.second;
			cout <<ans1 << " " << ans2 << endl;
		}
	}
	return 0;
}