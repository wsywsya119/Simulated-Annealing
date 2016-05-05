#ifndef __POINT__H__
#define __POINT__H__

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class point{
	private:
		int index;
		string className;
		vector<double> dimention;
	public:
		point();
		point(int i);

		int getIndex();
		void setIndex(int i);
		void setClassName(string name);
		string getClassName();
		vector<double> &getDimention();
		void addDim(double in);
		void clearDim();

		void copyDimention(point &f);
		void printInfo();
};

class centerPoint: public point{
	private:
		static int amountPoint;
		int amountDataPoint;
	public:
		centerPoint();
		void reset();
		int getAmountPoint();
		int getAmountDataPoint();
		void setAmountDataPoint(int d);
		void addAmountDataPoint();
};

class dataPoint: public point{
	private:
		static int amountPoint;
		int cluster;
		double distance;
	public:
		dataPoint();

		int getCluster();
		void setCluster(int c);
		double getDistance();
		void setDistance(double d);
};


#endif
