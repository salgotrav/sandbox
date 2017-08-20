#include <iostream>
#include <stdint.h>

//drops off each  bit on each iteration by shifting, complexity is o(n)
int computeParity(int64_t x)
{
	int parity = 0;
	while(x)
	{
		parity += (x&1);
		x = (x>>1);
	}
	return parity%2;
}

//optimized as it drops all till 1 on each iteration. complexity is o(k), where k is the number of bits set.
int computeParityOptimized(int64_t x)
{
	int parity =0;
	while(x)
	{
		++parity; 
		x = x&(x-1);
	}
	return parity%2;
}

int main()
{
	int num = 0b110110010000;
	std::cout<<std::endl<<"Parity: "<<computeParity(num)<<std::endl;
	std::cout<<std::endl<<"ParityOptimized: "<<computeParityOptimized(num)<<std::endl;
}
