#include "vect_op.h"
#include "gc_setting.h"

// 两向量相加
void vect_add(double *a,double *b,double *result){
    for(int i =0;i<N;i++)
        result[i] = a[i]+b[i];
}
// 两向量相乘
void vect_mult(double *a,double *b,double *result){
        for(int i =0;i<N;i++)
            result[i] = a[i]*b[i];
}
// 一个数于一个向量相乘
void vect_mult_one(double *a,double b,double *result){
        for(int i =0;i<N;i++)
            result[i] = a[i]*b;
}

//两向量内积
double vect_mult_sum(double *a,double *b){
    double result=0.0;
    for(int i =0;i<N;i++)
        result += a[i]*b[i];
}


