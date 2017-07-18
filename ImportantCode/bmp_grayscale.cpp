#include<iostream>
#include<fstream>

using namespace std;

int main()
{	
	ifstream iFile;
	ofstream oFile;		
	unsigned char header[54];
	iFile.open("input.bmp");	
	if(iFile.is_open())
	{
		oFile.open("output.bmp",ios::out|ios::binary);
		if(oFile.is_open())
		{			
			for(int i=0;i<54;i++)
			{
				char ch = iFile.get();
				header[i]=ch;
				oFile << ch;
			}

			int width = *(int*)&header[18];
		    int height = *(int*)&header[22];									
			int size = width*height*3;						
			unsigned char* colorValues = new unsigned char[size];			

			for(int i=0;i<size;i++)
			{
				char ch = iFile.get();				
				colorValues[i]=ch;
			}

			for(int i = 0; i < size; i += 3)
			{
				int avg = ((int)colorValues[i] + (int)colorValues[i+1] + (int)colorValues[i+2])/3;
				colorValues[i]=(unsigned char)avg;
				colorValues[i+1]=(unsigned char)avg;
				colorValues[i+2]=(unsigned char)avg;					
			}

			for(int i=0;i<size;i++)
			{
				char ch = colorValues[i];
				oFile << ch;
			}

			while(!iFile.eof())
			{
				char ch = iFile.get();
				oFile << ch;				
			}
		}
		oFile.close();
		iFile.close();
	}
	else
	{
		cout << "input file not found" << endl;
	}		
	return 0;
}