#include<iostream>
#include<string>
//#include<bitset>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/21 問題 ----- ABC045 C /Link http://abc045.contest.atcoder.jp/tasks/arc061_a  */
/* -----解説等-----
問題: 1 以上 9 以下の数字のみからなる文字列 S が与えられます。
この文字列の中で、あなたはこれら文字と文字の間のうち、いくつかの場所に + を入れることができます。
一つも入れなくてもかまいません。 ただし、+ が連続してはいけません。

このようにして出来る全ての文字列を数式とみなし、和を計算することができます。

ありうる全ての数式の値を計算し、その合計を出力してください。

制約
1?|S|?10
S に含まれる文字は全て 1 ? 9 の数字


Sが小さい。
全列挙をする。=> 2^10≒10^3
now = now*10 + s[i] として頭の数から足しこんでいき、
「+」が入る場所に関して足す数をリセットして足しこむことを繰り返す。

(1<<(-1))はコーナーかなあと思ったけど落ちなかった。
確認したら 1<<-1は未定義で０
j=0 で 1<<(j-1)は INT_MIN であった => -2,147,483,648
が、二進数表示は０であった => 0
そもそも非負整数でシフトするのだから　例外や未定義により　1<<n (n={x|x≦0}) は ０ として今はとりあえずよいだろう。

*/

string S;
ll ans = 0;
int n;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> S;
    n = S.size();
    
    /*int j = 0;
    cout << "1<<(-1) : " << (1 <<( j-1)) << endl;
    cout << static_cast<bitset<8> >(1<<(j-1)) << endl;
　　*/

    for (int i = 0; i < (1 << (n - 1)); i++) {
        ll sum = 0; ll cur = 0;

        FOR(j, 0, n) {
            if (j == 0) {
                cur = S[j] - '0';
                continue;
            }
            if (i & (1 << (j - 1))) {
                sum += cur;
                cur = 0;
            }
            cur = cur * 10 + (S[j] - '0');
        }
        sum += cur;
        ans += sum;
    }

    cout << ans << endl;

    return 0;
}