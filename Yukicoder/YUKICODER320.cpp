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

/* -----  2018/10/02  Problem: yukicoder 320  / Link: http://yukicoder.me/problems/no/320  ----- */
/* ------問題------

眠れないゆきちゃんは、眠くなるまで羊を数えることにしました。
普通に数えてはつまらないので、フィボナッチ数列状に羊が増えることにして数えました。
つまり、i番目の羊の数は、
a1=1、a2=1、ai=ai−1+ai−2
としてaiで表されます。

しかしゆきちゃんは眠かったために、何度か数え間違いをしてしまいました。
具体的には、ai=ai−1+ai−2−1 (i≥3)のように、1少なく数えてしまうというミスを何度かしました。※

朝起きたゆきちゃんは、N番目まで羊を数えて最後がM匹であることは思い出したのですが、何度間違えたのかが思い出せません。
ゆきちゃんが何度数え間違えたか、あなたはかわりに計算してあげることにしました。

間違いを多く伝えるとゆきちゃんが悲しむので、複数通り考えられる場合はそのうちもっとも小さい数を教えてあげてください。
上記の条件でMになることがない場合は−1を出力してください。

※一度の計算で2以上少なく数えてしまうことはありません
※a1とa2を間違えることはありません

-----問題ここまで----- */
/* -----解説等-----

解法1: ミスの累積はフィボナッチ数であるから、結局ミスの総和を構成できるフィボナッチ数の集合は存在するかという問題になる。
これによって選ばれた集合は、フィボナッチ数であるから最も大きなフィボナッチ数に構成し直すことができる。
よって結局貪欲に撮っていくだけで良い。


上限、下限の枝刈りができるので、分岐限定法で解ける
こういうのを競技プログラミングだと思っている節がある

----解説ここまで---- */


using tp = tuple < LL, LL, LL, LL >;
using tp2 = tuple< LL, LL, LL >;
map<tp2, int> memo;

// 計算があとn回
LL upper(LL a, LL b, LL n) {
	VL sum(n + 2, 0);
	sum[0] = a; sum[1] = b;
	FOR(i, 2, n + 2) {
		sum[i] = sum[i - 1] + sum[i - 2];
	}
	return sum[n+1];
}
LL lower(LL a, LL b, LL n) {
	VL sum(n + 2, 0);
	sum[0] = a; sum[1] = b;
	FOR(i, 2, n + 2) {
		sum[i] = sum[i - 1] + sum[i - 2] - 1;
	}
	return sum[n+1];
}


int f(LL a, LL b, int n, const LL M) {
	if (memo.find(tp2(a, b, n)) != memo.end())return memo[tp2(a, b, n)];

	if (n == 0) {
		if (b == M)return memo[tp2(a, b, n)] = 0;
		else return memo[tp2(a, b, n)] = INF;
	}
	if (upper(a, b, n) < M)return memo[tp2(a, b, n)] = INF;
	if (lower(a, b, n) > M)return memo[tp2(a, b, n)] = INF;



	int res1 = f(b, b + a, n - 1, M);
	int res2 = f(b, b + a - 1, n - 1, M)+1;

	return memo[tp2(a,b,n)] = min(res1, res2);
}

void solve(LL N, LL M) {
	int res = f(1, 1, N - 2, M);
	cout << (res == INF ? -1 : res) << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	solve(N, M);
	return 0;

	VL f(81, 1);
	FOR(i, 3, 81) {
		f[i] = f[i - 1] + f[i - 2];
	}

	LL diffSum = f[N] - M;
	int ans = 0;
	FORR(i, N - 2, 0) {
		if (diffSum - f[i] >= 0) {
			diffSum -= f[i];
			ans++;
		}
	}


	if (diffSum) {
		ans = -1;
	}
	cout << ans << "\n";

	return 0;
}
