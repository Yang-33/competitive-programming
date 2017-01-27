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
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/27 問題 ----- ABC040 D /Link http://abc040.contest.atcoder.jp/tasks/abc040_d */
/* -----解説等-----
問題: ある国には N 個の都市があり、それぞれ 1 から N までの番号がつけられています。
これらの都市間を結ぶ M 本の道路があり、i 本目の道路は都市 ai と都市 bi を結ぶもので、yi 年に造られたものです。
この国の国民はとても心配性なので、あまりに古い道は事故の危険性が高いと考えて使わないことがあります。
そこであなたは、この国の交通状況を調査することにしました。

Q 人の国民の情報が与えられます。j 人目の国民について、都市 vj に住んでおり、
造られた年が wj 年以前 (wj 年ちょうども含む) であるような道路を使わないことがわかっています。
それぞれの国民に対し、その人が住んでいる都市から道路のみを使って行き来できるような都市の個数を求めてください。


時系列順にソートあるいは並び替えてUF.
新しい橋から順番にたてていき、人の出す希望をsizeとして求めていけばよい。
今回のUFは集合の大きさをマイナスで保管し、符号を訂正することで集合の大きさを知ることができる。
マイナスにすることで一つの配列で正の値では根番号、負の値では集合の大きさを表すことができる仕様。

*/

#define MAX_V 100010
int pir[MAX_V];//親、あるいは集合の番号

void init(int n) {
    FOR(i, 0, n) {
        pir[i] = -1;
    }
}

int root(int x) {
    if (pir[x] < 0) {
        return x;
    }
    else {
        return pir[x] = root(pir[x]);
    }
}

void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
        if (pir[y] < pir[x]) swap(x, y);
        pir[x] += pir[y];
        pir[y] = x;
    }
}

bool same(int x, int y) {
    return root(x) == root(y);
}

int size(int x) {
    return -pir[root(x)];
}

//
//int sizes[MAX_V];//深さ
//
//void init(int n) {
//    FOR(i, 0, n) {
//        par[i] = i;
//        sizes[i] = 1;
//    }
//}
///* xの根を返すあるいは集合 */
//int find(int x) {
//    if (par[x] == x) {
//        return x;
//    }
//    else {
//        return par[x] = find(par[x]);
//    }
//}
///* 集合x,yを併合する。 */
//void unite(int x, int y) {
//    x = find(x);
//    y = find(y);
//    if (x == y)return;
//    if (sizes[x] > sizes[y])swap(x, y);
//
//    par[y] = x;
//    sizes[x] += sizes[y];
//    //sizes[y] = 0;
//}
//
////同じ集合かの判定
//bool same(int x, int y) {
//    return find(x) == find(y);
//}
///* 根xを元にするグラフの大きさ */
//int size(int x) {
//    return sizes[find(x)];
//}

#define MAX_M 200001
#define MAX_Q 100000
int N, M;
int a[MAX_M], b[MAX_M], y[MAX_M];
int Q;
int v[MAX_V], w[MAX_V];
vector<vector<pair<int, int>>> edge(MAX_M);
vector<vector<pair<int, int>>> query(MAX_M);
int ans[MAX_Q];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N >> M;
    init(N);

    FOR(i, 0, M) {
        cin >> a[i] >> b[i] >> y[i];
        a[i]--; b[i]--;
        edge[y[i]].push_back(make_pair(a[i], b[i]));
    }

    cin >> Q;
    FOR(i, 0, Q) {
        cin >> v[i] >> w[i];
        v[i]--;
        query[w[i]].push_back(make_pair(v[i], i));
    }

    FORR(i, MAX_M - 1, -1) {
        FOR(j, 0, query[i].size()) {
            ans[query[i][j].second] = size(query[i][j].first);
        }
        FOR(k, 0, edge[i].size()) {
            unite(edge[i][k].first, edge[i][k].second);
        }
    }

    FOR(i, 0, Q) {
        cout << ans[i] << endl;
    }

    return 0;
}