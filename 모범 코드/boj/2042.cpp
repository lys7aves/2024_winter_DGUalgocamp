#include <stdio.h>

#define MAXN 1000000

int t=1;
long long int tree[4*MAXN];

void Renew(int i, long long int x);
long long int Sum(int l, int r);

int main()
{
    int n, m, k, i, j;
    long long int x, a, b, c;
    
    scanf("%d %d %d", &n, &m, &k);
    while(t < n) t *= 2;
    
    for(i=1;i<=n;i++){
        scanf("%lld", &x);
        Renew(i, x);
	}
    
    for (i = 1; i <= m+k; i++) {
        scanf("%lld %lld %lld" , &a , &b , &c);
        if (a == 1) Renew(b,c);
        else printf("%lld\n", Sum(b,c));
    }
    
    return 0;
}

void Renew(int i , long long int x) {
    i += t-1;
    x -= tree[i];
    while(i){
        tree[i] += x;
        i /= 2;
    }
}

long long int Sum(int l , int r) {
    long long int sum=0;
    
    l += t-1; r += t-1;
    while(l <= r){
        if(l%2 == 1){
            sum += tree[l];
            l++;
		}
        if(r%2 == 0){
            sum += tree[r];
            r--;
        }
        l /= 2;
        r /= 2;
    }
    
    return sum;
}