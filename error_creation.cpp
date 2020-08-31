#include<iostream>
#include<fstream>
#include<bitset>
#include<string>
#include<ctime>
#include<cstdlib>
#include<conio.h>

using namespace std;

int main(){
	srand(time(NULL));
	
	fstream errfile,interfile;
	
	errfile.open("errfile.txt",ios::out|ios::trunc);
	interfile.open("intermediate.txt",ios::in); //opening the intermediate file.
	
	string frame,frame1;
	
	int n,bit_no,byte_no;
	cout<<"How many bits u have to modify:";
	cin>>n;
	
	if(!errfile.is_open() || !interfile.is_open()){
		cout<<"Unable to open the files"<<endl;
	}else{
		while(interfile.good()){
			getline(interfile,frame);

			while(n>0){
					bit_no = (rand() % 100)+24; //Generating a random number
					byte_no = bit_no/8;
						
					if(frame[bit_no]=='0'){		// modifying the bits at random positions.
						frame[bit_no]='1';
					}else{
						frame[bit_no]='0';
					}
//					cout<<frame[bit_no]<<endl;
					cout<<bit_no<<" bit is modified and byte no is "<<byte_no<<" in frame1"<<endl;
					n--;
			}
			errfile<<frame<<endl; // storing the modified frame into a new file.
		}
	}
	
	cout<<"\n Error file is successfully created and stored in errfile.txt"<<endl;
	getch();
	
	return 0;
}
