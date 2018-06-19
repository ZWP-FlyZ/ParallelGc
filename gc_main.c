/*
 * 利用OpenMP并行处理高維正定二次方程
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
	void default_gc_main();
#endif

	return 0;
}



