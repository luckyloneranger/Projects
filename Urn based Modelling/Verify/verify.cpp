//Verifies the colouring program using pre-proved functions
//For a given 'B'(beta) of Riemann Zeta Functions and numbers of iterations
//the individual components can be determined.


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "gsl/gsl_sf_zeta.h"

using namespace std;

main(){

	long long unsigned int color_no;
	int i;
	double K;
	double Z_req;
	double Z_req_1;
	double color_value = 0.0;

	cout.precision(15);

	cin>>color_no;
	cin>>K;
	Z_req = gsl_sf_zeta(K);
	Z_req_1 = gsl_sf_zeta(K-1);

	color_value = 0;
	for(i=1; i<= color_no; i++)
		color_value = color_value + (1.0/pow(i,color_no));
	
	color_value = (Z_req/Z_req_1) + color_value*(1/Z_req_1);

	cout<<color_value<<"\n";
}
