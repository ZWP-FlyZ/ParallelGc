/*
 * 利用OpenMP并行处理高維正定二次方程
 * 
 * 
 */

#include <stdio.h>
#include "gc_inf.h"
#include "vect_op.h"
#include "line_search.h"
#include "gc_setting.h"
#include <math.h>
double x[N];


int main(){

	printf("hello world N=%d\n",N);
	for(int i=0;i<N;i++) x[i]=(double)i;
	for(int i=0;i<N;i++) printf("%.3f ",x[i]);
	//double res = obj_function(x);
	double res = pow(2.0,2.0);
	printf("res = %f\n",res);
	return 0;
}



