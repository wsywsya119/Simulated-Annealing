#include"SA.h"
#include"process.h"
#include<iostream>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<limits>

using namespace std;


void SA(vector<centerPoint> &center, vector<dataPoint> &data, int amountCluster, int dimention, int tempurature)
{
	int ran=0;
	double result=0,resultPre=numeric_limits<double>::max();
	double diff=0,prob=0;
	vector<centerPoint> keep;

	for(int j=0;j<amountCluster;j++)
	{
		centerPoint ini;
		keep.push_back(ini);
	}

	srand((unsigned)time(NULL));
	for(int i=tempurature;i>0;i=i-1)
	{
		for(int j=0;j<(int)data.size();j++)
		{
			ran = rand()%amountCluster + 1;
			data[j].setCluster(ran);
		}

		update_center(data,keep,dimention);
		result = distance(data,keep);

		diff = result - resultPre;

		if(diff < 0)
		{
			resultPre = result;
			center = keep;
		}
		else
		{
			prob = exp((-1*diff)/tempurature);
			ran = (double)rand()/(double)RAND_MAX;
			if(ran >= prob)
			{
				resultPre = result;
				center = keep;
			}
		}
	}
}
