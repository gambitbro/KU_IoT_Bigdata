// generic program for queue

#include <stdio.h>
#include "queue.h"

int main(void)
{

    struct queue q1, q2;

    initQueue(&q1, 10, sizeof(int));
    initQueue(&q2, 100, sizeof(double));

    int i;
    i = 100;            //변수에 넣고싶은 값을 넣고
    push(&q1, &i);      //주소값을 전달, 사이즈는 이미 구조체가 가지고있음
    i = 200;
    push(&q1, &i);
    i = 300;
    push(&q1, &i);
    
    int re;
    pop(&q1, &re);
    printf("1st pop() : %d\n", re);
    pop(&q1, &re);
    printf("2nd pop() : %d\n", re);
    pop(&q1, &re);
    printf("3rd pop() : %d\n", re);


    double d;
    d = 1.1;
    push(&q2, &d);
    d = 2.2;
    push(&q2, &d);
    d = 3.3;
    push(&q2, &d);
    
    double re2;
    pop(&q2, &re2);
    printf("1st pop() : %f\n", re2);
    pop(&q2, &re2);
    printf("2nd pop() : %f\n", re2);
    pop(&q2, &re2);
    printf("3rd pop() : %f\n", re2);

    clearQueue(&q1);
    clearQueue(&q2);
    return 0;
}
