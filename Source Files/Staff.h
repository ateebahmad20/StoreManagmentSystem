#include<iostream>
using namespace std;
#define SIZE 1000


class staff
{
private:
	string name;
	string rank;
	int salary;
	int age;
	int id;

public:
	staff();
	void add_staff();
	void edit_staff(string, int);
	int search_staff(string);
	void remove_staff(string);
	void display_staff();
	void set_name(string);
	void set_rank(string);
	void set_salary(int);
	void set_age(int);
	void set_id(int);
	string get_name()const;
	string get_rank()const;
	int get_salary()const;
	int get_age()const;
	int get_id()const;
	~staff();
};
