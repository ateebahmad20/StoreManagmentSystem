#include"Staff.h"
#define SIZE 1000
static int  a = 0;

staff::staff()
{
	name = rank = "";//initiallizing string data members 
	salary = age = id = 0;//initiallizing integer data members 
}
void staff::add_staff()
{
	cout << "Enter Name Of Staff Member: "; cin >> this->name;//Inputs name in array
	cout << "Enter Rank Of Staff Member: "; cin >> this->rank;//Inputs rank in array
	cout << "Enter age of Staff Member: "; cin >> this->age;//Inputs Age in array
	cout << "Enter Salary of Staff Member: "; cin >> this->salary;//Inputs Salary in array
	cout << "Enter Id of Staff Member: "; cin >> this->id;//Inputs Id in array
}
void staff::edit_staff(string edit_name, int option)
{

	if (edit_name == this->get_name())
	{
		switch (option)
		{
		case 1:cout << "Change The Name: "; cin >> this->name; break;
		case 2:cout << "Change The Rank: "; cin >> this->rank; break;
		case 3:cout << "Change The Salary: "; cin >> this->salary; break;
		case 4:cout << "Change The Age: "; cin >> this->age; break;
		case 5:cout << "Change The ID: "; cin >> this->id; break;
		}
	}
	//		else { cout << "The Item Was Not Found." << endl; }
}
void staff::remove_staff(string remove_name)
{
	if (remove_name == this->get_name())
	{
		name = rank = "";
		salary = age = id = 0;
	}
	
}
void staff::display_staff()
{
	cout << "Member " << ++a << endl;
	cout << "Name: " << this->get_name() << "		Rank: " << this->get_rank() <<
		"	Salary: " << this->get_salary() << "	Age: " << this->get_age() << "	Id: " << this->get_id() << endl;
}
void staff::set_name(string na)
{
	name = na;
}
void staff::set_rank(string ra)
{
	rank = ra;
}
void staff::set_salary(int sa)
{
	salary = sa;
}
void staff::set_age(int ag)
{
	age = ag;
}
void staff::set_id(int i)
{
	id = i;
}
int staff::search_staff(string search_name)
{
	int flag = 0;
	if (this->get_name() == search_name)
	{
		this->display_staff();
		flag = 1;
	}
	return flag;
}
string staff::get_name()const
{
	return name;
}
string staff::get_rank()const
{
	return rank;
}
int staff::get_salary()const
{
	return salary;
}
int staff::get_age()const
{
	return age;
}
int staff::get_id()const
{
	return id;
}
staff::~staff()
{
	cout << "End of Staff Class." << endl;
}
