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
	// отсебятина
	friend ostream& operator << (ostream& s, Time& queue);
};

queue_base::queue_base() {
	a = nullptr; //  обнуляем указатель
	b = nullptr; //  обнуляем указатель 
	k = 0; // k = кол-во объектов в очереди
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
	elem* temp = new elem; // Выделяем память для объекта структуры elem.
	if (k == 0) { // если в очереди 0 элементов 
		temp->Val = valuev; // то присваиваем в поле Val переменной temp значение, введенное с клавиатуры
		temp->Prev = nullptr; // в указатель на предыдущий присваиваем значение нулевого указателя, т.к. элемент всего 1
		a = temp; // переменные а и б отвечают за первый и последний элемент в очереди, т.к. в очереди 1 элемент, то он является одновременно первым и последним
		b = temp; // temp - "временный" объект структуры присваюващий значения полям базового класса
	}
	else {
		temp->Val = valuev; // т.к. это не первый элемент в очереди, в поле val присваиваем значение введенное с клавиатуры
		temp->Prev = b; // в поле prev присваиваем значение указателя на предыдущий элемент
		b = temp; // значение и адрес "временной" переменной присваим объекту б, т.е. указатель объекта б теперь имеет указатель на передстоящий элемент в очереди
	}
	k++; // увеличиваем счетчик элементов очереди
}

inline queue_base queue_base::sum(queue_base& obj1, queue_base& obj2)
{
	elem* temp = obj1.get_b();
	queue_base j;
	if (obj1.get_k() != obj2.get_k()) // доработать 
		return j;
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
	if (obj1.get_k() != obj2.get_k()) // доработать 
		return j;
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
		cout << "Элементы отсутствуют" << endl;
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
		cout << "Очередь пуста!" << endl; // защита, если элементов в очереди нет
		return *this;
	}
	if (this->get_k() == 1) {
		delete this->a;
		this->a = nullptr; // если элемент в очереди всего один, нет смысла идти с конца до первого, удаляем сразу, и обнуляем указатели
		this->b = nullptr;
	}
	else {
		elem* temp = this->get_b(); // "временному" объекту структуры присваиваются значения последнего элемента в очереди (т.е. значения полей val и *prev )
		while (temp->Prev != this->a) { // справа налево продвигаемся по элементам очереди, пока не дойдем до второго элемента (слева) очереди
			temp = temp->Prev;
		}
		delete this->a; // когда дошли, удаляем первый элемент, очищаем память
		this->a = temp; // теперь a - это ранее второй элемент очереди становится первым, и т.д.
		this->a->Prev = nullptr; // указатель бывшего второго элемента очищаем(удаляем), т.к. элемент на которой он указывал, был удален
	}
	this->k--; // уменьшаем счетчик элементов на 1
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
	elem* temp = new elem; // Выделяем память для объекта структуры elem.
	if (left.k == 0) { // если в очереди 0 элементов 
		temp->Val = valuev; // то присваиваем в поле Val переменной temp значение, введенное с клавиатуры
		temp->Prev = nullptr; // в указатель на предыдущий присваиваем значение нулевого указателя, т.к. элемент всего 1
		left.a = temp; // переменные а и б отвечают за первый и последний элемент в очереди, т.к. в очереди 1 элемент, то он является одновременно первым и последним
		left.b = temp; // temp - "временный" объект структуры присваюващий значения полям базового класса
	}
	else {
		temp->Val = valuev; // т.к. это не первый элемент в очереди, в поле val присваиваем значение введенное с клавиатуры
		temp->Prev = left.b; // в поле prev присваиваем значение указателя на предыдущий элемент
		left.b = temp; // значение и адрес "временной" переменной присваим объекту б, т.е. указатель объекта б теперь имеет указатель на передстоящий элемент в очереди
	}
	left.k++; // увеличиваем счетчик элементов очереди
	return left;
}

//ostream& operator << (ostream& s, queue_base& queue) {
//	if (!queue.get_k()) {
//		cout << endl << "Очередь пуста!";
//		return s;
//	}
//
//}
