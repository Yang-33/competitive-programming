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
#define FOR(i, s, e) for (LL(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/01/22  Problem: yukicoder409 / Link: https://yukicoder.me/problems/no/409  ----- */
/* ------問題------

btkさんは毎日ドーナツを食べています．
ある日，btkさんは N 日間ダイエットをすることを決意しました．
btkさんは毎日違うお店でドーナツを買っていて，ダイエット開始から i 日目に訪れるお店でドーナツを食べるとDikg体重が増えることが分かっています． また，1 日ドーナツを食べるのをやめると，Akg痩せることができます.
しかし，ドーナツを食べない日が続くとストレスが溜まります．ここで，ストレス値というパラメータを定義します． ダイエット開始時点でのストレス値は0です．
1 日ドーナツを食べないとストレス値が 1 溜まり，1日の終了時にbtkさんの体重はB∗(ストレス値)kg増加します． ドーナツを食べるとストレス値は 0 に戻ります．
各日において，ストレス値の変化後に体重が変化することに注意してください．
ダイエット開始前のbtkさんの体重を W kgとしたとき，N 日間で何kgに痩せることができるでしょうか．


-----問題ここまで----- */
/* -----解説等-----


一昨日やったConvex Hull Trickを使うやつ
dp(i,j)とかでは高速化の余地なし?
次元を落として式はすぐに出たけど書くときの添字に結構困った。
dp(i):=食べてi日目を終える、とすると、
dp(i) = MIN[k:0,i-1](dp(k)+B(i-k)(i-k+1)/2-A(i-k))になり、O(N^2)っぽいが反省をいかすと
NlogNかNになる。(今回は追加する直線が単調なのでO(N))
というか追加する直線が単調じゃない時ってDPとかではなくて繊維がめちゃくちゃで結構特殊な高速化っぽそう…
btkさん解きましたよ!

----解説ここまで---- */

struct CHT2{
    typedef pair<LL,LL> PT;
    typedef LL RT;
    
    struct L{
        LL a,b;
        L(LL a, LL b): a(a),b(b){}
        bool operator<(const L &rhs) const{
            return a != rhs.a ? a > rhs.a : b < rhs.b;
        }
    };
    
    struct CP{
        LL n,d;
        L p;
        CP(LL _n,LL _d, const L &p):n(_n),d(_d),p(p){
            if(d < 0) { n *= -1; d *= -1;}
        }
        bool operator<(const CP &rhs) const{
            if(n == LINF || rhs.n == -LINF) return 0;
            if(n == -LINF || rhs.n == LINF) return 1;
            return n*rhs.d < rhs.n*d;
        }
    };
    typedef set<L>::iterator It;
    set<L> S;
    set<CP> C;
    
public:
    CHT2(){
        // 番兵
        S.insert({L(LINF,0), L(-LINF,0)});
        C.insert(cp(L(LINF,0),L(-LINF,0)));
    }
    // for debug
    void print() {
        cout << "S : "; for (auto it : S) printf("(%lld,%lld)", it.a, it.b); puts("");
        cout << "C : "; for (auto it : C) printf("(%lld,%lld)", it.n, it.d); puts("");
    }
    
    void add(LL a, LL b) {
        const L p(a,b);
        It pos = S.insert(p).first;
        if (check(*it_m1(pos), p, *it_p1(pos))) {
            // 直線(a,b)が不要
            S.erase(pos);
            return;
        }
        C.erase(cp(*it_m1(pos), *it_p1(pos)));
        {
            // 右方向の削除
            It it = it_m1(pos);
            while(it!=S.begin() && check(*it_m1(it), *it, p)) --it;
            C_erase(it, it_m1(pos));
            S.erase(++it,pos);
            pos = S.find(p);
        }
        {
            // 左方向の削除
            It it = it_p1(pos);
            while(it_p1(it)!=S.end() && check(p,*it, *it_p1(it))) ++it;
            C_erase(++pos, it);
            S.erase(pos, it);
            pos = S.find(p);
        }
        C.insert(cp(*it_m1(pos), *pos));
        C.insert(cp(*pos, *it_p1(pos)));
    }
    LL query(LL x) {
        const L &p = (--C.lower_bound(CP(x,1,L(0,0))))->p;
        return p.a*x + p.b;
    }
    
private:
    It it_p1(It a){return ++a;}
    It it_m1(It a){return --a;}
    void C_erase(It a, It b) {
        for (It it=a; it!=b; ++it) C.erase(cp(*it, *it_p1(it)));
    }
    CP cp(const L &p1, const L &p2) {
        if (p1.a == LINF) return CP(-LINF,1,p2);
        if (p2.a == -LINF) return CP(LINF,1,p2);
        return CP(p1.b-p2.b, p2.a-p1.a, p2);
    }
    bool check(const L &p1, const L &p2, const L &p3) {
        if (p1.a==p2.a && p1.b <= p2.b) return 1;
        if (p1.a == LINF || p3.a == -LINF) return 0;
        return (p2.a-p1.a)*(p3.b-p2.b) >= (p2.b-p1.b)*(p3.a-p2.a);
    }
};

LL N,A,B,W;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> A >> B >> W;
	VL d(N+1);
	FOR(i,0,N){
		cin >> d[i];
	}
	CHT2 Q;
	VL dp(N+2,0);
	dp[0] = W;
	// dp(i) :=　食べてi日目を終える 
	FOR(i,0,N){ //             i日目に食べる
		Q.add(-B*i,dp[i] + B*(i*i-i)/2+ A*i); 
		dp[i+1] = B*(i*i+i)/2 + d[i] - A*i + (Q.query(i));
		//debug(dp[i]);
	}
	ans = LINF;
	FOR(i,0,N+1){ // i日目から食べてないのでストレスまみれ
		ans = min(ans,  dp[i] - A*(N-i) +B*(N-i)*(N-i+1)/2);
	}
	cout << ans << "\n";

	return 0;
}
