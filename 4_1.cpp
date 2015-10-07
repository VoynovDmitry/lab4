#include <iostream>

using namespace std;

void solve(char in[], int sizeIn, char out[], int &sizeOut)
{
	int pos = 0;
	sizeOut = 0;
	while (pos < sizeIn)
	{
		while ((!isdigit(in[pos])&&(pos<sizeIn)))
			out[sizeOut++] = in[pos++];
		if (pos<sizeIn)
		{
			out[sizeOut++] = '0';
			out[sizeOut++] = 'x';
			int num = 0;
			while ((isdigit(in[pos]))&&(pos<sizeIn)) 
				num = num * 10 + (int)(in[pos++] - (int)'0');
			char numInHex[100];
			int sizeHex=0;
			while (num)
			{
				if (num%16 < 10)
					numInHex[sizeHex++] = (char)(num%16 + (int)'0');
				else
					numInHex[sizeHex++] = (char)((num%16) - 10 + (int)'A');
				num/=16;
			}
			sizeHex--;
			for (  ;sizeHex>=0;sizeHex--) 
				out[sizeOut++] = numInHex[sizeHex];
		}
	}
}

int main()
{
	
	return 0;
}