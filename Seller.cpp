#include "Seller.h"
Seller::Seller()
{

}
void Seller::addProduct(int currentID, vector <Product>& products)
{
	string productName;
	string productCategory;
	int price;
	cout << "Enter the product name : ";
	cin >> productName;
	cout << "Enter the product category : ";
	cin >> productCategory;
	cout << "Enter the product price : ";
	cin >> price;
	Product product = Product(currentID, price, productName, productCategory);
	products.push_back(product);
	product.view();
}
