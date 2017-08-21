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

class CachedParity
{
	int wordsize = 16;
	int mask = 0b1111111111111111;
	int cache[65536];
	public:
		CachedParity()
		{
			for(int i=0; i<65536; ++i)
			{
				cache[i] = computeParityOptimized(i);
//				std::cout<<std::endl<<i<<" "<<cache[i];
			}
		}
		int Compute(int64_t x)
		{
	//		std::cout<<std::endl<<x<<" "<<((x>>3*wordsize)&mask)<<'a';
	//		std::cout<<std::endl<<x<<" "<<((x>>2*wordsize)&mask)<<'b';
	//		std::cout<<std::endl<<x<<" "<<((x>>1*wordsize)&mask)<<'c';
	//		std::cout<<std::endl<<x<<" "<<((x>>0*wordsize)&mask)<<'d';
	//		std::cout<<std::endl;
			return cache[x>>(3*wordsize)]
					^ cache[ (x>>(2*wordsize)) & mask] 
					^ cache[ (x>>(1*wordsize)) & mask] 
					^ cache[ (x>>(0*wordsize)) & mask]; 
		}
};

int main()
{
	int num = 65537;
	//int num = 0b1010001101;
	CachedParity cache;	
	for(int num = 16; num < 444465536; ++num )
	{

	if((computeParity(num) == computeParityOptimized(num)) && (computeParity(num) == cache.Compute(num)))
		;
	else
		std::cout<<std::endl<<"Error: "<<num<<" - "<<computeParity(num)<<" "<<computeParityOptimized(num)<<" "<<cache.Compute(num);
	//std::cout<<std::endl<<"Parity: "<<computeParity(num)<<std::endl;
	//std::cout<<std::endl<<"ParityOptimized: "<<computeParityOptimized(num)<<std::endl;
	
	//std::cout<<std::endl<<"ParityCached: "<<cache.Compute(num)<<std::endl;
	}
}
