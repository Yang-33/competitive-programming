#include<iostream>
#include<string>
using namespace std;


/* 2017/01/20 問題 ----- ABC048 D /Link http://abc048.contest.atcoder.jp/tasks/arc064_b */
/* -----解説等-----
問題: 長さ 3 以上の文字列 s があります。 s の中に同一の文字が隣り合う箇所はありません。

高橋君と青木君がゲームで勝負します。 二人は交互に次の操作を行います。 高橋君が先手です。

s から両端以外の文字をひとつ取り除く。 ただし、その文字を取り除くことで、s の中に同一の文字が隣り合う箇所ができる場合、その文字を取り除くことはできない。
先に操作を行えなくなった人が負けです。 二人が最適に行動したとき、どちらが勝つかを判定してください。

制約
3≦|s|≦105
s は英小文字のみからなる。
s の中に同一の文字が隣り合う箇所はない。

膠着状態はabababのような二文字の繰り返しとなるもの
abababcabababaであればacaまで削減可能(11こ)=>２人目の負け
ababcabcabababaであればacacaまで削減可能(10こ)=>1人目の負け
ababxyabab=>ab(8)=>1
ababxyaba=>aya(6)=>1

ababxabab=>ab(7)=>2
ababxaba=>axa(5)=>2
文字列の両端が一緒 　=> {偶数、奇数} => {2負け、1負け}
文字列の両端が異なる => {偶数、奇数} => {1負け、2負け}

判定可能であるが正当性が示せない...！


*/

string S; int slen;
int p;
string ans;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> S;
    slen = S.size();
    if (S[0] == S[slen - 1] && slen % 2 == 1 || S[0] != S[slen - 1] && slen % 2 == 0)p = 2;
    else p = 1;

    if (p == 1)ans = "First";
    else ans = "Second";
    cout << ans << endl;

    return 0;
}