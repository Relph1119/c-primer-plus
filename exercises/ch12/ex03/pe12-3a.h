//
// Created by HRF on 2021/11/14.
//
// 公制
#define METRIC 0
// 美制
#define US 1

// 设置模式
void set_mode(int *mode);
// 根据用户输入的模式提示用户输入相应数据
void get_info(int mode, double *pd, double *pf);
// 根据设置的模式计算并显示油耗
void show_info(int mode, double pd, double pf);