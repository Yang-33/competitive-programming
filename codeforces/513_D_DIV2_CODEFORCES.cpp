#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
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

/* -----  2018/10/04  Problem: CodeForces513 D div2 / Link: http://codeforces.com/contest/1060/problem/D  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

lとrは実は交換可能ですって…はい。
つながっているものは考えなくても良いのでOK.結局どこにつなぐかだけを考えたい。
すると、あるLに対してはどれをつなぐことができる。(ここまではそれはそうと行った感じ)
1人1tableになるとする。すると先の考えから、Lに対してRを適当に選んでくることができる。
必要分を最小化すればよいが、適当に実験すると昇順でmaxを取るのが良さそう。
理由を考える。
なるべく大きいものは大きいものでカバーするのがよい。カバーしなかったとすると、それを使用しないといけないのでダメ。

たのしい(実際には解けていないので楽しくはない)


追記：ある手についてはカバーできたほうが嬉しい。
必ずN個の手は使うとなると、大きい方でギリギリのものをつかみたい。
マッチングっぽいがこれはソートするだけでよい。もしそうでないものが最適ならばソートから改善した手になるが、
1手でも変更するとコストが大きくなるためウソ。よって最適。

----解説ここまで---- */


LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;cin >> N;
	VI L(N), R(N);
	FOR(i, 0, N) {
		cin >> L[i] >> R[i];
	}
	SORT(L);
	SORT(R);
	FOR(i, 0, N) {
		ans += max(L[i], R[i]) + 1;
	}

	cout << ans << "\n";

	return 0;
}


//
//LL ans = 0LL;
//bool merged[200005];
//bool done[2][200005];
//int main() {
//	fill(merged, merged + 200005, 0);
//	cin.tie(0);
//	ios_base::sync_with_stdio(false);
//
//	LL N;
//
//	cin >> N;
//	VI L(N), R(N);
//	using tp = pair<PII, int>;
//	using vtp = tuple<int, int, int, int>;
//	vector<vtp> occ;
//	set<tp>se[2];
//	FOR(i, 0, N) {
//		cin >> L[i] >> R[i];
//		occ.push_back(vtp(L[i], R[i], i, 0));
//		occ.push_back(vtp(R[i], L[i], i, 1));
//		se[0].insert(tp(PII(L[i], -R[i]), i));
//		se[1].insert(tp(PII(R[i], -L[i]), i));
//	}
//	RSORT(occ);
//	// マージは最大でもN-1回まで？ -> 1回やると1個減るのでそう
//
//	// occについてやる　ないならそんで良い
//
//	// 必ず1つmergedになっていく(or もうみない)
//	for (auto vals : occ) { // 降順
//		int val, id, side;
//		tie(val, ignore, id, side) = vals;
//		if (merged[id])continue;
//		// 高いもののsideで一致する高いものを持ってくる
//		auto it = se[!side].lower_bound(tp(PII(val, -(INF + 20)), 0));
//
//		//cout << "one" << endl;
//		//for (auto itit : se[1]) {
//		//	cout << itit.first.first << ", " << -itit.first.second << ", " << itit.second << endl;
//		//}
//
//		{ // あるにはあった
//			// 自分のidならpass(1回しかない)
//			//if(it==se[!side].end())continue
//			//if ((*it).second == id && it!=se[!side].begin())--it;
//			//else if ((*it).second == id)continue;
//			
//			if ((*it).second == id)++it;
//			if (it == se[!side].end())continue;
//			
//			// check そうなら 相手をさくじょでmerge,さらにse,L,Rを更新
//			if ((*it).first.first == val) {
//				int revSideId = (*it).second;
//				if (merged[revSideId])continue;
//				//				int revSideVal = -(*it).first.second;
//
//				// erase & insert
//				if (side == 0) {
//					se[side].erase(tp(PII(L[id], -R[id]), id));
//					se[!side].erase(tp(PII(R[id], -L[id]), id));
//					L[id] = L[revSideId];
//					se[side].insert(tp(PII(L[id], -R[id]), id));
//					se[!side].insert(tp(PII(R[id], -L[id]), id));
//				}
//				else {
//					se[!side].erase(tp(PII(L[id], -R[id]), id));
//					se[side].erase(tp(PII(R[id], -L[id]), id));
//					R[id] = R[revSideId];
//					se[!side].insert(tp(PII(L[id], -R[id]), id));
//					se[side].insert(tp(PII(R[id], -L[id]), id));
//				}
//				ans += val + 1;
//				cout << "merge:" << id << "," << revSideId << ", side is" << side << ", val is" << val << endl;
//				// erased merge obj
//				merged[revSideId] = 1;
//				if (side == 0) { // 
//					se[side].erase(tp(PII(-(*it).first.second, -val), revSideId));
//					se[!side].erase(it);
//				}
//				else {
//					se[side].erase(tp(PII(-(*it).first.second, -val), revSideId));
//					se[!side].erase(it);
//				}
//				// se,そのままでよくない？
//			}
//			else { //ない
//				done[side][id] = 1;
//				if (done[side][id] && done[!side][id]) {
//					//merged[id] = 1;
//				}
//			}
//		}
//
//		// 小さいものを見終えたら
//
//	}
//	// 0のみやる
//	/*FOR(i, 0, N) {
//		if (!merged[i]) {
//			ans += 1 + max(L[i], R[i]);
//		}
//	}*/
//	//cout<<""
//	for (auto& it : se[0]) {
//		cout << it.first.first << ", " << -it.first.second << ", " << it.second << endl;
//		ans += 1 + max(abs(it.first.first), abs(it.first.second));
//	}
//
//	cout << ans << "\n";
//
//	return 0;
//}
