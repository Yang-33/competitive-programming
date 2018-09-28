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

/* -----  2018/09/28  Problem: yukicoder 295  / Link: http://yukicoder.me/problems/no/295  ----- */
/* ------問題------

文字列Sの連結成分の個数を、次の操作を行えるだけ行った後の文字列長さとして定めます。
操作：同じ文字が2文字以上連続する箇所があれば、そこから1文字取り除く
例えば「helloworld」の連結成分の個数は9、「aababbaaa」の連結成分の個数は5となります。
S の T 数を文字列 S が含む部分列 T の個数とします。
例えば、Sをhelloworld、Tをhelworld とすると、helloworldはhel__worldとhe_l_worldの2つを部分列として持つので、helloworld の helworld 数は 2 です。

文字列 S の各アルファベットの文字数 と 文字列 T が与えられます。
次の2条件を満たす文字列Sに対する、T数の最大値を求めてください。
・Sに含まれる文字alphaの個数は高々Salpha
・Sの連結成分の個数とTの連結成分の個数は等しい
ただし、答えが非常に大きくなる場合があるので 262 以上になる場合は"hel"を出力してください。

-----問題ここまで----- */
/* -----解説等-----

あるアルファベットに着目する。すると以下の問題を得る。
a1+a2+a3+...+an=A(Tの'a'の総和)
今、a1'+a2'+a3'+...+an'=A'(Sの'a'の総和)があるので、これを割り振り、以下を最大化したい
s.t. ai≦ai' 
max  Π'Combination (ai',ai)
これは増分を考えるとpriority_queueでできる。

また、これはシュミレーションしないといけないので、A'が非常に大きいときはできない。
しかし、大きいときは大体MAX=2^62を超えるので、超えない場合だけを考えれば良い。
割り振り先が少ないときのみ、Maxにならない場合になりうるのでこれを試せば良い。

----解説ここまで---- */

using LLL = __int128;
const LLL Max = 1LL << 62;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	VL a(26);
	FOR(i, 0, 26) {
		cin >> a[i];
	}
	string t; cin >> t;
	{
		VI alphanum(26);
		FOR(i, 0, SZ(t)) {
			alphanum[t[i] - 'a']++;
		}
		FOR(i, 0, 26) {
			if (alphanum[i] > a[i]) { cout << 0 << endl; return 0; }
		}
	}
	{
		VVI alpha(26);
		alpha[t[0] - 'a'].push_back(1);
		FOR(i, 0, SZ(t) - 1) {
			if (t[i] == t[i + 1]) {
				alpha[t[i] - 'a'].back()++;
			}
			else {
				alpha[t[i + 1] - 'a'].push_back(1);
			}
		}


		struct Frac {
			LLL n, d;
			Frac(LL n, LL d) :n(n), d(d) {}
			bool operator < (const Frac& a) const { return n * (a.n - a.d) < (n - d)*a.n; }
		};

		// sectionに対して、section(i)<=a[i]となるようにaを割り振る
		auto f = [](LLL a, const VI& section) ->LLL {
			LLL ret = 1;
			if (!SZ(section))return 1;


			if (a > 5e6) {
				if (SZ(section) == 1) {
					if (section.front() == 1)return a;
					if (section.front() == 2)return a * (a - 1) / 2;
					LLL ret = a * (a - 1)*(a - 2) / 6;
					assert(ret >= Max);
					return Max;
				}
				if (SZ(section) == 2) {
					if (section.front() == 1 && section.back() == 1) {
						return (a) / 2 * (a - a / 2);
					}
				}

				return Max;
			}


			priority_queue<Frac, vector<Frac>>pq;
			FOR(i, 0, SZ(section)) {
				a -= section[i];
				pq.push(Frac(section[i] + 1, section[i]));
			}
			while (a > 0) {
				Frac high = pq.top(); pq.pop();
				ret = ret * high.n / (high.n - high.d);
				if (ret >= Max)return Max;
				high.n++;
				pq.push(high);
				a--;
			}
			return ret;
		};
		LLL ans = 1;

		FOR(i, 0, 26) {
			LLL ret = f(a[i], alpha[i]);
			if (ret >= Max) { cout << "hel" << endl; return 0; }
			ans *= ret;
			if (ans >= Max) { cout << "hel" << endl; return 0; }
		}

		cout << (LL)ans << "\n";

	}



	return 0;
}
