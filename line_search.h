#ifndef __LINE_SEARCH__
#define __LINE_SEARCH__

//beta 在(0,1)
#define ARMIJO_BEAT 0.5
//sigma 在(0,0.5)
#define ARMIJO_SIGMA 0.25

//sigma 在(0,0.5)
#define ARMIJO_MAX_TEST_M 200


//采用Armijo线搜索确定步长 ak
double armijo_func(double *x,double *dk,double beta,double sigma);


#endif