#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include"point.h"
#include"read.h"
#include"K-means.h"
#include"process.h"

using namespace std;

int main(int argc, char const *argv[])
{
	if(argc<5)
	{
		cout<<"1.Enter the file name of data>>"<<endl;
		cout<<"2.Enter the dimention of data>>"<<endl;
		cout<<"3.Enter the amount of cluster>>"<<endl;
		cout<<"4.Enter the Tempurature of SA>>"<<endl;
		return 0;
	}

	string Filename=argv[1];
	int Dimention=atoi(argv[2]);
	int AmountCluster=atoi(argv[3]);
	int Tempurature=atoi(argv[4]);

	vector<dataPoint> data;

	read(Filename,Dimention,data);

	cout<<setw(28)<<"========"<<setw(12)<<"K-means"<<setw(12)<<"========"<<endl;
	Kmeans(data,Dimention,AmountCluster,Tempurature);
	cout<<setw(28)<<"========"<<setw(12)<<"K-means"<<setw(12)<<"========"<<endl;

	/*
	int m=1;
	for(int i=0;i<(int)data.size();i++)                                                                
	{
		if((i/50)+1 != m)cout<<endl<<endl;
		cout<<data[i].getIndex()<<": "<<data[i].getCluster()<<" ";
		m=(i/50)+1;
	}
	cout<<endl;
	*/

	correct_rate(data,AmountCluster);
}
