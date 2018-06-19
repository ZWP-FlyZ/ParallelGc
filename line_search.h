#ifndef __LINE_SEARCH__
#define __LINE_SEARCH__


//采用Armijo线搜索确定步长 ak
double armijo_func(double *x,double *dk,double beta,double sigma);


#endif