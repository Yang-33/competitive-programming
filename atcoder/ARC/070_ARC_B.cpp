#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

typedef long long ll;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define debug(x) cout<<#x<<": "<<x<<endl

/* ----- 2017/03/18  Problem: ARC070 B / Link: http://arc070.contest.atcoder.jp/tasks/arc070_b ----- */
/* ------蝠城｡---

シカのAtCoDeerくんは正整数が書かれたカードを N 枚持っています。i(1≦i≦N) 枚目に書かれている数は ai です。 
tCoDeerくんは大きい数が好きなので、カードに書かれた数の総和が K 以上になるようなカードの部分集合をよい集合と呼びます。
そして、各カード i に対して、そのカードが不必要かどうかを次のように判定します。
「カード i を含む任意のよい集合に対して、その集合からカード i を除いたものもよい集合」 ならカード i は不必要
それ以外の場合は、不必要でない
不必要なカードの枚数を求めてください。ただし、それぞれの判定は独立に行われ、不必要だからと言ってカードが途中で捨てられたりすることはありません。


-----問題ここまで----- */
/* -----解説等-----

a[i]を除いた数で、ある選び方をしたときにできた数 X[-a[i]] が,K未満で この X[-a[i]] + a[i] が K以上であるならば
a[i]は必要な数とみなすことができる。
各数を調査するとしてこの X[-a[i]]を生成するのに必要な時間は DP で Ｏ(KN)であるため総合でＯ(N^2*K)を要してしまうが
適切なデータの持ち方をすることでこの判定を行うための条件となる数の生成時間を短縮することができる。
当初ｄｐを短縮しようと思いmapを用いたがこれは嘘解法で　X[-a[i]] と X[-a[i]] + a[i] が存在すれば X[-a[i]] は a[i] なしで生成できる数である
と考えていた。
が　A={3,4,11},K=11で 7=>11 は７の生成に４が必要であるために嘘

コンテスト後この部分は昇順に並び替え うまく a[i] を用いず K 未満の数を生成し,a[i] を足し合わせたときにこれが K を超えるか確認すれば
よいという設定にすれば Ｏ(N*K)で判定できることに気が付いた。二分探索っぽい

ほかの回答ではaを並び替えれば aの大きさから不必要なものを二分できるので NKlogN で計算できるものもあった

----解説ここまで---- */

ll N, K;
map<ll, ll> m[2];

ll a[5000];
ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	FOR(i, 0, N) {
		cin >> a[i];
	}

	sort(a, a + N);
	reverse(a, a + N);
	FOR(i, 0, N) {
		ll tmp = 0;
		FOR(j, 0, N) {
			if (i == j)continue;
			if (tmp + a[j] < K) {
				tmp += a[j];
			}
		}
		if (tmp + a[i] >= K) {
			ans++;
		}
	}
	//m[0][0] = 0;
	//m[1][0] = 0;
	//cout << "afdf11" << endl;

	//int qq;
	//FOR(i, 0, N) {
	//	ll p = a[i];
	//	qq = i % 2;
	//	auto it = m[qq].begin();
	//	debug(m[qq].size());
	//	debug(qq);



	//	FOR(z, 0, m[qq].size()) { // !?
 //			m[(qq + 1) % 2][(*it).first] = (*it).first;
	//		m[(qq + 1) % 2][(*it).first + p] = (*it).first + p;
	//		it++;
	//	}

	//}
	//FOR(i, 0, N) {

	//	FOR(x, K - a[i], K) {
	//		if (m[(N) % 2].count(x) != 0 && m[(N) % 2].count(x + a[i]) != 0 && x + a[i] >= K) {
	//			ans++;
	//			break;
	//		}

	//	}


	//}

	cout << N - ans << endl;

	return 0;
}
