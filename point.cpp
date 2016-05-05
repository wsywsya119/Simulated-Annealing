#include<iostream>
#include"point.h"

using namespace std;

//point......
point::point(){}
point::point(int i)
{
	index=i;
}

int point::getIndex()
{
	return(index);
}

void point::setIndex(int i)
{
	index=i;
}

void point::setClassName(string name)
{
	className=name;
}

string point::getClassName()
{
	return(className);
}

vector<double> &point::getDimention()
{
	return(dimention);
}

void point::addDim(double in)
{
	dimention.push_back(in);
}

void point::clearDim()
{
	dimention.clear();
}

void point::copyDimention(point &f)
{
	this->dimention = f.dimention;
}

void point::printInfo()
{
	cout<<index<<" ";
	for(int i=0;i<(int)dimention.size();i++)
	{
		cout<<dimention[i]<<" ";
	}
	cout<<endl;
}


//centerPoint......
int centerPoint::amountPoint=0;

centerPoint::centerPoint():point(++amountPoint)
{
	this->setIndex(amountPoint);
	amountDataPoint = 0;
}

void centerPoint::reset()
{
	amountPoint = 0;
}

int centerPoint::getAmountPoint()
{
	return(amountPoint);
}

int centerPoint::getAmountDataPoint()
{
	return(amountDataPoint);
}

void centerPoint::setAmountDataPoint(int d)
{
	amountDataPoint = d;
}

void centerPoint::addAmountDataPoint()
{
	++amountDataPoint;
}

//dataPoint......
int dataPoint::amountPoint=0;

dataPoint::dataPoint():point(++amountPoint)
{
	cluster=0;
}

int dataPoint::getCluster()
{
	return(cluster);
}

void dataPoint::setCluster(int c)
{
	cluster = c;
}

double dataPoint::getDistance()
{
	return(distance);
}

void dataPoint::setDistance(double d)
{
	distance = d;
}
