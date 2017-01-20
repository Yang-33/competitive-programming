#include<iostream>

using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define MOD 1000000007
typedef long long ll;

/* 2017 01/19 問題 ----- ABC 050 C /Link http://abc050.contest.atcoder.jp/tasks/arc066_a */
/* -----解説等-----
問題: 1~N までの番号がついた、N 人の人がいます。
彼らは昨日、ある順番で左右一列に並んでいましたが、今日になってその並び方が分からなくなってしまいました。
しかし、彼らは全員、「自分の左に並んでいた人数と自分の右に並んでいた人数の差の絶対値」を覚えています。
彼らの報告によると、人 i の、「自分の左に並んでいた人数と自分の右に並んでいた人数の差の絶対値」は Ai です。

彼らの報告を元に、元の並び方が何通りあり得るかを求めてください。 ただし、答えは非常に大きくなることがあるので、109+7 で割った余りを出力してください。
また、彼らの報告が間違っており、ありうる並び方がないこともありえます。 その際は 0 を出力してください。

制約
1≦N≦10^5
0≦A_i≦N?1

元の並び順としてありうるものが何通りあるか求め、109+7 で割った余りを出力せよ。

正確な順番を復元した際、区別をしない置き方は一意に定まる。
以下の条件を満たさねばならない
N:奇数のとき　正の偶数が N/2 種類(2こ) + 0
N:偶数のとき　正の奇数が N/2 種類(2こ) +
組み合わせは2^(2/N).
場合分けとチェックを繰り返す。

*/

int N;
ll ans = 1;
bool flag = true;
int cnt[100000 / 2];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    if (N % 2 == 0) {
        FOR(i, 0, N) {
            int a; cin >> a;

            if (a % 2 == 0 || a > N)flag = false;

            cnt[a / 2]++;
        }
        
        FOR(i, 0, N / 2) {
            if (cnt[i] != 2)flag = false;
        }
        FOR(i, 0, N / 2) {
            ans = (ans * 2) % MOD;
        }

    }
    else {
        int zero = 0;
        FOR(i, 0, N) {
            int a; cin >> a;

            if (a % 2 == 1 || a > N)flag = false;
            if (a != 0) {
                cnt[a / 2]++;
            }
            else zero++;
        }
        FOR(i, 1, N / 2+1) {
            if (cnt[i] != 2)flag = false;
        }
        if (zero != 1)flag = false;
        FOR(i, 0, N / 2) {
            ans = (ans * 2) % MOD;
        }

    }


    if (flag == false)ans = 0;
    cout << ans << endl;

    return 0;
}