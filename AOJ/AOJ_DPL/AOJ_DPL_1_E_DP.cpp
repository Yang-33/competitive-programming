#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;
ll N;

/* 2016/12/31 問題 ----- AOJ_DPL_1_E  Name/Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E&lang=jp ----- */
/* -----解説等-----
問題: 編集距離
２つの文字列 s1、s2 の編集距離（レーベンシュタイン距離）を求めて下さい。

編集距離とは、以下３種類の操作によって、１つの文字列を別の文字列に変形するのに必要な手順の最小回数です：

挿入: 文字列に１つの文字を挿入する。
削除: 文字列から１つの文字を削除する。
置換: 文字列の中の１文字を別な文字に置き換える。

部分問題に帰着できるのでDP
dp[i][j] := str1のi文字とstr2のj文字まで見たときの 編集距離
=> Ｏ(STR1*STR2)

*/
#define MAX_N 1000 
string str1, str2;
ll dp[MAX_N + 1][MAX_N + 1];
ll L1, L2;//L1,L2.size()

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> str1 >> str2;
    L1 = str1.size(); L2 = str2.size();

    //自明な初期条件
    FOR(i, 0, L1 + 1)dp[i][0] = i;
    FOR(i, 0, L2 + 1)dp[0][i] = i;

    FOR(i, 1, L1 + 1) {
        FOR(j, 1, L2 + 1) {
            ll cost;
            if (str1[i - 1] == str2[j - 1])cost = 0;
            else cost = 1;
            dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + cost);
        }//dp[i][j]には dp[i-1][j-1] において文字が一致しなければ＋１、一致で　＋０
        //また、substr1 +1 = substr2 のときsubstr1に一文字追加(+1)でdp[i][j]に
        //また、substr1 = substr2 -1 のときsubstr2を一文字削除(+1)でdp[i][j]に
        //この三つのうち最小のものをとればよい。
    }


    cout << dp[L1][L2] << endl;

    return 0;
}