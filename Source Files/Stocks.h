#include<iostream>
#define SIZE 1000
using namespace std;

class stock_
{
private:
	string product_name = "";
	string category = "";
	string expiry = "";
	int price = 0;
	int quantity = 0;
	int  barcode = 0;
	int weight = 0;
	void alert_message();

public:
	void set_productname(string);
	void set_category(string);
	void set_expiry(string);
	void set_price(int);
	void set_quantity(int);
	void set_barcode(int);
	void set_weight(int);
	void add();
	void edit(int, string);
	void remove(string);
	void display_items();
	int search_items(string name_);
	string get_product_name()const;
	string get_category()const;
	string get_expiry()const;
	int get_price()const;
	int get_quantity()const;
	int get_barcode()const;
	int get_weight()const;
};

