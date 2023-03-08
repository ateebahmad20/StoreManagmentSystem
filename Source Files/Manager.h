#include"Staff.h"
#include"Stocks.h"


class manager :public staff, public stock_ //Inheriting properties from base classes
{
private:
	int pin;
public:
	manager();

	void refill_items(string name_);
	int get_pin();
};
