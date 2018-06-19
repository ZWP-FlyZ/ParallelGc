/*
 * 共轭梯度法计算高维变量方程极小值
 * 利用OpenMP 加速方程计算过程
 * 
 * 
 */

#include <stdio.h>
#include "gc_setting.h"

void default_gc_main(){
	printf("ERROR GC_MAIN\n");
}

#ifdef __FR_GC__
#include "fr_gc.h"
#endif

int main(){

#ifdef __FR_GC__
	fr_gc_main();
#else
	default_gc_main();
#endif
	return 0;
}



