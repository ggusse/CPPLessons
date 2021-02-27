#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

int main() {

	char userEntry[30];

	//loop to run program within
	do {

		//prompt user for entry
		cout<<"Enter string to be reversed or \'Q\' if you would like to quit: "<<endl;
		cin.getline(userEntry, 29);

		if((char)(userEntry[0])!='Q'){

			//declaration of variables
			char reversedString[30];
			size_t i;

			//loop to reverse string
			for(i=0; i<strlen(userEntry); ++i) {
				reversedString[i] = userEntry[strlen(userEntry) - 1 - i];
			}

			//output reversed string
			cout<<"Reversed string: "<<reversedString<<endl;
		}

	} while((char)(userEntry[0])!='Q');

	cout<<"Program was terminated"<<endl;
}
