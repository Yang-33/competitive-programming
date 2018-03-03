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

/* -----  2018/03/03  Problem: 001_apc_c / Link: https://apc001.contest.atcoder.jp/tasks/apc001_c?lang=en  ----- */
/* ------問題------

N を 3 以上の奇数とします。
N 個の席が円状に並んでいます。 席には 0 から N−1 まで番号が振られています。 各 i (0≤i≤N−2) について、席 i と席 i+1 は隣り合っています。 また、席 N−1 と席 0 は隣り合っています。
各席の状態は「空席」「男性が座っている」「女性が座っている」のどれかです。 ただし、同性どうしが隣り合う席に座っていることはありません。 N が 3 以上の奇数の場合、空席が少なくとも 1 つは存在することが示せます。
あなたには N のみが与えられ、各席の状態は与えられません。 あなたの目標は、どれか 1 つの空席の番号を当てることです。 そのために、あなたは次のクエリを繰り返し送ることができます。
整数 i (0≤i≤N−1) を選ぶ。 席 i が空席ならば、正答となる。 そうでなければ、席 i に座っている人の性別が知らされる。
クエリを高々 20 回まで送ることで、どれか 1 つの空席の番号を当ててください。

-----問題ここまで----- */
/* -----解説等-----

隣接する二点を決めたとき、長い方のパスで一点決めたときの性別から空席の位置がわかる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

bool react(int x) {
	cout << x << endl;
	string ret;
	cin >> ret;
	if (ret == "Vacant") exit(0);
	return (ret == "Male");
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	bool start = react(0);
	react(N - 1);
	int low = 1, high = N;

	while (1) {
		const int mid = (low + high) / 2;
		bool cur = react(mid);
		if (mid % 2 == (start != cur)) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}

	return 0;
}
