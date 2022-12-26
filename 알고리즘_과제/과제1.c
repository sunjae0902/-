//2022-2 알고리즘 과제 1
/*
 문제: Linker Emulation을 통한 n번째 피보나치 항을 구하는 c/c++ 프로그램을 개발한다.
 입력 예: input n: 10
 출력 예: 55
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long count2=0;

typedef struct fbARI{
    long long n,t1,t2,fv;
    char nStmt; //현재 처리 문장
    struct fbARI* prev; //특정 노드에서 다음 노드를 가리키는 포인터
}fbARI;

typedef struct Stack{
    fbARI *top; //가장 최근에 생성한 AR을 가리키는 포인터
}Stack;

void initStack(Stack *stack){
    stack->top=NULL;
}

int isEmpty(Stack *stack){
    return stack->top==NULL;
}

void push(Stack *stack, long long data){
    count2++;
    fbARI *now=(fbARI *)malloc(sizeof(fbARI));
    now->n=data;
    now->prev=stack->top; //널값
    stack->top=now;
}

long long pop(Stack *stack){
    fbARI *now;
    long long re;

    if (isEmpty(stack)){
        return 0;
    }
    now=stack->top;
    re=now->n;
    stack->top=now->prev;
    free(now);
    return re;
}

int main(void){
    fbARI* cfbARI;
    
    Stack stack;
    initStack(&stack);
    
    int n;
    long long fv=0,result2=0;
  
    
    printf("input n: "); scanf("%d",&n);
    
    push(&stack,n); //n push
    stack.top->nStmt='a'; //현재 처리 문장
    cfbARI=stack.top; //가장 최근에 생성한 노드 집어넣음
    
   

    while(!isEmpty(&stack)){ //스택이 빌 때까지 반복
        fv=pop(&stack);
        switch(cfbARI->nStmt){
            case 'a':
                if (fv==1) {
                    result2+=fv;
                    cfbARI->nStmt='b';
                   }
                
                if (fv>=2){
                    cfbARI->t1=fv-2;
                    push(&stack,cfbARI->t1);
                }
                
                if (fv>=1){
                    cfbARI->t2=fv-1;
                    push(&stack,cfbARI->t2);
                    
                }
                break;
         

       case 'b':
                if (fv==1) {
                    result2+=fv;
                    cfbARI->nStmt='c';
                    
                    }
                
                if (fv>=2){
                    cfbARI->t1=fv-2;
                    push(&stack,fv-2);
                }
                
                if (fv>=1){
                    cfbARI->t2=fv-1;
                    push(&stack,fv-1);
                    }
                break;
                
          case 'c':
                if (fv==1) {
                    result2+=fv;
                   }
                
                if (fv>=2){
                    cfbARI->t1=fv-2;
                    push(&stack,fv-2);
                }
                
                if (fv>=1){
                    cfbARI->t2=fv-1;
                    push(&stack,fv-1);
                    }
                break;
                
              }
    }
   }
