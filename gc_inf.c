#include "gc_inf.h"


/*
 *更改目标函数和对应的导数函数 
 * 并设置初始测试点 
 *
 */


// 二次高维系数
struct obj_param {
    // 二次参数矩阵
    double G[N][N];
    // 一次参数向量
    double b[N];
    // 零次参数向量
    double c;
} param; 


// 目标函数 y = x.T*G*x + b.T*x + c
double obj_function(double* x){
	int i=0,j=0;
	double result=0.0;
	double tmpNN[N];
	for(i=0;i<N;i++){
		tmpNN[i]=0.0;
		for(j=0;j<N;j++)
			tmpNN[i]+=x[j]*param.G[j][i];
		tmpNN[i]*=x[i];
	}
	
	for(i=0;i<N;i++)
		result += (x[i]*param.b[i]+tmpNN[i]);
	


	return result+param.c;    
}

// 原函数的导函数 dec_y = G*x + b
void dec_function(double* x,double *result){
    int i=0,j=0;
	for(i=0;i<N;i++){
		result[i]=param.b[i];
		for(j=0;j<N;j++)
			result[i]+=2*x[j]*param.G[i][j];
	}
}


// 初始化目标函数
void init_obj_function(){
    
	//测试函数 z = x^2 + y^2+ x + y 
	param.G[0][0] = 2.0;
	param.G[1][1] = 1.0;
	param.b[0] = 1.0;
	param.b[1] = 1.0;
	param.c=0.0;

}

