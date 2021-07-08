#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;

    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

int IsTheNumber ( const int N ){
    char flg = 0, nums[10];
    for (int i=0; i<10; ++i) nums[i] = 0;
    int t = N, tmp;
    do {
        tmp = t%10;
        if (nums[tmp]) {
            flg = 1;
            break;
        }
        nums[tmp] = 1;
    } while (t=t/10);
    if (flg) {
		double d = sqrt(N);
		int D = (int)d;
		if (D*D == N) {
			printf("%d %d\n", N, D);
			return 1;
		} else {
			return 0;
		}
    } else {
        return 0;
    }
}