#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>

using namespace std;

string addTxt;
string rvrsTxt;
string txtFromFile;
stringstream strStream;

int main(){

	char userInput = 'a';

	while(userInput!='Q'){

		//get user command
		cout<<"Enter \"A\" to add text to file, \"R\" to reverse text in file, or \"Q\" to quit: "<<endl;
		cin>>userInput;
		cout<<"\n";
		cin.ignore();

		if(userInput=='Q'){continue;}

		if(userInput=='A'){

			//get user entry
			cout<<"Enter text to be added to file: "<<endl;
			getline(cin, addTxt);
			cout<<"\n";

			//open file and write user entry
			ofstream regFile("CSC450_CT5_mod5.txt", std::ios_base::app);
			if(regFile.is_open()){
				regFile<<addTxt<<"\n";
				cout<<"Successfully added text"<<endl;
				cout<<"\n";
				regFile.close();
			}
			else{
				cout<<"Unable to open file"<<endl;
				cout<<"\n";
			}
			continue;
		}
		else if(userInput=='R'){

			//get text from file
			ifstream regFile("CSC450_CT5_mod5.txt");
			if(regFile.is_open()){
				strStream<<regFile.rdbuf();
				txtFromFile = strStream.str();
				cout<<"Successfully read text from file"<<endl;
				cout<<"\n";
				regFile.close();
			}
			else{
				cout<<"Unable to open read file"<<endl;
				cout<<"\n";
				continue;
			}

			//reverse text
			int i;
			int len = txtFromFile.length();
			char preReversed[len];
			char postReversed[len];
			for(i=0;i<len;++i){
				preReversed[i] = txtFromFile.at(i);
			}
			for(i=0; i<len; ++i) {
				postReversed[i] = preReversed[len - 1 - i];
			}
			rvrsTxt = postReversed;

			//write reversed text to file
			ofstream rvrsFile("CSC450-mod5-reverse.txt", std::ios_base::app);
			if(rvrsFile.is_open()){
				rvrsFile<<rvrsTxt<<"\n";
				cout<<"Successfully wrote reversed text to file"<<endl;
				cout<<"\n";
				rvrsFile.close();
			}
			else{
				cout<<"Unable to open write file"<<endl;
				cout<<"\n";
			}

			continue;
		}
		else{
			cout<<"Invalid command. Please enter a new character."<<endl;
			cout<<"\n";
			continue;
		}

	}

	cout<<"Program terminated"<<endl;
}
