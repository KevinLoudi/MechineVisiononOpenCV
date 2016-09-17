#ifndef READDATA_H
#define READDATA_H

#include <string>
using namespace std;

class ReadData
{
	public:
		ReadData();
		~ReadData();
		int ReadCSV(double **data,int rownum,int colnum);
	private:
		//int rownum;
		//int colnum;
};

#endif
