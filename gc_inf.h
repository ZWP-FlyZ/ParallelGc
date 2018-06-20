#ifndef __GC_INF__
#define __GC_INF__

#include "gc_setting.h"

//目标函数接口

 

// 目标函数
double obj_function(double* x);

// 梯度函数
void dec_function(double* x,double *result);

// 初始化目标函数
void init_obj_function();

#endif


