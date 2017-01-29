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

/* 2017/01/29 ��� ----- ABC034 C /Link http://abc034.contest.atcoder.jp/tasks/abc034_c */
/* -----�����-----
���: �� W x �c H �̃O���b�h������܂��B������ i �ԖځA������ j �Ԗڂ̃}�X�ڂɂ� (i,j) �Ƃ����ԍ������Ă��܂��B 

�����N�́A�}�X�� (i,j) ���� (i+1,j) �܂��� (i,j+1) �ɐi�ނ��Ƃ��ł��܂��B
�����N�� (1,1) ���� (W,H) �܂ōs���o�H�̌��� 1,000,000,007 �Ŋ��������܂�����߂Ă��������B


�t�������߂�B1/a �� a^(p-2) (mod p)�̓t�F���}�[�̒藝���狁�߂邱�Ƃ��ł���B
�����p���� nCr= n!/(r!*(n-r)!)�� nCr��n!*(r!)^(p^2)*(n-r)!^(p-2) (mod p)
�Ƃ���킹�΂悢�B
1�񓚂���΂悢�̂ł���ŏI���B

*/

#define MAX 230000
int W, H;
ll ans = 0;
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

    cin >> H >> W;

    fact[0] = rfact[0] = 1;

    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        rfact[i] = mod_inverse(fact[i], MOD);
    }
    H--; W--;
    ans = nCr(H+W, W);

    cout << ans << endl;

    return 0;
}