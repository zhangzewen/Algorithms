#include <iostream>
#include <string>

using namespace std;
using std::cin;
using std::cout;

class Item_base{
public:
	Item_base(const string &book = "",
						double sales_price = 0.0):
							isbn(book), price(sales_price) {}
	string book()const{return isbn;}
	virtual double net_price(size_t n) const{ cout << endl << "Parent" << endl; return n * price;}
	virtual ~Item_base(){}
private:
	string isbn;
protected:
	double price;
};


class Bulk_item : public Item_base {
public:

	Bulk_item(const string &book = "", 
						double sales_price = 0.0,
							size_t qty = 0, double disc_rate = 0.0):
									Item_base(book, sales_price), max_qty(qty), discount(disc_rate) {} 
	double net_price(size_t cnt) const
	{
		cout << endl<< "Child" <<endl;
		if (cnt > max_qty)
			return max_qty  * ((1 - discount) *price)  + (cnt - max_qty) * price;
		else 
			return cnt * price;
	}
private:
	size_t max_qty;
	double discount;
	
};


void print_total(ostream &os, const Item_base &item, size_t n)
{
	os << "ISBN: " << item.book()
		 << "\tnumber sold: " << n <<"\t total price: "
		 <<item.net_price(n) << endl;
}

int main(int argc,  char *argv[])
{
	Item_base base("Funck", 88.5);
	Bulk_item derived("Funck", 88.5, 30, 0.8);
	
	print_total(cout, base, 10);
	print_total(cout, derived, 50);	
}
