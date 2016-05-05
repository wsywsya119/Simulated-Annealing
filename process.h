#ifndef __PROCESS__H__
#define __PROCESS__H__

#include<iostream>
#include<vector>
#include"point.h"

using namespace std;

void random_initial(vector<centerPoint> &center, vector<dataPoint> &data, int amountCluster);

double distance(vector<dataPoint> &data, vector<centerPoint> &center);

void update_center(vector<dataPoint> &data, vector<centerPoint> &center, int dimention);

void correct_rate(vector<dataPoint> &data, int amountCluster);

#endif
