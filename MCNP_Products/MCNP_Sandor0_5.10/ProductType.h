#include <cstdint>
#include <string>
#include <iostream>
enum class ProductType: uint8_t
{
	PersonalHygiene, 
	SmallAppliences, 
	Clothing
};
ProductType parseProductType(const std::string& str);
std::ostream& operator <<(std::ostream& os, const ProductType& type);
