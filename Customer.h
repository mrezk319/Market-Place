#pragma once
#include "Person.h"
#include "Product.h"
#include "vector"
#include <String>

class Customer :public Person
{
	string address;
	int phonenumber;
	vector<Product> carts;
public:
	Customer();
	Customer(string,int);
	void searchbyname(vector<Product>&,string name);
	void searchbycategory(vector<Product>&,string category);
	void getinfo(int ID, string name, string address, int phonenum);
	void Addtocart(vector<Product>& , int productid);
	void confirmbyuing();
};

