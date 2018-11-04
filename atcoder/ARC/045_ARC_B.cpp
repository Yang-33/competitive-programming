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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/04  Problem: ARC 045 B / Link: http://arc045.contest.atcoder.jp/tasks/arc045_b  ----- */
/* ------問題------

高橋君の通っている学校で大掃除が行われることになりました．学校には N 個の教室があり，各教室は 1 から N まで順番に番号付けられており，左から右に並んでいます．
高橋君の学校には高橋君を含め M 人の生徒がおり，掃除すべき連続した教室の区間(掃除区間と呼ぶ)は M 個既に決まっています．しかし，それらの掃除区間を誰が担当するかは決まっていません． 異なる生徒には異なる掃除区間が割り当てられ，割り当てられた生徒はそれに含まれる全ての教室を掃除しなければなりません．1 つの教室が複数の掃除区間に含まれることがあります．
高橋君は大掃除の日に女の子とのデートの約束をしていることに気づきました．デートをサボってしまうと何が起こるか分からないので大掃除をサボることに決めました． 前述の通りいくつかの教室については複数の掃除区間に含まれていることがあるので，高橋君の担当分をサボっても全ての教室を誰かが掃除してくれさえすれば，サボったことがバレないことに気づきました． 掃除されていない教室があった場合には，サボったことがバレます．
あなたの仕事は高橋君のために，サボってもバレない掃除区間を全て教えてあげることです．
なお，この学校の生徒は高橋君を除きみんな真面目なので，高橋君以外がサボることは無いと仮定してください．

-----問題ここまで----- */
/* -----解説等-----

区間addを考える。その後ある値が2以上なら、誰かがさぼっても問題ない。
したがって、[s_i,t_i]について、どの値も2以上かを判定すれば良い。
一回区間addしたあと、2以上のものを別の配列で1にして、これの累積和から区間和が区間幅と一致するか見れば良い。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	VI s(M), t(M);
	VI csum(N + 11, 0);
	FOR(i, 0, M) {
		cin >> s[i] >> t[i];
		csum[s[i]]++;
		csum[t[i]+1]--;
	}
	FOR(i, 0, N+10) {
		csum[i + 1] += csum[i];
	}
	DD(De(csum));
	// 2以上を列挙
	VI over2(N + 11,0);
	FOR(i, 1, N+10) {
		if (csum[i]>=2)over2[i] = 1;
	}
	DD(De(over2));
	FOR(i, 0, N+10) {
		over2[i + 1] += over2[i];
	}
	DD(De(csum, over2));

	VI ans;
	FOR(i, 0, M) {
		int w = t[i] + 1 - s[i];
		int wsum = over2[t[i]] - over2[s[i]-1];
		DD(de(w, wsum));
		if (w == wsum)ans.push_back(i + 1);
	}
	cout << SZ(ans) << endl;
	for (int i : ans) {
		cout << i << endl;
	}



	return 0;
}
