#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* -----  2017/02/20  Problem: ABC031 D / Link: http://abc031.contest.atcoder.jp/tasks/abc031_d ----- */
/* ------問題------
日本には数字と短い文字列を対応させる語呂合わせの文化がある。

このことに興味を持った高橋君は、1 以上 K 以下の数字のみからなる正整数 v1, v2, ... , vN と
それぞれの正整数に対応する文字列 w1, w2, ... , wN の組 (v1, w1), (v2, w2), ... , (vN, wN) から、どの数字がどの文字列に対応しているかを推論することにした。

すなわち、以下の条件を満たす K 個の文字列 s1, s2, ... , sK を求めたい。

1≦i≦K を満たす任意の整数 i に対して、1≦|si|≦3 を満たす。
1≦i≦N を満たす任意の整数 i に対して、整数 vi を桁ごとに分解した際に得られる数字が上から順に d1, d2, ... , dl としたとき、
文字列 sd1, sd2, ... , sdl をこの順に連結した文字列が wi に等しい。
K 個の文字列 s1, s2, ... , sK を出力するプログラムを作成せよ。

*/
/* -----解説等-----

制約として各文字列skには3文字以下であるという事があるので、
各文字についての大きさがどれだけであるのかを先に決定し、それが
与えられたwに一致するものであるか、大きさが一致していても割り振りが正しいかどうかを確かめる。
この動作はO(3^K)で間に合う。
3bit探索みたい。

*/


ll N, K;
string v[50], w[50];


/* 決定済みの Three を調査 */
bool check(vector<int >& three) {
    /* 決定したサイズがそもそも違う */
    FOR(i, 0, N) {
        int num = 0;
        FOR(j, 0, v[i].size()) {
            num += three[v[i][j] - '0'];
        }
        if (num != w[i].size())return false;
    }
    /* サイズは正しくても割り振りが異なる */
    vector<string> a(K + 1);
    FOR(i, 0, N) {
        int num = 0;
        string s;
        FOR(j, 0, v[i].size()) {
            int idx = v[i][j] - '0';
            if (a[idx].empty()) {
                a[idx] = w[i].substr(num, three[idx]);
            }
            num += three[idx];
            s += a[idx];
        }
        if (s != w[i])return false;
    }

    return true;
}

/* 決定 */
bool dfs(int i, vector<int>& three) {
    if (i == K + 1) return check(three);
    FOR(j, 0, 3) {
        three[i] = j + 1;
        if (dfs(i + 1, three))return true;
    }
    return false;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> K >> N;
    FOR(i, 0, N) {
        cin >> v[i] >> w[i];
    }

    vector<int>Three(K + 1, 0);
    dfs(1, Three);

    vector<string> ans(K + 1);
    FOR(i, 0, N) {
        int num = 0;
        FOR(j, 0, v[i].size()) {
            int idx = v[i][j] - '0';
            if (ans[idx].empty()) {
                ans[idx] = w[i].substr(num, Three[idx]);
            }
            num += Three[idx];
        }
    }

    FOR(i, 1, K+1) {
        cout << ans[i] << endl;
    }

    return 0;
}