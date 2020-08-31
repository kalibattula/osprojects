#include<iostream>
#include<fstream>
#include<bitset>
#include<string>
#include<ctime>
#include<cstdlib>
#include<conio.h>

using namespace std;

string checkError(string data){
	int count;
	for(int i=1;i<data.length();i++){
		if(data[i]=='1'){
			count++;
		}
	}
	
	if(count%2 != (int)data[0]-48){
		return "noerror";
	}else{
		return "error";
	}

}

int main(){
	fstream errfile;
	errfile.open("errfile.txt", ios::in);
	
	string frame;
	string synbit1,synbit2;
	int frame_length;
	string byteData;
	int frameCount=0;
	
	
	if(!errfile.is_open()){
		
		cout<<"File didn't opened due to error"<<endl;
		
	}else{
		while(getline(errfile,frame)){
			frameCount++;
			synbit1 = frame.substr(0,8);
			synbit2 = frame.substr(8,8);
			int i = 3;

			if(bitset<8>(synbit1).to_ulong()==22 && bitset<8>(synbit2).to_ulong()==22){
				frame_length = bitset<8>(frame.substr(16,8)).to_ulong();
				if(frame_length==64){
						while(i<67){
						byteData = frame.substr(i*8,8);
						if(checkError(byteData) == "error"){
							cout<<"Error occured in byte "<<i<<" in frame "<<frameCount<<endl;
						}
						i++;
					}
				}else{
					
					while(i<frame_length-1){
						
						byteData = frame.substr(i*8,8);
						if(checkError(byteData) == "error"){
							cout<<"Error occured in byte "<<i<<" in frame "<<frameCount<<endl;
						}
						i++;
					}
				}
				

			}else{
				cout<<"The Received data is not a frame"<<endl;
			}
		}
	}

	getch();
	return 0;
}
