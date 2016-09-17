#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include "CBackProp.h"
#include "ReadData.h"
using namespace std;

#define rownum 285
#define colnum 801


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void display2d(double** data,int row,int col)
{
	for(int i=0;i<row;i++)
	{
		for(int k=0;k<col;k++)
		{
			cout<<data[i][k]<<" ";
		}
		cout<<endl;
	}
}

void display1d(double* data,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<data[i]<<" ";
		if(i%10==0)
		{
			cout<<endl;
		}
	}
	cout<<endl;
	cout<<"The size of the 1-d array is "<<size<<endl;
}

void Generatecol(double* coldata,int* origdata,int startindex,int endindex)
{
	int index=0;
	for(int i=startindex;i>endindex;i--)
	{
		coldata[index]=origdata[i];
		index++; 
	}
}

int main(int argc, char** argv) {
	
	//define a 2-d array pointer to store
	//channeldata
	double **channeldata;
	channeldata= new double*[rownum];
	
	for(int i=0;i<rownum;++i)
	{
	  channeldata[i]=new double[colnum];
	}

	//read channeldata from csv file, pre-processed 
	//and saved through Matlab
	ReadData File;
	File.ReadCSV(channeldata,rownum,colnum);
	
	//shape the input of the network
	int tao=3; //considering 3 time slots
	int T=rownum; //possible time slots
	int rowsz=tao-1;
	int colsz=T-tao-1;
	double **data;
	data=new double*[rowsz];
	for(int i=0;i<rowsz;++i)
	{
	  data[i]=new double[colsz];
	}
	
	//give value to the input array
	double* seldata=new double[rownum];
	for(int i=0;i<rownum;++i)
		seldata[i]=channeldata[135][i];
	
	//display1d(seldata,rownum);
	
	//get an input data martix for network
	//col
	for(int i=0;i<colsz;i++)
	{
		//row
		for(int j=0;j<rowsz;j++)
		{
			data[j][i]=seldata[tao-j+i];
		}
	}
	
	display2d(data,rowsz,colsz);
	
	//test data set
	//double *testData=new double[T-tao-1];
	double testData[T-tao-1][1];
	int index=0;
	for(int i=tao+1;i<=T;++i)
	{
	  //testData[index]=seldata[i];
	  testData[index][1]=seldata[i];
	  index++;
	} 
	cout<<"The test data set..."<<endl;
	//display1d(testData,T-tao-1);
	
//	double data[][4]={
//				0,	0,	0,	0,
//				0,	0,	1,	1,
//				0,	1,	0,	1,
//				0,	1,	1,	0,
//				1,	0,	0,	1,
//				1,	0,	1,	0,
//				1,	1,	0,	0,
//				1,	1,	1,	1 };
				

	// prepare test data	
//	double testData[][3]={
//								0,      0,      0,
//                                0,      0,      1,
//                                0,      1,      0,
//                                0,      1,      1,
//                                1,      0,      0,
//                                1,      0,      1,
//                                1,      1,      0,
//                                1,      1,      1};
	
	// defining a net with 4 layers having 3,3,3, and 1 neuron respectively,
	// the first layer is input layer i.e. simply holder for the input parameters
	// and has to be the same size as the no of input parameters, in out example 3
	int numLayers = 4, lSz[4] = {3,15,20,1};
	//lSz[4] = {3,3,2,1};
	
	// Learing rate - beta
	// momentum - alpha
	// Threshhold - thresh (value of target mse, training stops once it is achieved)
	double beta = 0.3, alpha = 0.1, Thresh =  0.00001;
    //mse<threshold, traning done
	
	// maximum no of iterations during training
	long num_iter = 2000000;

	
	// Creating the net
	CBackProp *bp = new CBackProp(numLayers, lSz, beta, alpha);
	
	cout<< endl <<  "Now training the network...." << endl;	
	long i=0;
	for (i=0; i<num_iter ; i++)
	{
		
		bp->bpgt(data[i%8], &data[i%8][3]);

		 //mse<threshold, traning done
		if( bp->mse(&data[i%8][3]) < Thresh) {
			cout << endl << "Network Trained. Threshold value achieved in " << i << " iterations." << endl;
			cout << "MSE:  " << bp->mse(&data[i%8][3]) 
				 <<  endl <<  endl;
			break;
		}
		if ( i%(num_iter/10) == 0 )
			cout<<  endl <<  "MSE:  " << bp->mse(&data[i%8][3]) 
				<< "... Training..." << endl;

	}
	
	if ( i == num_iter )
		cout << endl << i << " iterations completed..." 
		<< "MSE: " << bp->mse(&data[(i-1)%8][3]) << endl;  	

	cout<< "Now using the trained network to make predctions on test data...." << endl << endl;	
	//using the trained network to make prediction
//	for ( i = 0 ; i < 8 ; i++ )
//	{
//		bp->ffwd(testData[i]);
//		cout << testData[i][0]<< "  " << testData[i][1]<< "  "  << testData[i][2]<< "  " << bp->Out(0) << endl;
//	}

	system("pause");
	return 0;
}
