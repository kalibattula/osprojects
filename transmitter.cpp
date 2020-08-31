#include<iostream>
#include<fstream>
#include<bitset>
#include<string>
#include<conio.h>

using namespace std;

int main(){
	fstream infile,outfile;
	infile.open("input.txt",ios::in); //opening the input file
	outfile.open("intermediate.txt",ios::out|ios::trunc); //opening the intermediate file

	char c;
	int ascii_val;	
	string frame_array[68]; //creating an array for a frame
	frame_array[0] = bitset<8>(22).to_string();
	frame_array[1] = bitset<8>(22).to_string();
	int dataCount = 3;
	
	if(!infile.is_open()){
		cout<<"File not opened due to error";
	}else{
		while(infile.good()){
			
			infile.get(c); // get method is used to read a single character from a file.
			
			ascii_val=int(c); // int() method is used to get the ascii value of the character.
			
			string str = bitset<7>(ascii_val).to_string(); //converting ascii value to bits using bitset module.
			
			string s2;
			char countChar = '1';
			char zero='0';
			char one='1';
		    int count = 0;
		    
			for (int i = 0; i < str.size(); i++)  // count number of ones in a file.
		    {
		        if (str[i] ==  countChar)
		        {
		            ++ count;
		        }
		    }
		    if(count%2==0){  // checking no of ones in binary file and adding odd parity bit
		    	s2=one;
		    	s2+=str;
			}else{
				s2=zero;// appending a string.
				s2+=str;
			}
			
			
			frame_array[dataCount] = s2; //inserting data into frame
			dataCount++;
			if(dataCount==67){
				frame_array[2] = bitset<8>(64).to_string();
				for(int i=0;i<67;i++){
					outfile<<frame_array[i]; //storing a frame in the intermediate file.
				}
				outfile<<"\n";
				dataCount = 3; 
			}
			cout<<s2<<" ";
		}
		frame_array[2] = bitset<8>(dataCount).to_string();
		for(int i=0;i<dataCount-1;i++){
			outfile<<frame_array[i]; //put the final frame into the intermediate file.
		}
//		cout<<dataCount-1;
		cout<<"\n Frames are stored in intermediate.txt file"<<endl;
	}
	infile.close();
	outfile.close();
	getch();
	return 0;
}
