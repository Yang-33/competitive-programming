#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* -----  2017/03/02  Problem: ABC009 C / Link: https://abc009.contest.atcoder.jp/tasks/abc009_3 ----- */
/* ------問題------

文字列の辞書式順序による比較についてはご存知だろうか？知らない場合は ABC007 の B 問題にその定義が載っているので読むとよいだろう。
今回は、この辞書式順序が重要な役割を果たす問題を解いてもらいたいと思う。
まず、英小文字（a-z）のみからなる N 文字の文字列 S が与えられる。
S=S1,?S2,?…,?SN の文字を並び替えて作れるような文字列 T=T1,?T2,?…,?TN のうち、辞書順で最小になるようなものを求めてほしい。
ただし、並び替え方には 1 つだけ制限がある。別に整数 K が与えられ、元から位置の変わった文字の個数を K 以下にしなければならない。
つまり、Si≠Ti となるような（文字が不一致となるような） i （1≦i≦N）の個数が K 以下であるような並び替え方しかできない。

-----問題ここまで----- */
/* -----解説等-----

変更が K こ以下でなくてはならないが、そうである保証を得ることができないので
コンピューターパワーで殴る。

 ----解説ここまで---- */

ll N, K;

string s;

bool C(const string &t, map<char, int>& M) {
    int Count = 0;
    for (int i = 0; i < t.size(); i++) {
        Count += (s[i] != t[i]);
    }
    map<char, int> L;
    for (int i = t.size(); i < N; i++) L[s[i]]++;
    Count += N - t.size();
    for (char c = 'a'; c <= 'z'; c++) {
        Count -= min(M[c], L[c]);
    }
    return Count <= K;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> K;
    cin >> s;
    map<char, int> M;
    for (int i = 0; i < N; i++) M[s[i]]++;
    string t;
    for (int i = 0; i < N; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (M[c] == 0) continue;
            M[c]--;
            if (C(t + c, M)) {
                t.push_back(c);
                break;
            }
            else M[c]++;
        }
    }
    cout << t << endl;
    return 0;
}