#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <climits> //INT_MIN/MAX
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define mp make_pair
const int INF = 1e9;
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

/* -----  2017/04/11  Problem: NagoyaU contest 4 D  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2612  ----- */
/* ------問題------

負けず嫌いのイクタ君は、最近囲碁盤を使って遊ぶゲームに熱中している。
しかし、囲碁も五目並べも友人に全く勝てないので、あまり有名でない Phutball というゲームの特訓をすることにした。

このゲームは難しいゲームなので、手始めに自分のターンに勝って終局できるかを判定できるように特訓することにした。

ゲームの勝利条件は以下のようなものである。

白石は黒石の置かれている場所にジャンプすることは出来ない。
碁盤の中央の19×15の部分を用いる。
勝利条件を判定したい碁盤は白石が1つと黒石がいくつか置かれた状態で与えられる。
ゴール地点というのは碁盤の下端か、その下側を指す。（下図を参照せよ。）
ゴール地点に白石を運べば勝利する。
勝利するために以下のようなことを行う。
白石は1回以上ジャンプを行うことができる。
ジャンプは白石に隣接する8方向（上下左右と斜め上、斜め下）の黒石のどれかを飛び越えることで行える。
黒石が隣接していない方向へジャンプすることは出来ない。
飛び越えられた黒石は、1回のジャンプごとに碁盤の上から取り除かれる。
ジャンプしたあとの白石はゴール地点かゲーム盤の上に存在しなければいけない。
黒石が2個以上連続していても、ちょうどそれをまたぐようにジャンプできる。
白石は黒石の置かれている場所にジャンプすることは出来ない。(ジャンプする方向に連続している黒石は必ず飛び越えなくてはならない。)

図の丸印がついている場所へはジャンプすることが可能であり、全てゴール地点であるが、バツ印の場所はゴール地点でもなく、碁盤の内側でもないので、ジャンプすることは出来ない。

あなたの仕事はイクタ君の特訓を手助けするために、ゴールできるかどうかの判定と、ゴールするための最小のジャンプ回数を求めるプログラムを書いてあげる事である。
黒石の数が20以下。
白石は必ず1つだけ存在する。
すでにゴールした状態が入力されることはない。

-----問題ここまで----- */
/* -----解説等-----

各黒石に番号を振っておく。黒石が２０個以下であることが保証されているので、
このすべてについてを管理することができそうである。
また、移動についてを見ていくと、移動可能なマスには移動経路によらず一度しか訪れない。
飛び越したものを集合で管理し、bitDP[XXXXXX] := この状態からゴールに到達できる際の最小移動回数
として計算をしていけばよい。
また移動した際に黒石を消していくのでｄｆｓで掘り下げる際に消して、元に戻ってきたら復元してある必要がある。
うまくやればdfsでもbfsでもできそう。

----解説ここまで---- */

int h,w;
vector<string> t(20);
map<pii,int>m;
int bD[1<<22];
bool visit[1<<22];

int dfs(int y,int x,int now){
  if(y==h||(y==h-1&&0<=x&&x<w))return 0;
  if(x<0||y<0||w<=x||h<=y){
    //    cout<<x<<" "<<y<<" "<<now<<endl;
    return INF;
  }
  if(visit[now]){return bD[now];}else  visit[now]=true;
  
  int res=INF;
  FOR(i,0,8){
    int nx=x+dx[i];int ny=y+dy[i];
    int next=now;
    if(nx<0||ny<0||w<=nx||h<=ny)continue;
    if(t[ny][nx]!='X')continue;
    vector<string> orig=t;
    while((!(nx<0||w<=nx||ny<0||h<=ny))&&t[ny][nx]=='X'){// skip
      t[ny][nx]='s';
      next|=(1<<m[mp(ny,nx)]);
      nx+=dx[i];ny+=dy[i];
    }
    res=min(res,1+dfs(ny,nx,next));
    t=orig;

  }


  return bD[now]=res;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  h=19;w=15;
  FOR(i,0,1<<22)visit[i]=false;

  FOR(i,0,h)cin>>t[i];

  int num=0;
  int tx,ty;
  FOR(i,0,h)FOR(j,0,w){
    if(t[i][j]=='X')m[mp(i,j)]=num,num++;
    else if(t[i][j]=='O'){
      ty=i;tx=j;
    }
  }

  int ans=dfs(ty,tx,0);

  if(ans>=INF)cout<<-1<<endl;
  else cout << ans << endl;

  return 0;
}
