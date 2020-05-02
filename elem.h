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
	friend ostream& operator << (ostream& s, Time& queue);
};

queue_base::queue_base() {
	a = nullptr;
	b = nullptr;
	k = 0;
}

elem* queue_base::get_a() {
	return a;
}

elem* queue_base::get_b() {
	return b;
}

int queue_base::get_k() {
	return k;
}

inline void queue_base::add(double valuev)
{
	elem* temp = new elem;
	if (k == 0) {
		temp->Val = valuev;
		temp->Prev = nullptr;
		a = temp;
		b = temp;
	}
	else {
		temp->Val = valuev;
		temp->Prev = b;
		b = temp;
	}
	k++;
}

inline queue_base queue_base::sum(queue_base& obj1, queue_base& obj2)
{
	elem* temp = obj1.get_b();
	queue_base j;
	double* och_i = new double[obj1.get_k()];
	double* och_j = new double[obj2.get_k()];
	double* och_k = new double[obj1.get_k()];
	int l = obj1.get_k() - 1;
	for (int i = 0; i < obj1.get_k(); ++i) {
		och_i[l--] = temp->Val;
		temp = temp->Prev;
	}
	temp = obj2.get_b();
	l = obj2.get_k() - 1;
	for (int i = 0; i < obj2.get_k(); ++i) {
		och_j[l--] = temp->Val;
		temp = temp->Prev;
	}
	for (int i = 0; i < obj1.get_k(); i++) {
		och_k[i] = och_i[i] + och_j[i];
		j.add(och_k[i]);
	}
	delete[] och_i;
	delete[] och_j;
	delete[] och_k;
	och_i = nullptr;
	och_j = nullptr;
	och_k = nullptr;
	return j;
}

inline queue_base queue_base::divide(queue_base& obj, double valuev)
{
	queue_base j;
	elem* temp = obj.get_b();
	double* och_i = new double[obj.get_k()];
	double* och_j = new double[obj.get_k()];
	int l = obj.get_k() - 1;
	for (int i = 0; i < obj.get_k(); ++i) {
		och_i[l--] = temp->Val;
		temp = temp->Prev;
	}
	for (int i = 0; i < obj.get_k(); ++i) {
		och_j[i] = (och_i[i] / valuev);
		j.add(och_j[i]);
	}
	return j;
}

inline queue_base queue_base::multiplication(queue_base& obj1, queue_base& obj2)
{
	elem* temp = obj1.get_b();
	queue_base j;
	double* och_i = new double[obj1.get_k()];
	double* och_j = new double[obj2.get_k()];
	double* och_k = new double[obj1.get_k()];
	int l = obj1.get_k() - 1;
	for (int i = 0; i < obj1.get_k(); ++i) {
		och_i[l--] = temp->Val;
		temp = temp->Prev;
	}
	temp = obj2.get_b();
	l = obj2.get_k() - 1;
	for (int i = 0; i < obj2.get_k(); ++i) {
		och_j[l--] = temp->Val;
		temp = temp->Prev;
	}
	for (int i = 0; i < obj1.get_k(); i++)
		och_k[i] = och_i[i] * och_j[i];
	for (int i = 0; i < obj1.get_k(); i++)
		j.add(och_k[i]);
	delete[] och_i;
	delete[] och_j;
	delete[] och_k;
	och_i = nullptr;
	och_j = nullptr;
	och_k = nullptr;
	return j;
}

inline void queue_base::show()
{
	if (!get_k())
	{
		cout << "Ёлементы отсутствуют" << endl;
		return;
	}
	elem* temp = get_b();
	double* och = new double[get_k()];
	int l = get_k() - 1;
	for (int i = 0; i < get_k(); i++)
	{
		och[l--] = temp->Val;
		temp = temp->Prev;
	}
	for (int i = 0; i < get_k(); ++i) {
		cout << "[" << och[i] << "] ";
	}
	delete[] och;
}

inline queue_base queue_base::operator+(queue_base& b)
{
	return sum(*this, b);
}

inline queue_base queue_base::operator-=(int)
{
	if (!(this->get_k())) {
		cout << "ќчередь пуста!" << endl;
		return *this;
	}
	if (this->get_k() == 1) {
		delete this->a;
		this->a = nullptr;
		this->b = nullptr;
	}
	else {
		elem* temp = this->get_b();
		while (temp->Prev != this->a) {
			temp = temp->Prev;
		}
		delete this->a;
		this->a = temp;
		this->a->Prev = nullptr;
	}
	this->k--;
	return *this;
}

inline queue_base queue_base::operator*(queue_base& b)
{
	return multiplication(*this, b);
}

inline queue_base queue_base::operator/(double valuev)
{
	return (divide(*this, valuev));
}

queue_base& operator-(queue_base& left, queue_base& right)
{
	queue_base j;
	if (left.get_k() != right.get_k())
		return j;
	elem* temp = left.get_b();
	double* och_i = new double[left.get_k()];
	double* och_j = new double[right.get_k()];
	double* och_k = new double[left.get_k()];
	int l = left.get_k() - 1;
	for (int i = 0; i < left.get_k(); ++i) {
		och_i[l--] = temp->Val;
		temp = temp->Prev;
	}
	temp = right.get_b();
	l = right.get_k() - 1;
	for (int i = 0; i < right.get_k(); ++i) {
		och_j[l--] = temp->Val;
		temp = temp->Prev;
	}
	for (int i = 0; i < left.get_k(); i++)
		och_k[i] = och_i[i] - och_j[i];
	for (int i = 0; i < left.get_k(); i++)
		j.add(och_k[i]);
	delete[] och_i;
	delete[] och_j;
	delete[] och_k;
	och_i = nullptr;
	och_j = nullptr;
	och_k = nullptr;
	return j;
}

queue_base& operator+=(queue_base& left, double valuev) {
	elem* temp = new elem;
	if (left.k == 0) {
		temp->Val = valuev;
		temp->Prev = nullptr;
		left.a = temp;
		left.b = temp;
	}
	else {
		temp->Val = valuev;
		temp->Prev = left.b;
		left.b = temp;
	}
	left.k++;
	return left;
}
