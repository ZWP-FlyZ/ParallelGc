#include "vect_op.h"
#include "gc_setting.h"
#include <stdio.h>
// 两向量相加
void vect_add(double *a,double *b,double *result){

#if USEING_PARALLEL
#if DEEP_PARALLEL
#pragma omp parallel for num_threads(THREAD_NUM) 
#endif
#endif
    for(int i =0;i<N;i++)
        result[i] = a[i]+b[i];
}
// 两向量相乘
void vect_mult(double *a,double *b,double *result){
#if USEING_PARALLEL
#if DEEP_PARALLEL
#pragma omp parallel for num_threads(THREAD_NUM) 
#endif
#endif
    for(int i =0;i<N;i++)
        result[i] = a[i]*b[i];
}
// 一个数于一个向量相乘
void vect_mult_one(double *a,double b,double *result){
#if USEING_PARALLEL
#if DEEP_PARALLEL
#pragma omp parallel for num_threads(THREAD_NUM) 
#endif
#endif
        for(int i =0;i<N;i++)
            result[i] = a[i]*b;
}

//两向量内积
double vect_mult_sum(double *a,double *b){
    double result=0.0;
#if USEING_PARALLEL
#if DEEP_PARALLEL
#pragma omp parallel for num_threads(THREAD_NUM) reduction(+:result)
#endif
#endif
    for(int i =0;i<N;i++)
        result += a[i]*b[i];
    return result;
}

void vect_copy(double * origin,double *targe){
#if USEING_PARALLEL
#if DEEP_PARALLEL
#pragma omp parallel for num_threads(THREAD_NUM) 
#endif
#endif
        for(int i =0;i<N;i++) targe[i] = origin[i];
}


//打印向量
void show_vect(double * a){
    printf("[ ");
    if(N<11) {
        for(int i =0;i<N;i++) 
            printf("%.3f ",a[i]);
    }
    else{
        for(int i =0;i<5;i++) 
            printf("%.3f ",a[i]);
        printf("... ");
        for(int i =0;i<5;i++) 
            printf("%.3f ",a[N-5+i]);
    }
    printf("]");
}

