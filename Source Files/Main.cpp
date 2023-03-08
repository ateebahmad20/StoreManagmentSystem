#include"Manager.h"
#include<fstream>
#include<stdlib.h>
#define SIZE 1000
//----------------------------------------------------------------------

void edit();
void options();
void staff_options();
void edit_staff();
void go_back();
static int  a = 0;

//----------------------------------------------------------------------

int main()
{
	int type = 0;
	int count = 1;
	int count1 = 1;
	int pin = 0;
	int x = 0;
	int type_access = 0;
	int opt = 0;
	int option = 0;
	int n = 0;
	int  option_edit;
	int continue_ = 0;
	int counter = 1;
	int* arr = 0;
	int sum = 0;
	string file_data = "";
	string remove_name = "";
	string search_name = "";
	string refill_name = "";
	string edit_name = "";
	manager* stocks = new manager[SIZE];//dynamic memory allocation 
	manager* staffs = new manager[SIZE];//dynamic memory allocation 

	char* file = new char[1000];
	char* file1 = new char[1000];
	system("Color 47");

	ifstream stock("stock.txt");// file opens to read data
	for (int i = 0; i < SIZE; i++)// loop will help in read data line by line and will automatically placed in array
	{
		counter = 1;// reset counter
		for (int q = 0; q < 7; q++)
		{
			stock.getline(file, 50);// 50 character read from file to array
			file_data = file;
			if (!stock.eof()) // loop will run until end of line reached 
			{
				switch (counter) // each case calls setter function to set appropriate data to file 
				{
				case 1:
					stocks[i].set_productname(file_data); break;
				case 2:
					stocks[i].set_category(file_data); break;
				case 3:
					stocks[i].set_expiry(file_data); break;
				case 4:
					stocks[i].set_price(atoi(file)); break;
				case 5:
					stocks[i].set_quantity(atoi(file)); break;
				case 6:
					stocks[i].set_barcode(atoi(file)); break;
				case 7:
					stocks[i].set_weight(atoi(file)); break;
				}
				counter++;
				count++; // used to find out how many lines are read
			}
		}
	}
	stock.close();
	//cout << count << endl;
	count = count / 7; // used to tell that how many objects are read and from array has to start
	//cout << count << endl;

	//------------------------------------------------------------------------------------------------------------------

	ifstream staff("staff.txt");// file opens to read data
	for (int i = 0; i < SIZE; i++)// loop will help in read data line by line and will automatically placed in array
	{
		counter = 1;// reset counter
		for (int q = 0; q < 5; q++)
		{
			staff.getline(file1, 50);// 50 character read from file to array
			file_data = file1;
			if (!staff.eof()) // loop will run until end of line reached 
			{
				switch (counter) // each case calls setter function to set appropriate data to file 
				{
				case 1:
					staffs[i].set_name(file_data); break;
				case 2:
					staffs[i].set_rank(file_data); break;
				case 3:
					staffs[i].set_salary(atoi(file1)); break;
				case 4:
					staffs[i].set_age(atoi(file1)); break;
				case 5:
					staffs[i].set_id(atoi(file1)); break;
				}
				counter++;
				count1++; // used to find out how many lines are read
			}
		}
	}
	staff.close();
	//cout << count1 << endl;
	count1 = count1 / 5; // used to tell that how many objects are read and from array has to start
	//cout << count1 << endl;
	//------------------------------------------------------------------------------------------------------------------
	cout << "\n\n\n\n\n\n\t\t\t  STORE MANAGEMENT SYSTEM\n" << endl;
	cout << "=========================================================================";
	cout << "\n\n\t\t\t\t1-Manager\n\n\t\t\t\t2-Customer\n\n\t\t\t\t3-Exit" << endl;
	cout << "\n=========================================================================";
	cout << "\n\nEnter Your Choice: "; cin >> n;

	switch (n)//Case 1 is Manager Program
	{
	case 1:
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t" << endl;
		cout << "=========================================================================";
		cout << "\n\n\t\t\tPassword Protected"; //Manager Pin Entry
		cout << "\n\n=========================================================================";
		cout << "\nEnter Pin: "; cin >> pin;

		system("cls");
		while (pin != stocks[0].get_pin())//Re-Entry of Pin If does not work
		{
			cout << "Re-Enter Pin: "; cin >> pin;
		}

		for (type_access = 0;type_access != 3;)
		{
			cout << "\n\n\n\n\n\n\t\t\t" << endl;
			cout << "=========================================================================";
			cout << "\n\t\t\t     Manager's Menu";
			cout << "\n\n\t\t\t\t1-Stocks\n\n\t\t\t\t2-Staff\n\n\t\t\t\t3-Exit" << endl;
			cout << "\n=========================================================================";
			cout << "\n\nEnter Your Choice: "; cin >> type_access;

			switch (type_access)
			{
			case 1:// access stocks 
				system("cls");

				for (option = 0; option != 7;)
				{
					options();

					cout << "\nEnter Task Number to Perform: "; cin >> option; cout << endl;//Entry Option To Be Called
					switch (option)
					{
						cout << count << endl;

					case 1: system("cls"); stocks[count].add(); cout << endl; count++; go_back(); continue;//Calls Member Function to Add Data

					case 2: system("cls");cout << "Enter Name of Item To Be Edited: "; cin >> edit_name;//Ask Name of item to be edited
						edit(); //calls function to displays options
						cout << endl << "Please Enter Number Of The Funtion To Edit: "; cin >> option_edit;//enter option number to be called
						for (int c = 0; stocks[c].get_product_name() != ""; c++)//the loop runs until the end of array reached
							stocks[c].edit(option_edit, edit_name);//calls edit member funcion to edit the specifit item
						go_back();
						continue;

					case 3:system("cls");cout << "Enter Name of Item To Be Removed: "; cin >> remove_name;//ask for item to be removed
						for (int c = 0; stocks[c].get_product_name() != ""; c++)//the loop runs until the end of array reached
							stocks[c].remove(remove_name);//member function is used to remove a the data of specific item
						go_back();
						continue;

					case 4:system("cls");cout << endl;
						for (int c = 0; stocks[c].get_product_name() != ""; c++)//this case displays all items in the array
						{
							stocks[c].display_items();
						}
						go_back();
						continue;

					case 5:system("cls");cout << "Enter Name of Item To Be Searched: "; cin >> search_name;//ask for item name to be searched 
						cout << endl;
						for (int c = 0; stocks[c].get_product_name() != ""; c++)
						{
							if (stocks[c].search_items(search_name))//calls member function to search the item
								cout << "Item Found." << endl;

						}
						go_back();
						continue;

					case 6:system("cls");cout << "Enter Name of Item To Be Refilled: "; cin >> refill_name; //ask for item name to be refilled 
						for (int c = 0; stocks[c].get_product_name() != ""; c++)
						{
							stocks[c].refill_items(refill_name);//calls member function for refilling items
						}
						go_back();
						continue;

					case 7: go_back(); continue;// the program terminates of this option used
					}
				}
				break;

			case 2: // access staff
				system("cls");
				for (opt = 0; opt != 6;)
				{
					staff_options();
					cout << "\nWhich Option Do You Want to choose: "; cin >> opt;
					switch (opt)
					{
					case 1: system("cls");
						cout << count1 << endl;
						staffs[count1].add_staff();// calls to add data to array
						count1++;
						go_back();
						continue;

					case 2: system("cls");
						cout << "Enter Name of Item To Be Edited: "; cin >> edit_name;//Ask Name of item to be edited
						edit_staff(); //calls function to displays options
						int option;
						cout << "Enter Option To Edit specific Item: "; cin >> option;
						for (int c = 0; staffs[c].get_name() != ""; c++)//the loop runs until the end of array reached
							staffs[c].edit_staff(edit_name, option);//calls edit member funcion to edit the specifit item
						go_back();
						continue;

					case 3: system("cls");
						cout << "Enter Name of Item To Be Removed: "; cin >> remove_name;//ask for item to be removed
						for (int c = 0; staffs[c].get_name() != ""; c++)//the loop runs until the end of array reached
							staffs[c].remove_staff(remove_name);//member function is used to remove a the data of specific staff
						go_back();
						continue;

					case 4:system("cls");cout << endl;
						a = 0;
						for (int c = 0; staffs[c].get_name() != ""; c++)//this case displays all items in the array
						{
							staffs[c].display_staff();
						}
						go_back();
						continue;

					case 5:system("cls");
						cout << "Enter Name of Item To Be Searched: "; cin >> search_name;//ask for item name to be searched 
						cout << endl;
						for (int c = 0; staffs[c].get_name() != ""; c++)
						{
							if (staffs[c].search_staff(search_name))//calls member function to search the item
								cout << "Item Found." << endl;

						}
						go_back();
						continue;

					case 6:
						go_back();
						continue;// the program terminates of this option used
					}

				}
				break;

			case 3: system("cls"); main();
			}
		}
		break;

	case 2: //Customer Menu
		system("cls");
		for (int i = 0;i != 3;)
		{
			cout << "\n\n\n\n\n\n\t\t\t\n";
			cout << "===========================================================\n\n";//Customer Program
			cout << "\t\t\tCustomer Menu" << endl << endl;
			cout << "\t\t\t1-Buy Items\n\n\t\t\t2-Calculate Bill\n\n\t\t\t3-Exit\n\n" << endl;
			cout << "===========================================================" << endl;
			cout << "\nEnter Your Choice: "; cin >> i;
			system("cls");

			switch (i)
			{
			case 1:
				cout << "\n\t\tAvaiable Items are:\n";
				cout << "\n======================================" << endl << endl;

				for (int c = 0; stocks[c].get_product_name() != ""; c++)//this case displays all items in the array
					cout << "Product " << c + 1 << ": " << stocks[c].get_product_name() << "\nPrice: " << stocks[c].get_price() << endl << endl;

				cout << "========================================";
				cout << "\n\nHow Many Items You Want to Buy: "; cin >> opt;
				arr = new int[opt]; //Dynamic Memory Allocation

				for (int i = 0;i < opt;i++)
				{
					cout << "Enter Product" << ": "; cin >> arr[i];
				}

				go_back();
				continue;

			case 2:
				for (int i = 0;i < opt;i++)
					sum += stocks[arr[i] - 1].get_price(); //finding total sum

				cout << "\n\t\tBill:\n";
				cout << "\n======================================" << endl << endl;
				cout << "Your Items: ";

				for (int i = 0;i < opt;i++)
					cout << stocks[arr[i] - 1].get_product_name() << ",";
				cout << "\n\nTotal Sum: " << sum << "Rps";
				cout << "\n========================================";
				go_back();
				continue;

			case 3: main();

			}
		}
		break;
	case 3: cout << "Thank You!"; break;
	}

	file_data = "";
	ofstream stok("stock.txt", ios::out);
	for (int i = 0; stocks[i].get_product_name() != ""; i++) // counter loop to 
	{
		counter = 1;
		for (int q = 0; q < 7; q++)
		{

			switch (counter)
			{
			case 1:
				stok << stocks[i].get_product_name() << endl; break;
			case 2:
				stok << stocks[i].get_category() << endl; break;
			case 3:
				stok << stocks[i].get_expiry() << endl; break;
			case 4:
				stok << stocks[i].get_price() << endl; break;
			case 5:
				stok << stocks[i].get_quantity() << endl; break;
			case 6:
				stok << stocks[i].get_barcode() << endl; break;
			case 7:
				stok << stocks[i].get_weight() << endl; break;
			}
			++counter;// counter get incremented to from 1 till 7 to output group 

		}
	}
	stok.close();


	//-----------------------------------------------------------------------------------------------

	file_data = "";
	ofstream stff("staff.txt", ios::out);
	for (int i = 0; staffs[i].get_name() != ""; i++) // counter loop to 
	{
		counter = 1;
		for (int q = 0; q < 5; q++)
		{

			switch (counter)
			{
			case 1:
				stff << staffs[i].get_name() << endl; break;
			case 2:
				stff << staffs[i].get_rank() << endl; break;
			case 3:
				stff << staffs[i].get_salary() << endl; break;
			case 4:
				stff << staffs[i].get_age() << endl; break;
			case 5:
				stff << staffs[i].get_id() << endl; break;
			}
			++counter;// counter get incremented to from 1 till 7 to output group 
		}

	}
	stff.close();
	return 0;
}

void edit()
{
	cout << "\n\tFor Changing Particular Item Enter Item Option:\n1.Product Name\n2.Category\n3.Expiry\n4.Price Of Item\n5.Quantity Of Item\n6.Weight Of Item\n7.Barcode" << endl;
}
void edit_staff()
{
	cout << "\n\tFor Changing Particular Item Enter Item Option:\n1.Member Name\n2.Rank\n3.Salary\n4.Age\n5.Id" << endl;

}
void options()
{
	cout << "\n\t\tOptions Available:" << endl;
	cout << "\n===================================================" << endl << endl;
	cout << "\n1.Add Item\n2.Edit Item\n3.Remove Item\n4.Display All Items\n5.Search Items\n6.Refill Items\n7.Exit" << endl;
	cout << "\n\n===================================================" << endl << endl;

}
void staff_options()
{
	cout << "\n\t\tOptions Available"<<endl;
	cout << "\n===================================================" << endl << endl;
	cout << "\n1.Add Staff Member \n2.Edit Staff Member\n3.Remove Staff Member\n4.Display All Staff Member\n5.Search Staff Member\n6.Exit" << endl;
	cout << "\n\n===================================================" << endl << endl;

}

void go_back()
{
	cout << "\n\nPress E to go back...";
	getchar();
	getchar();
	system("cls");
}
