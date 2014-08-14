/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : main.c

* Purpose : Simulating the Urn based model for predicting individual Color value

* Created By : B Harendra Prasad

_._._._._._._._._._._._._._._._._._._._._.*/


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "gsl/gsl_sf_zeta.h"
#include "colour.cpp"
#define TRAILS 1000


using namespace std;

main(){
	long long unsigned int N=1000;
	long long unsigned int color_no;
	long long unsigned int max_color_no=1;
	double K ;//= 1.895;
	double count_K,color_value;
	color_no = 0;
	//cout<<"Enter the value of N : \n";
	//cin>>N;

	//cout<<"Enter the value of exponent: \n";
	cin>>K;
	//for(K=2;K>1.8;K=K-(0.005)){
	count_K = K;
	
	//cout<<"No. of colors Req. : \n";
	//cin>>max_color_no;
	
	
	srand(time(NULL));
	
	node* temp;
	int i,j;

	double** COLOR;
	COLOR = (double**)malloc(TRAILS*sizeof(double*));
	for(i=0; i<TRAILS; i++)
		COLOR[i] = (double*)malloc(TRAILS*sizeof(double));
	

	for(i=0;i<TRAILS;i++)
		for(j=0;j<TRAILS;j++)
			COLOR[i][j] =0;


	double C = 1.0/gsl_sf_zeta(K);

	output test,test1;
	output initial;

	for(i=0 ; i< TRAILS; i++){
			test = coloring(N,count_K,initial);
			temp = test.head;
			color_no = 0; 
		
		
		while(temp != NULL){
			if(color_no >= max_color_no)
				break;
			if(temp->value == color_no){
				COLOR[i][color_no] = temp->count + test.color_0 * (C / pow(1+color_no,count_K));
				temp = temp->right;
			}	
			else
				COLOR[i][color_no] = test.color_0 * (C / pow(1+color_no,count_K));	
			color_no++;
		}	

	
		while(color_no < max_color_no){
			COLOR[i][color_no] = test.color_0 * (C / pow(1+color_no,count_K));
			color_no++;
		}
	}



	
	
	double max_color_value = 0;
	long long unsigned int count,gen,counter;
	double log_P,log_count,B;
	gen =0;
	
	
	for(count = 0; count<TRAILS; count++)
		if(max_color_value < COLOR[count][0])
			max_color_value = COLOR[count][0];
	
	//cout<<K<<"\t"<<max_color_value/N<<"\n";
		
	
	double* P;
	P = (double*)malloc(max_color_value*sizeof(double));
		for(count =0; count<max_color_value; count++)
			P[count] = 0.0;

	cout.precision(15);
	
	int temp_P=0;
	double temp_C[100];	

	//max_color_value = TRAILS;
	for(count =0; count<max_color_value; count++){
		for(counter =0; counter<TRAILS; counter++)
			if((max_color_value - count)	<= COLOR[counter][0])						
				P[count]++;
			if(count/max_color_value >= temp_P*0.01){
				if(temp_P != 0)
					temp_C[temp_P] = (P[count]-P[gen])/TRAILS;
				else
					temp_C[temp_P] = (P[count]/TRAILS);
				cout<<temp_P*0.01<<"\t"<<temp_C[temp_P]<<"\n";
				gen = count;
				temp_P++;
			}
	}
		//cout<<temp_P*0.01<<"\t"<<P[count]-P[count-1]<<"\n";
				
	/*for(count =0; count<max_color_value; count++){
		P[count] = P[count]/TRAILS;
		
		log_P = (-1)*log(P[count]);
		log_count = log(((double)(count+1)/max_color_value))*(-1);
		B = log_P/log_count;
		//cout<<(double)(count+1)/max_color_value<<"\t\t"<<temp_P<<"\n";
		//cout<<log_count<<"\t"<<log_P<<"\n";		
		if(P[count] >= 0.9)
			break;
	}*/

	//for(count =0 ;count<temp_P;count++)
	//	cout<<count*0.01<<"\t"<<temp_C[count]<<"\n";




	//free(P);
	for(i =0; i <TRAILS; i++)
		free(COLOR[i]);
	free(COLOR);


}



