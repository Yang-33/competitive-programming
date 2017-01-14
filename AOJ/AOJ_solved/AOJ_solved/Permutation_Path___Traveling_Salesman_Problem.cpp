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
#define llong long long
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;
llong N;

/* 2017/01/11 問題 DPL_2_A  Name/Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A ----- */
/* -----解説等-----
問題: 巡回セールスマン問題
重み付き有向グラフ G(V,E) について、以下の条件を満たす最短経路の距離を求めて下さい：

ある頂点から出発し、出発点へ戻る閉路である。
各頂点をちょうど１度通る。

|V|, |E| はそれぞれグラフ G の頂点の数と辺の数を示す。
グラフ G の頂点にはそれぞれ 0, 1, ..., |V|-1 の番号が付けられている。

s_i, t_i はグラフ G の i 番目の辺が結ぶ２つの頂点を表す（有向）。
d_i は s_i と t_i の間の距離　（i 番目の辺の重み）である。


最短経路の距離を1行に出力する。条件を満たす経路がない場合は -1 と出力する。

制約
2 ? |V| ? 15
0 ? d_i ? 1,000
G に多重辺はない


---------------------------------------------------






*/
ll V, E;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N;

    cout << N << endl;

    return 0;
}