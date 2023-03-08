#include"Stocks.h"

void stock_::set_productname(string p)
{
	product_name = p;
}
void stock_::set_category(string c)
{
	category = c;
}
void stock_::set_expiry(string e)
{
	expiry = e;
}
void stock_::set_price(int p)
{
	price = p;
}
void stock_::set_quantity(int q)
{
	quantity = q;
}
void stock_::set_barcode(int b)
{
	barcode = b;
}
void stock_::set_weight(int w)
{
	weight = w;
}
void stock_::add()
{
	cout << "Add Product Name: "; cin >> product_name;
	cout << "Add Category of Item: "; cin >> category;
	cout << "Add Expiry: "; cin >> expiry;
	cout << "Add Price of Item: "; cin >> price;
	cout << "Add Quantity of Items: "; cin >> quantity;
	cout << "Add Weight of the Item: "; cin >> weight;
	cout << "Add Barcode of Product: "; cin >> barcode;
}
void stock_::edit(int option, string ename_)
{
	do {
		if (this->search_items(ename_) == 1)
		{
			switch (option)
			{
			case 1:	cout << "Change Product Name "; cin >> product_name; break;
			case 2:	cout << "Change Category of Item "; cin >> category; break;
			case 3:	cout << "Change Expiry "; cin >> expiry; break;
			case 4:	cout << "Change Price of Item "; cin >> price; break;
			case 5:	cout << "Change Quantity of Items "; cin >> quantity; break;
			case 6:	cout << "Change Weight of the Item "; cin >> weight; break;
			case 7:	cout << "Change Barcode of Product "; cin >> barcode; break;
			default:cout << "Entered Wrong Option...Please try Again "; cin >> option; continue;
			}
			cout << "Item Found...Record Deleted." << endl;
		}
		
	} while (option > 7);
}
void stock_::remove(string name)
{
	if (this->search_items(name) == 1)
	{
		cout << "Item Found...Record Deleted." << endl;
		product_name = "-";
		category = "-";
		expiry = "-";
		price = 0;
		quantity = 0;
		barcode = 0;
		weight = 0;
	}
	
}
int stock_::search_items(string name_)
{
	int flag = 0;
	if (name_ == this->get_product_name())
	{
		this->display_items();
		flag = 1;
	}
	else
		flag = 0;
	return flag;
}
void stock_::display_items()
{
	cout << "Product Name: " << this->get_product_name() << "	\nCategory: " << this->get_category() << "	\nExpiry: " << this->get_expiry() << "	\nPrice: " << this->get_price()
		<< "	\nBarcode: " << this->get_barcode() << "	\nQuantity: " << this->get_quantity() << "	\nWeight: " << this->get_weight() << endl << endl;
}
void stock_::alert_message()
{
	cout << "The Item Quantity is Less than 10% in Stock...Please Refill " << endl << endl;
}
string stock_::get_product_name()const
{
	return product_name;
}
string stock_::get_category()const
{
	return category;
}
string stock_::get_expiry()const
{
	return expiry;
}
int stock_::get_price()const
{
	return price;
}
int stock_::get_quantity()const
{
	return quantity;
}
int stock_::get_barcode()const
{
	return barcode;
}
int stock_::get_weight()const
{
	return weight;
}
