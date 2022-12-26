// 2022-1 프로그래밍기초및실습 과제3 의생명시스템학부 20212277 김선재
/*
 문제: 성적 출력 프로그램을 작성하여라. 단, 배운 내용만(15주차 내용까지 허용, 구조체 사용 금지) 사용해야 한다. 주어진 학생 정보를 배열에 저장하고, 다음 실행 예처럼 출력되도록 작성한다.
 
 실행 예:
 1. 이름 오름차순 출력 2. 학번 오름차순 출력
 3. 점수 내림차순 출력4. 이름 검색
 5. 종료

 번호를 선택하세요 : 1
 
 이름       학번       점수
 Aiden    20220018  78
 Amelia   20220005  79
   .
   .
   .
 
 */

#include <stdio.h>
#include <string.h>

void sort_name(char name[][10], int id[20], int score[20]){ //이름 오름차순 정렬
    char temp[10];
    int temp_id,temp_score;
    for (int i=0;i<19;i++){
        for (int j=0;j<19-i;j++){
            if (strcmp(name[j],name[j+1])>0){
                strcpy(temp,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],temp);

                temp_id=id[j];
                id[j]=id[j+1];
                id[j+1]=temp_id;
                
                temp_score=score[j];
                score[j]=score[j+1];
                score[j+1]=temp_score;

                
            }
        }
    }
    
    printf("%9s %9s %13s\n","이름","학번","점수");

    for (int i=0;i<20;i++)
            printf("%9s %9d %5d\n",name[i],id[i],score[i]);
    


}

void sort_id(char name[][10], int id[20], int score[20]){ //학번 오름차순 정렬
    char temp[10];
    int temp_id,temp_score;

    for (int i=0;i<19;i++){
        for(int j=0;j<19-i;j++){
            if (id[j]>id[j+1]){
                temp_id=id[j];
                id[j]=id[j+1];
                id[j+1]=temp_id;

                strcpy(temp,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],temp);
                
                temp_score=score[j];
                score[j]=score[j+1];
                score[j+1]=temp_score;
            }
        }
    
    }
    printf("%9s %9s %13s\n","이름","학번","점수");

    for (int i=0;i<20;i++)
            printf("%9s %9d %5d\n",name[i],id[i],score[i]);
    
    


}
void sort_score(char name[][10], int id[20], int score[20]){ //점수 내림차순 정렬
    char temp[10];
    int temp_id,temp_score;

    for (int i=0;i<19;i++){
        for(int j=0;j<19-i;j++){
            if (score[j]<score[j+1]){
                temp_score=score[j];
                score[j]=score[j+1];
                score[j+1]=temp_score;

                strcpy(temp,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],temp);
                
                temp_id=id[j];
                id[j]=id[j+1];
                id[j+1]=temp_id;
            }
        }
    }
    printf("%9s %9s %13s\n","이름","학번","점수");

    for (int i=0;i<20;i++)
            printf("%9s %9d %5d\n",name[i],id[i],score[i]);
    


}

void search_name(char str[10], char name[][10],int id[20], int score[20]){     //이름 검색
    
    int i;
    for ( i=0;i<20;i++)
        if (strcmp(name[i],str)==0) break;

    printf("%9s %9s %13s\n","이름","학번","점수");
    printf("%9s %9d %5d\n",name[i],id[i],score[i]);
}
    


int main(void){
    int n;
    char str[10];
    char name[20][10]={
        "Sophia","Olivia","Riley","Emma","Ava",
        "Isabella","Aria","Amelia","Mia","Liam",
        "Noah","Jackson","Aiden","Elijah","Grayson"
        ,"Lucas","Oliver","Caden","Mateo","David"};

    int id[20]={
        20220001,20220010,20220002,20220015,20220009,
        20220014,20220020,20220005,20220016,20220008,
        20220012,20220004,20220018,20220017,20220003,
        20220013,20220007,20220019,20220011,20220006};

    int score[20]={
        98,96,88,77,82,
        93,84,79,90,80,
        89,99,78,83,92,
        71,72,68,96,76};
    
    while(1){
        printf("1. 이름 오름차순 출력           2. 학번 오름차순 출력\n");
        printf("3. 점수 내림차순 출력           4. 이름 검색\n");
        printf("5. 종료\n");
        printf("번호를 입력하세요:"); scanf("%d",&n);
        switch(n){
            case 1:
                sort_name(name,id,score);
                break;
            case 2:
                sort_id(name,id,score);
                break;
            case 3:
                sort_score(name,id,score);
                break;
            case 4:
                printf("이름을 입력하세요: "); scanf("%s",str);
                search_name(str,name,id,score);
                break;

            case 5:
                break;
       }
        if (n==5) break;
       
    }
    return 0;
}


                


