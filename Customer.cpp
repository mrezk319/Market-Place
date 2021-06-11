#include "Customer.h"
Customer::Customer() {

}

Customer::Customer(string address, int phonenumber) {
	this->address = address;
	this->phonenumber = phonenumber;
}

void Customer::searchbyname(vector<Product>& products,string name) {
	bool found = false;

	for (int i = 0; i < products.size(); i++) {
		if (products[i].getnamepro()==name) {
			products[i].view();
			cout <<"    ******************   "<< endl;
			found = true;
		}
	}
	if (found == false) {
		cout << " NO match found ";
	}


}
void Customer::searchbycategory(vector<Product>& products,string category) {
	bool found = false;

	for (int i = 0; i < products.size(); i++) {
		if (products[i].getCategory() == category) {
			products[i].view();
			cout <<"    ******************   "<< endl;
			found = true;
		}
	}
	if (found == false) {
		cout << " NO match found \n";
	}
}

void Customer::getinfo(int ID,string name,string address,int phonenumber) {
	cout << "Enter your ID :";
	cin >> ID;
	cout << "Enter your Name";
	cin >> name;
	cout << "Enter your Address";
	cin >> address;
	cout << "Enter your Phone number :";
	cin >> phonenumber;
}

void Customer::Addtocart(vector<Product>& products, int productid)
{
	
	int counter = 0;
	for (int i = 0; i < products.size(); i++)
	{
		if (products[i].getProductID() == productid) {
			carts.push_back(products[i]);
			counter++;
		}
	}
	if (counter == 0) cout << "This product is not here !" << endl;

}

void Customer::confirmbyuing()
{
	int total_price = 0;
	for (int i = 0; i < carts.size(); i++) {
		carts[i].viewCart();
		cout <<"-----------------------"<<endl;
		total_price += carts[i].getPrice();
	}

	cout << "Total Price : " << total_price << endl;
	cout << "    ------------------     " << endl;
}
