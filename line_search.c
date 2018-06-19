#include "line_search.h"
#include "gc_setting.h"
#include "vect_op.h"
#include "gc_inf.h"
#include <math.h>
#include <stdio.h>


//采用Armijo线搜索确定步长 ak
double armijo_func(double *x,double *dk,double beta,double sigma){
    int max_m = 20;
    double f_x_k = 0.0;// 原值
    double g_x_k[N];// 梯度向量
    double tmp=0.0,tmp1=0.0,tmp2=0.0;
    double tmp_vect[N];
    double beta_m = 0;


    f_x_k = obj_function(x);
    dec_function(x,g_x_k);

    tmp = sigma *vect_mult_sum(g_x_k,dk);

    for(int m=0;m<max_m;m++){
        beta_m=pow(beta,(double)m);
        tmp1 = f_x_k + beta_m*tmp;
        vect_mult_one(dk,beta_m,tmp_vect);
        vect_add(x,tmp_vect,tmp_vect);
        if(obj_function(tmp_vect)<=tmp1)
            return beta_m;
    }
    printf(">>>><ak><<<<!!!!");
    return beta_m;




}


