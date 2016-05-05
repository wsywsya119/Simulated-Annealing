#include"K-means.h"
#include"process.h"
#include"SA.h"
#include<iomanip>

void Kmeans(vector<dataPoint> &data, int dimention, int amountCluster, int tempurature)
{
	vector<centerPoint> center;

	SA(center,data,amountCluster,dimention,tempurature);
	//random_initial(center,data,amountCluster);

	double result=0,last=0;

	while(1)
	{
		result = distance(data,center);
		update_center(data,center,dimention);
		if(last!=result)
		{	
			last = result;
		}
		else
		{
			break;
		}
		cout<<"\033[1;12mSSE\033[0m:"<<setw(8)<<result<<" ";
		cout.precision(6);
		for(int i=0;i<(int)center.size();i++)
		{
		cout<<"\033[1;12mcluster_"<<center[i].getIndex()<<"\033[0m";
		cout<<":"<<setw(3)<<center[i].getAmountDataPoint();
		cout<<" points";
		if(i<(int)center.size()-1)cout<<", ";
		}
		cout<<endl;
	}

}















