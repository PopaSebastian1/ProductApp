#include "ProductType.h"

ProductType parseProductType(const std::string& str)
{
	if (str == "PersonalHygiene")
		return ProductType::PersonalHygiene;
	if (str == "SmallAppliences")
		return ProductType::SmallAppliences;
	if (str == "Clothing")
		return ProductType::Clothing;
	throw std::exception{ "unknown product type" };
}

std::ostream& operator<<(std::ostream& os, const ProductType& type)
{
	switch (type)
	{
	case ProductType::PersonalHygiene:
		os << "PersonalHygiene";
		break;
	case ProductType::SmallAppliences:
		os << "SmallAppliences";
		break;
	case ProductType::Clothing:
		os << "Clothing";
		break;
	}
	return os;
}
