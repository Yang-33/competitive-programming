# python3.
#/* -----  2017/09/20  Problem: ACPC2017_day3_b  / Link:   ----- */
#/* ------問題------



#-----問題ここまで----- */
#/* -----解説等-----

#n==1は明らかにm+1
#ほかの場合は大変で、二次元座標の格子点の数を数えることになる。

#----解説ここまで---- */

MOD = 10**9+7
 
def sum(a,d,n):
    return n*(2*a+(n-1)*d)//2
 
def main():
    n,m = map(int,input().split())
 
    s = 0
    if n == 1:
        s = m+1
    else:
        s = sum(m+1,-n+1,1+m//(n-1))
        s *= 2
        s -= (m+1)
 
    print(s%MOD)
 
if __name__ == '__main__':
    main()