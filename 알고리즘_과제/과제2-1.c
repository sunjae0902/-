//2022-2 알고리즘 과제 2=> n번째 피보나치 수를 구하는 3가지 프로그램들의 성능 평가
/* 2-1
 문제: 분할정복법을 사용한 재귀적 알고리즘으로 n번째 피보나치 수를 구하고 호출 횟수와 수행 시간을 구하는 프로그램을 개발해라.
 입력: input n: 10
 출력: 결과: 55
      호출 횟수:
      수행 시간: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long count1=0;

long long fib (int n){
    count1++;
    if(n<=1) return n;
    return fib(n-2)+fib(n-1);
}

int main(void){
    
    int n;
    long long result1=0;
    
    clock_t start1,end1; float t1=0.0;
    printf("input n: "); scanf("%d",&n);
    start1=clock();
    result1=fib(n);
    end1=clock();
    t1=(float) (end1-start1)/CLOCKS_PER_SEC;
    printf("결과: %lld\n",result1);
    printf("호출 횟수: %ld\n",count1);
    printf("수행 시간: %.5f\n",t1);
    
    return 0;
}





