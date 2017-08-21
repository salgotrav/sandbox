#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

int StringToInt(std::string str)
{
	if(str.size()==0)
		return 0;
	
	bool positiveSign = str[0]=='-' ? false : true;

	int num =0;
	int start = positiveSign ? 0 : 1;
	for(int i = start; i<str.size(); ++i)
		num = num*10 + (str[i]-'0');
	
	if(positiveSign == false)
		num *= -1;	
	return num;
}

std::string IntToString(int num)
{
	std::string str;
	bool positiveSign = num>=0 ? true : false;
	num = std::abs(num);
	
	if(num == 0)
		return "0";
	
	while(num)
	{
		int rem = num%10;
		str += '0'+rem;
		num /= 10;
	}
	
	if(positiveSign == false)
		str += '-';
	std::reverse(str.begin(), str.end());
	return str;
}

int main()
{
 //	int num = -12345;
//	std::cout<<"String: "<<IntToString(num)<<std::endl;

	std::string str = "-0";
	std::cout<<"Num: "<<StringToInt(str)<<std::endl;
}
