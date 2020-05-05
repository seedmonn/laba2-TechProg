#pragma once
#include <iostream>
using namespace std;

typedef struct elem {
	double Val;
	elem* Prev;
}elem;

class queue_base {
	elem* a;
	elem* b;
	int k;
public:

	queue_base();

	elem* get_a();
	elem* get_b();
	int get_k();

	void add(double);
	queue_base sum(queue_base& obj1, queue_base& obj2);
	queue_base divide(queue_base& obj1, double valuev);
	queue_base multiplication(queue_base& obj1, queue_base& obj2);
	void show();

	queue_base operator +(queue_base& b);
	queue_base operator -=(int);
	queue_base operator *(queue_base& b);
	queue_base operator /(double valuev);

	friend queue_base& operator+=(queue_base& left, double valuev);
	friend queue_base& operator-(queue_base& left, queue_base& right);
};
