#include <iostream>

using namespace std;

int main() {

	char userInput = 'A';

	do {

		//initialize variables
		int a;
		int b;
		int c;
		int* aPointer = new int(a);
		int* bPointer = new int(b);
		int* cPointer = new int(c);

		//check for sufficient memory to run
		if((aPointer=new int(a))==0||(bPointer=new int(b))==0||(cPointer=new int(c))==0){
			cerr<<"Insufficient memory";
			exit(1);
		}

		//prompt user whether to run program
		cout<<"Type \'R\' to run or type \'Q\' to quit: "<<endl;
		cin>>userInput;

		//get and print integers and pointers
		if(userInput!='Q'){
			cout<<"Enter first integer: "<<endl;
			cin>>a;

			cout<<"Enter second integer: "<<endl;
			cin>>b;

			cout<<"Enter third integer: "<<endl;
			cin>>c;

			cout<<"Variable 1: "<<a<<endl;
			cout<<"Variable 1 Pointer: "<<aPointer<<endl;

			cout<<"Variable 2: "<<b<<endl;
			cout<<"Variable 2 Pointer: "<<bPointer<<endl;

			cout<<"Variable 3: "<<c<<endl;
			cout<<"Variable 3 Pointer: "<<cPointer<<endl;
		}

		//set integers to 0
		a = a - a;
		b = b - b;
		c = c - c;

		//clear pointers from memory
		delete aPointer;
		delete bPointer;
		delete cPointer;

	} while(userInput!='Q');

	cout<<"Program was terminated"<<endl;

	return 0;
}
