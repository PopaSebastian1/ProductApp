#pragma once
#include <string>
#include<iostream>
#include "ProductType.h"
class Product
{
private:
	uint16_t m_id, m_tva;
	std::string m_name, m_expirationdate;
	float m_price;
	ProductType m_type;
public:
	Product(uint16_t id, std::string name,float price, uint16_t tva, std::string expirationdate);
	Product(uint16_t id, std::string name, float price, uint16_t tva, ProductType type);
	uint16_t Getid() const;
	std::string Getname() const;
	float Getprice() const;
	uint16_t Gettva() const;
	std::string Getexpirationdate() const;
	ProductType Gettype() const;
	friend std::ostream& operator <<(std::ostream& os, const Product& p);
	friend bool operator <(const Product& p1, const Product& p2);
	friend bool ComparePrice(const Product& p1, const Product& p2);

	
	/*Product(const Product& produs);
	Product& operator =(const Product& produs);
	~Product();*/



};
bool ComparePrice(const Product& p1, const Product& p2);

