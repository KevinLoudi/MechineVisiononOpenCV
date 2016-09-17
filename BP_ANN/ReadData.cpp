#include "ReadData.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

ReadData::ReadData()
{
}

ReadData::~ReadData()
{
}

int ReadData::ReadCSV(double **data,int rownum,int colnum)
{
	std::ifstream file("DayChannelState.csv");
	
	for(int row = 0; row < rownum; ++row)
    {
        std::string line;
        std::getline(file, line);
        if ( !file.good() )
            break;

        std::stringstream iss(line);

        for (int col = 0; col < colnum; ++col)
        {
            std::string val;
            std::getline(iss, val, ',');
            if ( !iss.good() )
                break;

            std::stringstream convertor(val);
            convertor >> data[row][col];
        }
    }	
	return 0;
}
