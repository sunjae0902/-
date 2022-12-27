/* 2-1
 문제: 동적계획법(반복문)을 사용한 알고리즘으로 n번째 피보나치 수를 구하고 호출 횟수와 수행 시간을 구하는 프로그램을 개발해라.
 입력: input n: 10
 출력: 결과: 55
      호출 횟수: 9
      수행 시간: 0.00006
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000
long count3=0;

long long fib2 (int n){
    int i;
    long long f[MAX];
    
    f[0]=0;
    if (n>0){
        f[1]=1;
        for (i=2;i<=n;i++) {
            f[i]=f[i-1]+f[i-2];
            count3++;
        }
    }
    return f[n];
    }

int main(void){
    
    int n;
    long long result3=0;
    
    clock_t start3,end3; float t3=0.0;
    printf("input n: "); scanf("%d",&n);
    start3=clock();
    result3=fib2(n);
    end3=clock();
    t3=(float) (end3-start3)/CLOCKS_PER_SEC;
    
    printf("결과: %lld\n",result3);
    printf("호출 횟수: %ld\n",count3);
    printf("수행 시간: %.5f\n",t3);
    
    return 0;
}


