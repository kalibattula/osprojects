#include<iostream>
#include<fstream>
#include<bitset>
#include<string>
#include<conio.h>

using namespace std;

int main(){
	fstream interfile,outfile;
	
	interfile.open("intermediate.txt", ios::in);
	outfile.open("output.txt", ios::out| ios::trunc);
	
	string frame;
	string synbit1,synbit2;
	unsigned long data;
	int frame_length;
	
	if(!interfile.is_open()){
		
		cout<<"File didn't opened due to error"<<endl;
		
	}else{
		while(getline(interfile,frame)){

			synbit1 = frame.substr(0,8);
			synbit2 = frame.substr(8,8);
			int i = 3;

			if(bitset<8>(synbit1).to_ulong()==22 && bitset<8>(synbit2).to_ulong()==22){

				frame_length = bitset<8>(frame.substr(16,8)).to_ulong();
				if(frame_length==64){										//This is for all the frames except last frame
						while(i<67){
						data=bitset<7>(frame.substr(i*8+1,7)).to_ulong(); //Getting ASCII value of each byte of data.
						outfile<<char(data);
						cout<<char(data);
						i++;
					}
				}else{

					while(i<frame_length-1){								//This is for the last frame.
						data=bitset<7>(frame.substr(i*8+1,7)).to_ulong(); //Getting ASCII value of each character.
						outfile<<char(data);
						cout<<char(data);
						i++;
					}
				}
			}
		}
	}
	interfile.close();
	outfile.close();
	cout<<"\n Data successfully received and stored in output.txt file"<<endl;
	getch();
	return 0;
}
