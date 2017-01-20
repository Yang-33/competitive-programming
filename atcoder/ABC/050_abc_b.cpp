#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2010/00/00 問題 -----  ABC 050 B /Link http://abc050.contest.atcoder.jp/tasks/abc050_b */
/* -----解説等-----
問題:oisinoお姉ちゃんは、あるプログラミングコンテストの決勝を控えています。
このコンテストでは、N 問の問題が用意されており、それらには 1~N の番号がついています。
joisinoお姉ちゃんは、問題 i(1≦i≦N) を解くのにかかる時間が Ti 秒であることを知っています。

また、このコンテストでは、M 種類のドリンクが提供されており、1~M の番号がついています。
そして、ドリンク i(1≦i≦M) を飲むと、脳が刺激され、問題 Pi を解くのにかかる時間が Xi 秒になります。
他の問題を解くのにかかる時間に変化はありません。

コンテスタントは、コンテスト開始前にいずれかのドリンクを 1 本だけ飲むことができます。
joisinoお姉ちゃんは、それぞれのドリンクについて、それを飲んだ際に、全ての問題を解くのに何秒必要なのかを知りたくなりました。 全ての問題を解くのに必要な時間とは、それぞれの問題を解くのにかかる時間の合計です。 あなたの仕事は、joisinoお姉ちゃんの代わりにこれを求めるプログラムを作成することです。

ans:
問題の制約から添え字がごちゃごちゃしているが
総和をとってドリンクの部分を差をとって訂正するだけ。

*/

int N;
int T[100000];
int M;
int P[100000], X[100000];
ll sum = 0, ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N) {
        cin >> T[i];
        sum += T[i];
    }

    cin >> M;
    FOR(i, 0, M) {
        cin >> P[i] >> X[i];
        ans = sum-T[P[i]-1]+X[i];
        cout << ans << endl;
    }

    return 0;
}