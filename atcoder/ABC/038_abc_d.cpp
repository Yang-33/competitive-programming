#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define MOD 1000000007
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/29 問題 ----- ABC038 D /Link http://abc038.contest.atcoder.jp/tasks/abc038_d */
/* -----解説等-----
問題: 高橋くんはプレゼントを用意することになりました。
プレゼントの中身はすでに決まり、あとはプレゼントを入れる箱を用意するだけです。
高橋くんが使える箱はN個あり、i番目の箱は縦hicm×横wicmのサイズです。

プレゼントがより多くの箱に入っていたほうが面白いと考えた高橋くんは、
なるべく多くの箱を入れ子にし、最も内側の箱にプレゼントを入れることにしました。
ある箱は、縦・横ともにより大きいサイズの箱にのみ入れることができます。
また、ある箱は1つまでしか他の箱を入れることはできません。
プレゼントを入れる箱を最大で何重の入れ子にできるか答えてください。


まずは片側についてソートをして、箱を入れる順序を決定する。
この際、もう片側の辺については順序がLICで処理できるようになっていてほしく、また同じ箱の大きさでは
箱に入れることができないという制約から、各Wについて降順にすればよい。

INFのところで一回墜ちたのが良くない考察だった。

http://mayokoex.hatenablog.com/entry/2016/05/28/230000
というようなsegtreeやBITで解くという方針も存在する。ソートしたことで区間が生じていることに着目したもので
logサイズで検索をかけられるのがミソ。おもしろい。重複区間を数え上げてFOR iをずらしていくのもおもしろい。

*/

#define MAX_N 100001
#define INF INT_MAX/2
int N;
int h, w;
vector<pair<int, int>> b;
vector<int> a(MAX_N);
int x[MAX_N + 1];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N) {
        cin >> w >> h;
        b.push_back(make_pair(w, -h));
    }

    sort(b.begin(), b.end());
    FOR(i, 0, N) {
        a[i] = -b[i].second;
    }


    fill(x, x + MAX_N + 1, INF);
    x[0] = -INF;
    
    FOR(i, 0, N) {
        *lower_bound(x, x + MAX_N + 1, a[i]) = a[i];
    }

  /*  FOR(i, 0, N+1) {
        if (x[i] == INF) {
            cout << i-1 << endl;
            return 0;
        }
    }*/


    FORR(i, N, 0) {
        if (x[i] < INF) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}