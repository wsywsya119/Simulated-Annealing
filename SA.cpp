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
	double result=0,resultPre=numeric_limits<double>::max(),resultBest=0;
	double diff=0,prob=0;
	double ran2=0;
	vector<centerPoint> keep,keepBest;

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

		cout<<"Result: "<<result<<endl;

		if(diff < 0)
		{
			resultBest = resultPre = result;
			center = keep;
		}
		else
		{
			prob = exp((-5*(diff))/tempurature);
			ran2 = (double)rand()/(double)RAND_MAX;
			cout<<"prob: "<<prob<<" ran: "<<ran2<<endl;
			if(ran2 <= prob)
			{

				resultPre = result;
				center = keep;
			}
		}
		cout<<"Keeping Result: "<<resultBest<<endl;
	}
}
