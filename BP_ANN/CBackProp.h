#ifndef CBACKPROP_H
#define CBACKPROP_H

#include<assert.h>
#include<iostream>
#include<stdio.h>
#include<math.h>

class CBackProp
{
//	output of each neuron
	double **out; //the output of the ith neuron of the jth layer is out[i][j]

//	delta error value for each neuron
	double **delta;

//	vector of weights for each neuron
	double ***weight; //w[i][k][j] 
	//weight connection between (i-1)th layer's jth neuron and ith layer's kth neuron

//	no of layers in net
//	including input layer
	int numl;

//	vector of numl elements for size 
//	of each layer
	int *lsize;

//	learning rate
	double beta;

//	momentum parameter
	double alpha;

//	storage for weight-change made
//	in previous epoch
	double ***prevDwt;

//	squashing function
	double sigmoid(double in);

public:

	~CBackProp();

//	initializes and allocates memory
	CBackProp(int nl,int *sz,double b,double a);

//	backpropogates error for one set of input
	void bpgt(double *in,double *tgt);

//	feed forwards activations for one set of inputs
	void ffwd(double *in);

//	returns mean square error of the net
	double mse(double *tgt) const;	
	
//	returns i'th output of the net
	double Out(int i) const;
};

#endif
