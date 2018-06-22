#ifndef __GC_SETTING__
#define __GC_SETTING__


//------------------------------
// 并行设定

//0-不使用OpenMP 1-开启OpenMP
#define USEING_PARALLEL 1
// 使用线程数
#define THREAD_NUM 8

// 开启深度并行优化,USEING_PARALLEL生效时起效
// 可能降低效率
#define DEEP_PARALLEL 0

#define DEEP_PARALEEL_THREAD_NUM 1
//------------------------------

// 变量向量维数
#define N 9000

// 梯度结束精度
#define END 0.001

// 最大迭代次数
#define MAX_REPEAT 50


// 以下定义使用FR共轭梯度 
#define __FR_GC__

#endif

