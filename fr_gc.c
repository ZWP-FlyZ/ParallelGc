/*
 * FR共轭梯度实现 
 * 
 * 
 */

#include <stdio.h>
#include "gc_inf.h"
#include "vect_op.h"
#include "line_search.h"
#include "gc_setting.h"
#include "fr_gc.h"
#include <math.h>
#include <omp.h>

double 	x[N],// 测试点向量
		gk[N],// 当前梯度向量
        dk[N];//当前搜索方向


double  gk_gk=0.0,//上一次的gkgk
        tmp=0.0,
        beta_k_1,
        ak=0.0;//步长
extern struct obj_param param;

float start_time=0.0;
//设置初始点
void init_x(double *x){
	x[0]=1.0;
	x[1]=1.0;
}

int fr_gc_main(){

	printf("FR_GC start N=%d, END=%f, MAX_REPEAT=%d\n",N,END,MAX_REPEAT);

    // 初始化
    init_x(x);
    init_obj_function();

    start_time = omp_get_wtime();
    for(int i=0;i<MAX_REPEAT;i++){

        dec_function(x,gk);// 计算梯度

        //计算范数
        tmp = vect_mult_sum(gk,gk);
        printf("step=%d ||gk||=%f\n",i,tmp);
        if(sqrt(tmp)<=END){
        	tmp = obj_function(x);
        	printf("\n------------ result --------------\n");
            printf("all step=%d min=%f\n",i+1,tmp);
            printf("all time = %f S\n",omp_get_wtime()-start_time);
            printf("x=");
            show_vect(x);
        	printf("\n------------ result --------------\n");
            break;
        }
        //计算方向
        if(i==0) vect_mult_one(gk,-1.0,dk);
        else{
        	// 以下为FR共轭梯度迭代过程 
            beta_k_1 = tmp/gk_gk;
            vect_mult_one(dk,beta_k_1,dk);
            vect_mult_one(gk,-1.0,gk);
            vect_add(gk,dk,dk);
        }
        gk_gk = tmp;

        //计算步长
        ak = armijo_func(x,dk,ARMIJO_BEAT,ARMIJO_SIGMA);

        //更新测试点
        vect_mult_one(dk,ak,gk);// 这里的gk当成临时变量使用
        vect_add(x,gk,x);

    }

	return 0;
}



