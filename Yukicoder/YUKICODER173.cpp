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

/* -----  2018/07/28  Problem: yukicoder 173  / Link: http://yukicoder.me/problems/no/173  ----- */
/* ------問題------

A君とB君はカードゲームが好きである．
このカードゲームでは 1 から 1000 までの整数が 1 つずつ書かれた 1000 枚のカードが存在する．
最初にA君とB君にはそれぞれ N 枚ずつカードが配られる．
ゲームはとってもとってもとっても簡単である．
ゲームは N 試合からなる．
各試合では自由にカードを 1 枚出して書かれている整数の大きい方がその試合の勝者で，出された 2 枚のカードに書かれている整数の和が得点として得られる．
試合で 1 度出したカードは 2 度使えない．
N 試合が終わった後で得られた合計得点が大きい方がこのゲームの勝者となる（同点なら勝者なし）．
カードはすでに配られた状態でA君に配られたカードは A1,A2,…,AN で，B君に配られたカードは B1,B2,…,BN ある．
A君がこのゲームで勝つ確率を計算せよ．
ただし，A君もB君も小さいカードを早めに使用する癖があり，以下の様な方法で各試合に出すカードを選ぶものとする．
A君もB君も，使えるカードが 1 枚しかない場合は，必ずそのカードを出す．
A君は，使えるカードが 2 枚以上ある場合は，その中で最も小さい整数が書かれたカードを確率 PA で出し，その他のカードを選ぶ確率は全て等しい．
B君は，使えるカードが 2 枚以上ある場合は，その中で最も小さい整数が書かれたカードを確率 PB で出し，その他のカードを選ぶ確率は全て等しい．
A君も，B君も，今までのゲームの結果，現在のカードの状況等に出すカードは影響されず，それらと独立に出すカードを選ぶ．

-----問題ここまで----- */
/* -----解説等-----

学び:乱数発生器は生成に時間がかかる
モンテカルロ法をする。
許容誤差は4σぐらいがいいらしい。
今回はσ= 0.5/sqrt(N)なので、0.005 = 4σ=2/sqrt(N) から、N = 10^6がよい。
が5000でも通りました。(a)

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	double PA, PB; cin >> PA >> PB;
	VI a(N), b(N);
	int sum = 0;
	FOR(i, 0, N) {
		cin >> a[i];
		sum += a[i];
	}
	FOR(i, 0, N) {
		cin >> b[i];
		sum += b[i];
	}
	SORT(a);
	SORT(b);
	double ans = 0;
	const double TI =5000;
	random_device rnd;
	mt19937 mt(rnd());

	FOR(ti, 0, TI) {
		int Apoint = 0;
		int Acard = (1 << N) - 1;
		int Bcard = (1 << N) - 1;

		auto getCardId = [&N,&mt](double A ,int state) {
			int sz = __builtin_popcount(state);
			
			int left = 0;
			// Pa ,1/(sz-1)(1-Pa),1/(sz-1)(1-Pa),1/(sz-1)(1-Pa)
			int sp = mt()%10000;
			if (sz == 1)left = 0;
			else if (sp < A * 10000) {
				left= 0;
			}
			else {
				left =1+ mt() % (sz-1);
			}

			FOR(i, 0, N) {
				if (state & 1 << i) {
					if (!left)return i;
					else left--;
				}
			}
			return 0;
		};

		FOR(i, 0, N) {
			int ca = getCardId(PA, Acard);
			int cb = getCardId(PB, Bcard);
			Acard &= ~(1 << ca);
			Bcard &= ~(1 << cb);
			if (a[ca] > b[cb]) {
				Apoint += a[ca] + b[cb];
			}
		}
		if (Apoint * 2 > sum) {
			ans++;
		}
	}

	ans /= TI;
	cout <<fixed<<setprecision(10)<< ans << "\n";

	return 0;
}
