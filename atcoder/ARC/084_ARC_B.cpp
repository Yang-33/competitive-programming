#include<stdio.h>
#include<math.h>


#define min(a,b) (a<b?a:b)
#define SZ(a) int((a).size())
#define FOR(i, s, e) for (long long (i) = (s); (i) < (e); (i)++)

/* -----  2017/11/04  Problem: ABC 084 B / Link: http://arc084.contest.atcoder.jp/tasks/arc084_b  ----- */
/* ------問題------

K の正の倍数の10 進法での各桁の和としてありうる最小の値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

桁DPではゴリ押せない理由として桁数がめちゃめちゃ大きくてもKの倍数で桁和が45以下になるものがあります。なんか0が入りまくって1000桁とかの数字とかもあり得る
人生おわりです。(めっちゃ高速になるようにしたけど無理だった)
あとc,c++はあまり速度が変わらない？

そうはいかないので、
本当はDPで探索が多すぎて厳しい気持ちになるので、最短経路を考えるらしい。
これは余剰環でみればよい。

----解説ここまで---- */

#define digit 240 //ここを大きくすると通る
int K;
//char dp[digit][100001][2][2];
#define sum ((long long)digit * 100001 * 2 * 2)
char dp[sum];
char target[digit];
char f(int i, int mk, int wa, int lz, int less) {
	if (wa > 45)return 60;
	if (i == -1) {
		if (lz == 1)return 60;
		if (mk == 0)return 0;
		else return 60;
	}

	//	//char &res = dp[i * 100001 * 2 * 2 + mk * 2 * 2 + lz * 2 + less];
	//char &res = dp[i * 100001 * 2 * 2 + mk * 2 * 2 + lz * 2 + less];
	//	char  &res = dp[i][mk][lz][less];
	if (dp[i * 100001 * 2 * 2 + mk * 2 * 2 + lz * 2 + less] != -1)return  dp[i * 100001 * 2 * 2 + mk * 2 * 2 + lz * 2 + less];
	char num = target[i] - '0';
	char Max = less ? 9 : num;
	char res = 60;
	for (char nx = 0; nx < Max + 1; nx++) {
		res = min(res, (char)(nx + f(i - 1, (mk * 10 + nx)>=K? (mk * 10 + nx) % K: (mk * 10 + nx), wa + nx, lz == 1 && nx == 0, less | (nx < Max))));
	}

	return  dp[i * 100001 * 2 * 2 + mk * 2 * 2 + lz * 2 + less] = res;
}
int main() {

	FOR(i, 0, digit - 1)target[i] = '0'; target[digit - 1] = '1';
	scanf("%d", &K);
	FOR(i, 0, sum)dp[i] = -1;
	int ans = f(digit - 1, 0, 0, 1, 0);
	//assert(ans > 0 && ans <= 50);
	printf("%d\n", ans);

	return 0;
}
