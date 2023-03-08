#include"Manager.h"



manager::manager()
{
	pin = 9999;
}
int manager::get_pin()
{
	return pin;
}
void manager::refill_items(string name_)
{
	if (this->search_items(name_) == 1)
	{
		this->edit(5, name_);
		cout << "Changed." << endl;
	}
}
