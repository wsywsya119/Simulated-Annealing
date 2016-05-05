#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include"read.h"

using namespace std;

void read(string filename, int dimention,vector<dataPoint> &data)
{
	ifstream input;
	string line;

	input.open(filename.c_str(),ifstream::in);

	int Dim=0;
	while(getline(input,line))
	{
		istringstream token(line);
		string word;

		dataPoint initial;
		while(getline(token,word,','))
		{
			initial.addDim(atof(word.c_str()));
			++Dim;
			if(Dim==dimention)
			{
				getline(token,word,',');
				initial.setClassName(word);
				break;
			}
		}
		data.push_back(initial);
		Dim=0;
	}

	input.close();
}
