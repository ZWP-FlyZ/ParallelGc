#ifndef __GC_INF__
#define __GC_INF__

#include "gc_setting.h"

// 二次高维系数
struct obj_param {
    // 二次参数矩阵
    double G[N][N];
    // 一次参数向量
    double b[N];
    // 零次参数向量
    double c;
}; 




// 目标函数
double obj_function(double* x);

// 梯度函数
void dec_function(double* x,double *result);

// 初始化目标函数
void init_obj_function();

#endif


