#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int maxProfit(std::vector<int> data)
{
	int minPriceSoFar = std::numeric_limits<int>::max();
	int maxProfit = 0;
	for(auto price : data)
	{
		int maxProfitSellToday = price - minPriceSoFar;
		maxProfit = std::max(maxProfit, maxProfitSellToday);
		minPriceSoFar = std::min(minPriceSoFar, price);
	}	
	return maxProfit;
}

int main()
{
	std::vector<int> data = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
	std::cout<<"MaxProfit: "<<maxProfit(data);

}
