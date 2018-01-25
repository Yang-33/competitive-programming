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

/* -----  2018/01/22  Problem: colopl_final2018_c / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

一次関数の加算と取得、高速には無理だと思ってた

----解説ここまで---- */

struct CHT{
    typedef pair<LL,LL> PT;
    typedef LL RT;
    vector<PT> deq; // first * x + second
    int s,t;
    CHT(int n):s(0),t(0){ deq.resize(n); }
    void add(RT a,RT b){  // a: 単調減少
        const PT p(a,b);
        while(s+1 < t && check(deq[t-2],deq[t-1],p)) t--;
        deq[t++] = p;
    }
    RT incl_query(RT x){  // x: 単調増加
        while(s+1 < t && f(deq[s],x) >= f(deq[s+1],x)) s++;
        return f(deq[s],x);
    }
    RT query(RT x){   // 条件なし
        RT low = s-1, high = t-1;
        while(low+1<high) {
            RT mid = (low+high)>>1;
            if (isright(deq[mid], deq[mid+1], x)) low = mid;
            else high = mid;
        }
        return f(deq[high], x);
    }
    
private:
    bool isright(const PT &p1,const PT &p2,RT x){
         return (p1.second-p2.second) >= x * (p2.first-p1.first);
    }
    bool check(const PT &p1,const PT &p2,const PT &p3){
        return (p2.first-p1.first)*(p3.second-p2.second) >= (p2.second-p1.second)*(p3.first-p2.first);
    }
    RT f(const PT &p,RT x){
        return p.first*x + p.second;
    }
};
LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a(N+1);
	FOR(i,0,N){
		cin >> a[i+1];
	}
	CHT Q(N+1);
	FOR(j,1,N+1){
		Q.add(-2*j,j*j + a[j]);
	}
	FOR(i,1,N+1){
		cout<<i*i+ Q.incl_query(i)<<endl;
	}

	return 0;
}
