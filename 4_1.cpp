#include <iostream>

using namespace std;

char * solve(char in[], int sizeIn)
{       
	char out[100];
	int pos = 0;
	int sizeOut = 0;
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
	out[sizeOut++] = '\0';
	return out;
}
void assert(char * in, char *test, int sizeIn)
{
	bool a = true;
	char * result = solve(in , sizeIn);
	if (strlen(test) != strlen(result))
	{
		cout << "FAIL" << endl;
	}
	else
	{
		for (int i = 0; i < strlen(result); i++)
			if (result[i] != test[i]) a = false; 
		if (a) cout << "OK" << endl;
		else  cout << "FAIL" << endl;
	}


}

int main()
{ 
	char a1[] = "aaaaa258xxx";
	char test1[] = "aaaaa0x102xxx";
	assert(a1, test1, 11);
	char a2[] = "16a16a";
	char test2[] = "0x10a0x10a";
	assert(a2, test2, 6);
	char a3[] = "08.10.2015";
	char test3[] = "0x8.0xA.0x7DF";
	assert(a3, test3,10);
	char a4[] = "15+15=30";
	char test4[] = "0xF+0xF=0x1E";
	assert(a4, test4, 8);
	char a5[] = "laba4-2";
	char test5[] = "laba0x4-0x2";
	assert(a5, test5, 7);
	char a6[] = "10A11B12C13D14E";
	char test6[] = "0xAA0xBB0xCC0xDD0xEE";
	assert(a6, test6, 15);
	return 0;
}
