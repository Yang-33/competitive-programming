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

/* -----  2017/11/29  Problem: AOJ 2729 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2729  ----- */
/* ------問題------

名前をカットする。
カットしたい名前とカットしてはいけない名前が与えられるので、
ある連続したエリアをカットするとき、最小何回で全部カットできるか。

-----問題ここまで----- */
/* -----解説等-----

最小のものはこれを選択しないとだめなため、この周りをできるだけ愚直にカットする。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	vector<PII> seg;
	FOR(i, 0, N) {
		char c; int len; cin >> c >> len;
		seg.push_back(PII((c == 'y'), len));
	}


	// 小さい方からまとめて消す
	// 削除した残りの区間についてまたやる

	// ** 削ったものについて独立にやるとめちゃ長い削除禁止棒があるときに影響が出る
	queue<vector<PII>>q;
	q.push(seg);// [l,r)

	while (!q.empty()) {
		vector<PII> a = q.front(); q.pop();

		int L = 0, R = SZ(a);
		int minval = INF;
		int minid = -1;
		FOR(i, L, R) { // minを持ってくる
			if (a[i].first == 1 && a[i].second < minval) {
				minval = a[i].second;
				minid = i;
			}
		}
		if (minid == -1)continue; //ないわね

		ans++; //削除確定
		//minのまわりを上下ではさむように
		int nL = minid;
		while (nL > L && (a[nL - 1].first == 1 || (a[nL - 1].first == 0 && a[nL - 1].second < minval)))nL--;
		int nR = minid;
		while (nR < R - 1 && (a[nR + 1].first == 1 || (a[nR + 1].first == 0 && a[nR + 1].second < minval)))nR++;

		// nLまではOK
		// nRまではOK
		vector<PII>nx;
		FOR(i, L, R) {
			if (!(nL <= i&&i <= nR))nx.push_back(a[i]);
		}
		q.push(nx);
	}


	cout << ans << "\n";

	return 0;
}

//
//#include <bits/stdc++.h>
//using namespace std;
//
//using VS = vector<string>;    using LL = long long;
//using VI = vector<int>;       using VVI = vector<VI>;
//using PII = pair<int, int>;   using PLL = pair<LL, LL>;
//using VL = vector<LL>;        using VVL = vector<VL>;
//
//#define ALL(a)  begin((a)),end((a))
//#define RALL(a) (a).rbegin(), (a).rend()
//#define PB push_back
//#define EB emplace_back
//#define MP make_pair
//#define SZ(a) int((a).size())
//#define SORT(c) sort(ALL((c)))
//#define RSORT(c) sort(RALL((c)))
//#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
//#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
//#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
//#define debug(x) cerr << #x << ": " << x << endl
//const int INF = 1e9;                          const LL LINF = 1e16;
//const LL MOD = 1000000007;                    const double PI = acos(-1.0);
//int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
//
///* -----  2017/11/29  Problem: AOJ 2729 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2729  ----- */
///* ------問題------
//
//
//
//-----問題ここまで----- */
///* -----解説等-----
//
//
//----解説ここまで---- */
//
//LL N;
//
//LL ans = 0LL;
//
//int main() {
//	cin.tie(0);
//	ios_base::sync_with_stdio(false);
//
//	cin >> N;
//	vector<PII> seg;
//	FOR(i, 0, N) {
//		char c; int len; cin >> c >> len;
//		seg.push_back(PII((c == 'y'), len));
//	}
//
//
//	// 小さい方からまとめて消す
//	// 削除した残りの区間についてまたやる
//	queue<PII>q;
//	q.push(PII(0, N));// [l,r)
//
//	while (!q.empty()) {
//		PII a = q.front(); q.pop();
//		int L = a.first, R = a.second;
//		if (L >= R)continue;
//		if (L < 0 || R > N)continue;
//		int minval = INF;
//		int minid = -1;
//		FOR(i, L, R) { // minを持ってくる
//			if (seg[i].first == 1 && seg[i].second < minval) {
//				minval = seg[i].second;
//				minid = i;
//			}
//		}
//		if (minid == -1)continue; //ないわね
//
//								  //minのまわりを上下ではさむように
//		int nL = minid;
//		while (nL > L && (seg[nL - 1].first == 1 || (seg[nL - 1].first == 0 && seg[nL - 1].second < minval)))nL--;
//		int nR = minid;
//		while (nR < R - 1 && (seg[nR + 1].first == 1 || (seg[nR + 1].first == 0 && seg[nR + 1].second < minval)))nR++;
//
//		// nLまではOK
//		// nRまではOK
//		if (L < nL)q.push(PII(L, nL));
//		if (nR + 1 < R)q.push(PII(nR + 1, R));
//		ans++;
//	}
//
//
//	cout << ans << "\n";
//
//	return 0;
//}
