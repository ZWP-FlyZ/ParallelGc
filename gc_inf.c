#include "gc_inf.h"


// 目标函数 y = x.T*G*x + b.T*x + c
double obj_function(double* x){
	int i=0,j=0;
	int result=0.0;
	double tmpNN[N];
	for(i=0;i<N;i++){
		tmpNN[i]=0.0;
		for(j=0;j<N;j++)
			tmpNN[i]+=x[j]*param.G[j][i];
		tmpNN[i]*=x[i];
	}
	
	for(i=0;i<N;i++)
		result+=tmpNN[i]*param.b[i];

	return result+param.c;    
}

// 原函数的导函数 dec_y = G*x + b
void dec_function(double* x,double *result){
    int i=0,j=0;
	for(i=0;i<N;i++){
		result[i]=param.b[i];
		for(j=0;j<N;j++)
			result[i]+=x[j]*param.G[i][j];
	}
}

// 初始化目标函数
void init_obj_function(){
    
}

