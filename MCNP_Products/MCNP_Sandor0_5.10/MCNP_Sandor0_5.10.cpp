// MCNP_Sandor0_5.10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <regex>
#include "Product.h"
void citire(std::vector<Product>& produse)
{
	
	//std::ifstream f{ "product.prodb" };
	for(std::ifstream f{ "product.prodb" };!f.eof();)
	{
		uint16_t id, tva;
		std::string name, str;
		float price;
		std::regex dateformat(R"(\d\d\d\d-\d\d-\d\d)");
		f >> id >> name >> price >> tva;
		f >> str;
		if (std::regex_match(str, dateformat))
		{
			produse.emplace_back(Product (id, name, price, tva, str));
		}
		else
		{
			produse.emplace_back(Product (id, name, price, tva, parseProductType(str)));
		}

		
	}
}
bool CompareNume(const Product& p1, const Product& p2)
{
	return p1.Getname() < p2.Getname();
}
int main()
{
	std::vector<Product>produse;
	citire(produse);
	for (const Product& product : produse)
	{
		if (product.Gettva() == 19)
		{
			std::cout << product;
		}
	}
	for (int i = 0; i < produse.size(); i++)
	{
		if (produse[i].Gettva() == 19)
		{
			std::cout << produse[i];
		}
	}


	// 1. functie comparator (functie obisnuita)
	std::sort(produse.begin(), produse.end(), CompareNume);
	// 2. operatorul <
	std::sort(produse.begin(), produse.end());
	// 3. functie lambda
	std::sort(produse.begin(), produse.end(),[produse](const Product& p1, const Product& p2){
		return p1.Getprice() < p2.Getprice();
		});
	// 4. metoda a clasei
	std::sort(produse.begin(), produse.end(), ComparePrice);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
