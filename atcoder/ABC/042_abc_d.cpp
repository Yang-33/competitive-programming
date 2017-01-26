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

/* 2017/01/25 ��� ----- ABC042 D /Link http://abc042.contest.atcoder.jp/tasks/arc058_b */
/* -----�����-----
���: �c H �}�X�A�� W �}�X�̃}�X�ڂ�����܂��B
����͂����́A����ԍ���̃}�X�ڂɂ��܂��B
�����āA�E������1�}�X�ړ����邱�Ƃ��J��Ԃ��A��ԉE���̃}�X�ڂւƈړ����܂��B
�������A������ A �ȓ��A�������� B �ȓ��̃}�X�ڂւ͈ړ����邱�Ƃ͏o���܂���B

�ړ�������@�͉��ʂ肠�邩���߂Ă��������B

�Ȃ��A�����͔��ɑ傫���Ȃ邱�Ƃ�����̂ŁA������ 10^9+7 �Ŋ��������܂���o�͂��Ă��������B

�g�ݍ��킹�E�t���̖��
���ɗގ������������������Ƃ�����̂ł����ɂ`�b
����Z��MOD�͎�邱�Ƃ��ł��Ȃ��̂Ńt�F���}�[�̒藝����t����p���đg�ݍ��킹�����߂�B

nCk=n!/((n-k)!*(k!))
nCk�̌v�Z�����Ă����ۂ�mod���Ƃ�Ɗ���Z�ɑ΂��Ă͂��̌v�Z���ł��Ȃ��̂ŁA
p:�f���Ƃ��ăt�F���}�[�̏��藝��a��p���݂��ɑf�ł邱�Ƃ��l�����āA�ό`���ċt�����l�����
a^(p-1)��1 (mod p)�@->  a^(p-2)*a��1 (mod p)
-> a^(p-2)��1/a (mod p) ->b/a (mod p) = b*a^(p-2) (mod p)
�ƂȂ�

�P��̋t���́A
Int inv[1000010];
inv[1] = 1;
for (int i = 2; i <= N; ++i)
inv[i] = P - (P / i) * inv[P % i] % P;�@(mod P)

�Ƃ��ċ��߂邱�Ƃ��ł���B�����p���ĊK��Ƃ��̋t����
I
nt fac[1000010], facInv[1000010];
fac[0] = facInv[0] = 1;
for (int i = 1; i <= N; ++i) {
fac[i] = (fac[i - 1] * i) % P;
facInv[i] = (facInv[i - 1] * inv[i]) % P;
}
pow_mod(a,mod-2,mod)��p���Ȃ��Ă����̂悤�ɋ��߂邱�Ƃ��ł���B

invers�O����O(N+N+N) �g�pO(1) <�P��t���̗��p>
powmod�O����O(N+N*log(MOD)) �g�pO(1) <�t�F���}�[�̏��藝����>

*/

#define MAX 230000
int H, W, A, B;
ll fact[MAX], rfact[MAX];

ll mod_pow(ll x, ll p, ll mod) {
    ll a = 1;
    while (p) {
        if (p % 2) a = a * x % mod;
        x = x * x % mod;
        p /= 2;
    }
    return a;
}

//�t��
ll mod_inverse(ll a, ll m) {
    return mod_pow(a, m - 2, m);
}


ll nCr(int n, int r) {
    return fact[n] * rfact[r] % MOD * rfact[n - r] % MOD;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int H, W, A, B;
    cin >> H >> W >> A >> B;
    ll ans = 0;


    fact[0] = rfact[0] = 1;

    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        rfact[i] = mod_inverse(fact[i], MOD);
    }

    for (int i = B + 1; i <= W; i++) {
        int h = H - A - 1, w = i - 1;
        ll tmp = nCr(h + w, h);
        h = A - 1, w = W - i;
        tmp *= nCr(h + w, w);
        ans += tmp % MOD;
    }

    cout << ans%MOD << endl;

    return 0;
}