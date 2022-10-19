#include "Product.h"

Product::Product(uint16_t id, std::string name, float price, uint16_t tva, std::string expirationdate)
		: m_id{id}, m_name{name}, m_price{price},m_tva{tva}, m_expirationdate{expirationdate}
{	

}

Product::Product(uint16_t id, std::string name, float price, uint16_t tva, ProductType type)
	: m_id{ id }, m_name{ name }, m_price{ price }, m_tva{ tva }, m_type{type}
{
}

uint16_t Product::Getid() const
{
	return m_id;
}

std::string Product::Getname() const
{
	return m_name;
}

float Product::Getprice() const
{
	return m_price;
}

uint16_t Product::Gettva() const
{
	return m_tva;
}

std::string Product::Getexpirationdate() const
{
	return m_expirationdate;
}

ProductType Product::Gettype() const
{
	return m_type;
}
std::ostream& operator<<(std::ostream& os, const Product& p)
{
	os << p.m_id << " " << p.m_name << " " << p.Getprice() << " " << p.m_tva << " ";
	if (p.m_tva == 9)
	{
		os << p.m_expirationdate << std::endl;
	}
	else
	{
		os << p.m_type << std::endl;
	}
	return os;		
}

bool operator<(const Product& p1, const Product& p2)
{
	return p1.Getname() < p2.Getname();
}

bool ComparePrice(const Product& p1, const Product& p2)
{
	return p1.Getprice() < p2.Getprice();
}
