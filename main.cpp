#include "Person.h"
#include <iostream>
#include "Product.h"
#include "Customer.h"
#include <string>
#include <vector>
#include "Seller.h"

using namespace std;

int Person::userNumber = 0;
int Product::productNumber = 0;


int main()
{
	int choise = 0;
	vector<Product>products = vector<Product>();
	vector<Product>cart = vector<Product>();
	vector<vector<Product>>categories = vector<vector<Product>>();
	string name, category;
	int productid;


	Product pro1 = Product(1, 10, "t.shirt", "clothes");
	Product pro2 = Product(2, 30, "tomato", "food");
	Product pro3 = Product(2, 30, "Eggs", "food");
	Product pro4 = Product(2, 30, "Lan4on", "food");
	Product pro5 = Product(3, 50, "cat", "pets");
	Product pro6 = Product(3, 50, "Dogs", "pets");
	Product pro7 = Product(4, 1500, "mobile", "electronics");


	products.push_back(pro1);
	products.push_back(pro2);
	products.push_back(pro3);
	products.push_back(pro4);
	products.push_back(pro5);
	products.push_back(pro6);
	products.push_back(pro7);

	string answer;
	string email;
	vector <Person> users;
	while (true) {
		cout << "Do you want to...?\n1-sell\n2-buy" << endl;
		cin >> answer;
		if (answer == "sell" || answer == "Sell" || answer == "1")
		{
			int currentID;
			cout << "Enter your name : ";
			cin >> name;
			cout << endl;
			cout << "Enter your email : ";
			cin >> email;
			cout << endl;

			Seller seller;
			bool found = false;
			for (int i = 0; i < users.size(); i++)
			{
				if (users[i].getEmail() == email)
				{
					cout << "Welcome again " << users[i].getName() << endl;
					found = true;
					currentID = users[i].getID();
					break;
				}
			}

			if (!found)
			{
				Person person = Person(name, email);
				currentID = Person::userNumber;
				users.push_back(person);
				cout << "Welcome " << users[currentID - 1].getName() << endl;
			}
			while (true) {
				int choise;

				cout << "Which thing do u wanna do(please enter a number)?\n";
				cout << "1-Add product.\n";
				cout << "2-Logout.\n";
				cout << "3-Exit the program.\n";
				cin >> choise;

				if (choise == 1)
				{
					seller.addProduct(currentID, products);
				}
				else if (choise == 2) {
					break;
				}
				else if (choise == 3) {
					return 0;
				}
				else {
					cout << "Please Enter a number from the menu.\n";
				}
			}
		}
		else if (answer == "buy" || answer == "Buy" || answer == "2")
		{
			string address;
			int phone;
			cout << "Enter your address : " << endl;
			cin >> address;
			cout << "Enter your phone : " << endl;
			cin >> phone;
			Customer cust = Customer(address, phone);
			choise = 6;
			while (choise != 0) {
				cout << "do you want to view products (press 1)\n";
				cout << "do you want to search by name (press 2)\n";
				cout << "do you want to search by category (press 3)\n";
				cout << "do you want to add to cart  (press 4)\n";
				cout << "do you want to confirm buying (press 5)\n";
				cout << "press 0 to EXIT\n";
				cin >> choise;
				if (choise == 1) {
					for (int i = 0; i < products.size(); i++) {
						products[i].view();
						cout << "   *************************    \n\n";
					}
				}
				else if (choise == 2) {
					cin >> name;
					cust.searchbyname(products, name);
				}

				else if (choise == 3) {
					cin >> category;
					cust.searchbycategory(products, category);
				}
				else if (choise == 4) {
					cout << "Enter Product ID or enter -1 to out\n";
					productid = 100;
					while (productid != -1) {
						cin >> productid;
						cust.Addtocart(products, productid);
					}
				}
				else if (choise == 5) {
					cust.confirmbyuing();
				}

			}
		}
	}

	return 0;
}