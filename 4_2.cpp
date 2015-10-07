#include <iostream>
using namespace std;
int solution(char * a)
{
	int answer = 0, summand = 0, sign = 1;
	for (int i = 0; i < strlen(a);i++)
		if (isdigit(a[i]))
		{
			summand = summand * 10 + (a[i] - '0');
		}
		else
		{
			answer = answer + sign*summand;
			if (a[i] == '+') sign = 1;
			else sign = -1;
			summand = 0;
		}
	answer = answer + sign*summand;
	return answer;
}

void assert(char * test, int reqAns)
{
	if (solution(test) == reqAns)
		cout << "OK" << endl;
	else 
		cout << "FAIL" << endl;
}

int main()
{
	assert("34-12-10+4", 16);
	assert("11-14+3", 0);
	assert("99-98-97+1+4-2", -93);
	assert("150-19-31+20-80-40", 0);
	assert("412401-41219+1245950-100000+2340001", 3857133);
	assert("14245-1541-1668904+412950", -1243250);
	system("pause");
	return 0;
}
