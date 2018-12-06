
#include <stdio.h>
#include <stdlib.h>

#ifndef _STATS_
#define _STATS_


typedef struct stat_obj_struct {
   double sum, sum2, min, max;
   size_t num;
} sStatObject, *StatObject;

typedef struct stat_result_struct {
    double mean;
    double var;
    double stddev;
    size_t num;
    double min;
    double max;
} sStatResult, *StatResult;

StatObject NewStatObject();
#define FREE_STAT_OBJECT(so) \
   free(so); so = NULL

void stat_obj_value(StatObject so,StatResult sr);
void stat_object_add(StatObject so, double v);


#endif