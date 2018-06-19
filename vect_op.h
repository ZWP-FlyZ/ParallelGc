#ifndef __VECT_OP__

#define __VECT_OP__


// 两向量相加
void vect_add(double *a,double *b,double *result);
// 两向量相乘
void vect_mult(double *a,double *b,double *result);
// 一个数于一个向量相乘
void vect_mult_one(double *a,double b,double *result);

//两向量内积
double vect_mult_sum(double *a,double *b);

#endif
