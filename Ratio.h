#include <stdio.h>
#include <stdbool.h>

struct RatioNumb{
    int num;
    int den;
    int factor;
    bool Numb_exist;
};

void outputR(struct RatioNumb n){
    printf("Result of cut is: %i/%i \n", n.num, n.den);
}

void cutR(struct RatioNumb n){
    int min_ = 1;
    if (n.num < n.den){
        min_ = n.num;
    }
    else{
        min_ = n.den;
    }
    for(int i=1;i<min_+1;i++){
        if ((n.num%i==0) && (n.den%i==0)){
            if (i > n.factor){
                n.factor = i;
            }
        }
    }
    if (n.factor != 1){
        n.den = n.den/n.factor;
        n.num = n.num/n.factor;
    }
    outputR(n);
}

void chekR(struct RatioNumb n){
    if(n.den == 0){
        n.Numb_exist = false;
    }
    else{
        cutR(n);
    }
}

void inputR(struct RatioNumb n){
        n.num = 0;
        n.den = 0;
        n.Numb_exist = true;
        n.factor = 1;
        printf("Enter num: \n");
        scanf("%d", &n.num);
        printf("Enter den: \n");
        scanf("%d", &n.den );
        chekR(n);
}

struct ChainFraq{
    int num;
    int *pointer;
    int e;
    float r;
};

void inputChFr(struct ChainFraq n, int *a, int num){
    n.r = 0;
    n.pointer = a;
    n.num = num;
    printf("Enter epsilon: \n");
    scanf("%d", &n.e);
    createN(n);
}

void createN(struct ChainFraq n){
    printf("Your row to ChFr is: ");
    for(int i=0;i<n.num;i++){
        if(i==0){
            printf("[");
        }
        else if(i==n.num-1){
            printf("%i] \n", *(n.pointer+i));
        }
        else{
            printf("%d ,", *(n.pointer+i));
        }
    }
    for(int i=n.num;i>=0;i--){
        n.r = 1.0/n.r + *(n.pointer+i);
    }
    printf("Your number is: %f ", n.r);
}

