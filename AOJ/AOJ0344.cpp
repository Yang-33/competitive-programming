#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/01/15  Problem: AOJ 0344 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0344  ----- */
/* ------問題------

あなたは所属するプログラミング部の部室から古びたボードゲームを発見しました。面白そうなので遊んでみることにしました。 
このゲームは M 個のイベントから成り、時刻 ti にイベント i を攻略しなければいけません。ただし、そのときにあなたの強さは si 以上である必要があり、si 以上にできない場合はゲームオーバーになります。ゲーム開始時（時刻０）のあなたの強さは０ですが、アイテムを買うことで強さを増加させることができます。ゲーム開始時のあなたの所持金は０ですが、１単位時間あたり１増加します。 
ボードにはそれぞれ１から N の番号が付けられた N 個のアイテムが順番に並べられており、アイテム i の値段は vi で、それを購入するとあなたの強さが hi 増加します。アイテムは所持金が十分であれば好きな時刻に好きな数だけ購入することができますが、残っているアイテムの中で番号が小さいものから順に選ばなければなりません。各アイテムは１度購入すると消滅します。 
また、同じ時刻に複数のアイテムを連続で買うことができ、このとき隣り合うアイテムの hi の差分の和をボーナスとして得ることができます。例えば、ある時刻にアイテム１,２,３を同時に買った場合、h1 + h2 + h3 に加えて|h1 - h2| + |h2 - h3| だけあなたの強さが増加します。 
あなたは、全てのイベントを攻略した後の所持金を最大化したいと考えています。 
アイテムの情報とイベントの情報を入力とし、すべてのイベントを攻略した後の所持金の最大値を出力するプログラムを作成せよ。 

-----問題ここまで----- */
/* -----解説等-----

愚直を考えると値の伝搬がダメそう。
そこで、連続するやつは後のやつにやらせる。->ケツを更新

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int M;

	cin >> N>>M;
	VL v(N),h(N);
	FOR(i,0,N){
		cin>>v[i]>>h[i];
	}
	VL usesum(N+1,0);
	VL powersum(N+1,0);
	FOR(i,0,N){
		usesum[i+1] += usesum[i] + v[i];
		powersum[i+1] += powersum[i] + h[i];
	}
	VL powerdiff(N+1,0);
	FOR(i,0,N-1){
		powerdiff[i] = abs(v[i] - v[i+1]);
	}
	VL powerdiffsum(N+1,0);
	FOR(i,0,N-1){
		powerdiffsum[i+1] +=powerdiffsum[i]+ powerdiff[i];
	}


	VL t(M),s(M);
	FOR(i,0,M){
		cin>>t[i]>>s[i];
	}
	vector<VVL> dp(M+1,VVL(N+1,VL(2,-1)));
	dp[0][0][0] = 0;
	// 0 simple 1 ketu
	FOR(i,0,M){
		LL nowmoney = t[i];
		FOR(j,0,N+1){
			if(dp[i][j][0]>=s[i]){
				dp[i+1][j][0] = max( dp[i+1][j][0], dp[i][j][0] );
			}
			if(dp[i][j][1]>=s[i]){
				dp[i+1][j][0] = max( dp[i+1][j][0], dp[i][j][1]);
			}
			if(j==N)continue;
			//debug(nowmoney - usesum[j+1]);
			if(nowmoney - usesum[j+1]>=0){
				if(dp[i][j][0]>=0){
					LL addpower =  h[j];
					dp[i][j+1][0] = max(dp[i][j+1][0], dp[i][j][0] + addpower);
					dp[i][j+1][1] = max(dp[i][j+1][1], dp[i][j][0] + addpower);
				}
				if(dp[i][j][1]>=0){
					LL addpower = h[j] + abs(h[j] - h[j-1]);
					dp[i][j+1][1] = max(dp[i][j+1][1],dp[i][j][1] + addpower );
				}
			}
		}
	}
 
	ans = -1;
	FOR(j,0,N+1){
		if(dp[M][j][0]!=-1){
			//debug(t[M-1]-usesum[j]);
			ans = max(ans,t[M-1] - usesum[j]);
			//debug(ans);
		}
	}
	cout<<ans<<endl;


	// VVL dp(M+1,VL(N+1),-1);
	// dp[0][0] = 0;
	// FOR(i,0,M){
	// 	FOR(j,0,N){
	// 		LL money = t[i] - usesum[j]; // time - sum[item]
	// 		LL power = dp[i][j];
	// 		FOR(k,j+1,N){ // [j+1,k]までを選択
	// 			LL cost = usesum[k+1] - usesum[j+1];
	// 			LL addpower =	powersum[k+1] - powersum[j+1] + powerdiffsum[k] -powerdiffsum[j+1]; 
	// 			if(money -cost<0)break;// cut
	// 			if(power+addpower>=s[i]){
	// 				dp[i+1][k] = max(dp[i+1][k],dp[i][j]+addpower);
	// 			}

	// 		}
	// 	}
	// }



	return 0;
}
