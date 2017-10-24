#include "bits/stdc++.h"
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

/* -----  2017/10/23  Problem: nu_5  / Link: http://joi2011ho.contest.atcoder.jp/tasks/joi2011ho5  ----- */
/* ------問題------

あなたは Just Odd Inventions 社を知っているだろうか? この会社の業務は「ただ奇妙な発明 (just odd
inventions)」をすることである．ここでは略して JOI 社と呼ぶ．
JOI 社では多くの微生物を 1 つのシャーレに生きたまま閉じ込める研究をしている．調査対象の微生物
は N 匹存在し，1, 2, · · · , N という番号がついている．各微生物はシャーレに閉じ込められると，foo (fatally
odd object) と呼ばれる有害物質を一瞬のうちにシャーレ内に放出する．各微生物が放出する foo の量は知
られている．シャーレに閉じ込められた全微生物が放出した foo はシャーレ内の各微生物が均等に摂取す
る．各微生物の foo 許容量は知られており，この量を超えて foo を摂取すると微生物は死んでしまう．
微生物 i の foo 放出量は ai ミリグラム，foo 許容量は bi ミリグラムである．すなわち，シャーレに微生物
i1, i2, · · · , ik を閉じ込めたとき，シャーレ内の各微生物はそれぞれ ai1 + ai2 + · · · + aik
kミリグラムの foo を摂取し，シャーレ内の微生物 i は，この摂取量が bi より大きいと死んでしまう．
JOI 社からの委託により，あなたは出来るだけ多くの微生物をシャーレに生きたまま閉じ込めなければ
ならない．ただし，微生物の死骸はシャーレ内の環境に悪影響を及ぼすため，シャーレ内のどの微生物も
foo の摂取で死んではならない．
なお，JOI 社が「ただ奇妙な発明」をすることでどうやって利益を得ているかは，今もって謎であり，JOI
社内でも社長以外の誰も知らない．

-----問題ここまで----- */
/* -----解説等-----

許容量が多い方の集団をとった方がうれしい。
基本的にはこの方針だが、その集団の中には、foo放出量がとても多いものがいる可能性がある。
したがってこの際には許容量の下限を下げて再度計算すればよい。
これは許容量を大きい順にソートした状態で、priorityQueueを用いればよい。
またこれではN回検査をしなければならずO(N^2)だが単調性があるので二分探索をすることでNlogNぐらいになってうれしい。
実際にはO(Nlog(NlogN))ぐらい？

----解説ここまで---- */

LL N;

LL ans = 0LL;

bool f(int x,vector<PLL>p) {// n ok 
	bool ok = 0;
	LL sum = 0;
	priority_queue<LL>q;// subsum max
	FOR(i, 0, x) {
		sum += p[i].second;
		q.push(p[i].second);
	}
	if (sum <= p[x - 1].first*x)return 1;

	FOR(i, x, N) {//swap 
		if (q.top() > p[i].second) {
			sum -= q.top()-p[i].second; q.pop();
			q.push(p[i].second);
		}
		if (sum <= p[i].first*x)return 1;
	}
	return false;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N), b(N);
	vector<PLL>p;
	FOR(i, 0, N) {
		cin >> a[i] >> b[i];
		p.push_back(PLL(b[i], a[i]));
	}
	sort(ALL(p), greater<PLL>());
	/*FOR(i, 0, N) {
		cout << p[i].first << " " << p[i].second << endl;
	}*/

	int l = 0, r = N + 1;
	FOR(i, 0, 20) {
		int mid = (l+r) / 2;
		if (f(mid,p))l = mid;
		else r = mid;
	}
	ans = l;


	cout << ans << "\n";

	return 0;
}
