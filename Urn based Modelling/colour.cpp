#include <iostream>

typedef struct _Node {	
	long long unsigned int value;
	double count;
	struct _Node *left;
	struct _Node *right;	
}node;

typedef struct _output{
	node* head;
	long long unsigned int color_0;
}output;



node* init(node* head){
	head->value = 0;
	head->count = 1;
	head->right = NULL;
	head->left = NULL;
return head;
}

output coloring (long long unsigned int N,double k, output test){
	test.head = new node;	
	test.head = init(test.head);
	long long unsigned int color_no,change_color_no,check;
	long long unsigned int counter = 1;
	long long unsigned int z_counter = 0;	
	std::cout.precision(15);
	double C = 1.0/gsl_sf_zeta(k);
	node* temp;
	node* root;
	node* tester;
	double X;
	double sum;
	temp = test.head;
	root = temp;
	tester = root;
	//srand(time(NULL));
	while(counter <= N){
		color_no = 0;
		X = 1.0*counter*rand()/RAND_MAX;		
		sum = 0.0;
		while(sum <= X){
//std::cout<<"Sum ---"<<sum<<"\t"<<X<<"\n"; 
			if(color_no != temp->value)
				sum = sum + z_counter*((double)C/pow((1+color_no),k));
			else{
				sum = sum + temp->count + z_counter*((double)C/pow((1+color_no),k));
				if(temp->right != NULL){			
					temp = temp->right;
					check = temp->value;					
				}
			}
			color_no++;
		}
		color_no--;



/*
		while(tester != NULL){
			std::cout<<tester->count<<"("<<tester->value<<")\t";
			tester  = tester->right;
		}
		std::cout<<z_counter<<"(colour_0)\n";
		std::cout<<color_no<<" color\t";
		std::cout<<temp->value<<"   current color\n\n";
*/


		if(check >= color_no)
			if(temp->left != NULL)
				if(temp->left->value == color_no)
					temp = temp->left;	
		if(color_no == 0)
			z_counter++;
		
		else{
			change_color_no = color_no - 1;
			if(temp->value == change_color_no)
				temp->count++; 
			else if((temp->left == NULL)&&(temp->value > change_color_no)){				
				node* node_first = new node;
				node_first->left = NULL;
				node_first->right = temp;
				temp->left = node_first;
				node_first->value = change_color_no;
				node_first->count = 1;
				root = node_first;
			}
			else if((temp->value > change_color_no)&&(temp->left->value < change_color_no)){
				node* node_center = new node;
				node_center->value = change_color_no;
				node_center->count = 1;
				node_center->right = temp;
				node_center->left = temp->left;
				temp->left->right = node_center;
				temp->left = node_center;
			}
			else if((temp->value > change_color_no)&&(temp->left->value == change_color_no))
				temp->left->count++;
			else if(temp->value < change_color_no){
				node* node_end = new node;
				node_end->value = change_color_no;
				node_end->count = 1;
				node_end->left = temp;
				temp->right = node_end;
				node_end->right = NULL;
			}
		}			
		counter++;
		tester = root;
		temp = root;
	}
	test.head = root;
	test.color_0 = z_counter;
return test;
}











