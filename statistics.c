/* Derived from https://rosettacode.org/wiki/Cumulative_standard_deviation#C
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "statistics.h"

StatObject NewStatObject()
{
  StatObject so;
 
  so = malloc(sizeof(sStatObject));
  so->sum = 0.0;
  so->sum2 = 0.0;
  so->num = 0;
  return so;
}


void stat_obj_value(StatObject so,StatResult sr)
{
  sr->num = so->num;
  sr->mean = so->sum/so->num;
  sr->var = so->sum2/so->num - sr->mean*sr->mean;
  sr->stddev = sqrt(sr->var);
  sr->min = so->min;
  sr->max = so->max;
  return;
}

void stat_object_add(StatObject so, double v)
{
  so->sum += v;
  so->sum2 += v * v;
  if (!so->num || so->min > v)
    so->min = v;
  if (!so->num || so->max < v)
    so->max = v;
  so->num++;
  return;
}