#include "img_conf.h" 
#include "lv_conf.h"

#if USE_IMG_BATTERY_EMPTY != 0 || LV_APP_USE_INTERNAL_ICONS == 2

#include <stdint.h> 
#include "misc/others/color.h"

const color_int_t img_battery_empty [] = { /*Width = 32, Height = 18*/ 
32,	/*Width*/
18,	/*Heigth*/
16,	/*Color depth = 16*/
1,	/*Flags: Transp = 1*/
2016, 31727, 31695, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 31695, 2016, 2016, 2016, 
27469, 14823, 21130, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 21130, 12710, 25356, 2016, 2016, 
16904, 8452, 27469, 35953, 38066, 38066, 35953, 35921, 35921, 35921, 35921, 35921, 35921, 35921, 35921, 35921, 35921, 35921, 35921, 35921, 35921, 35921, 35921, 35921, 35921, 35953, 38034, 27501, 6371, 14823, 2016, 2016, 
10597, 6339, 35921, 48599, 42260, 42260, 46486, 48631, 48599, 48599, 48599, 48599, 48599, 48599, 48599, 48599, 48599, 48599, 48599, 48599, 48599, 48599, 48599, 48599, 48599, 48631, 52825, 38034, 6339, 8452, 2016, 2016, 
10597, 10565, 46518, 57051, 35921, 35921, 52857, 63390, 61309, 61309, 61309, 61309, 61309, 61309, 61309, 61309, 61309, 61309, 61309, 61309, 61309, 61309, 61309, 61309, 61309, 63390, 65535, 48631, 12678, 2145, 21162, 2016, 
10597, 10597, 52857, 59164, 27469, 25388, 54970, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 54938, 14823, 0, 6371, 25356, 
10597, 12678, 52857, 54938, 14823, 14791, 50712, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 54938, 14823, 0, 0, 14823, 
10597, 12678, 52857, 52857, 10565, 8484, 48599, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 52857, 14823, 0, 0, 10565, 
10597, 12678, 52857, 52857, 10597, 10565, 48631, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 52857, 14823, 0, 0, 10597, 
10597, 12678, 52857, 52857, 12678, 10565, 48631, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 52857, 14823, 0, 0, 12678, 
10597, 12678, 52857, 52857, 12678, 10565, 48631, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 52857, 14823, 0, 0, 12678, 
10597, 12678, 52857, 52857, 10597, 10565, 48599, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 52857, 14823, 0, 0, 10597, 
10597, 12678, 52857, 52825, 8484, 8452, 48599, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 52857, 16904, 0, 0, 8484, 
10597, 12678, 52857, 57051, 19049, 19017, 52825, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 54938, 14823, 0, 32, 19017, 
10597, 10597, 52857, 63422, 42260, 40179, 61277, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 54970, 14791, 2145, 21130, 2016, 
10597, 8452, 42292, 54938, 44405, 44373, 52857, 57083, 57083, 57083, 57083, 57083, 57083, 57083, 57083, 57083, 57083, 57083, 57083, 57083, 57083, 57083, 57083, 57083, 57083, 59164, 61277, 44405, 8484, 6339, 2016, 2016, 
10597, 32, 21162, 29614, 27501, 27501, 29614, 31695, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 29614, 31695, 33808, 23243, 32, 8452, 2016, 2016, 
21130, 8484, 19017, 23275, 25356, 25356, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 23275, 25356, 19017, 6371, 19017, 2016, 2016, 
};

#endif