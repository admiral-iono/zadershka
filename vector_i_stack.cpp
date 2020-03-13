#include <iostream>
#include <string>

using namespace std;



double min (double f, double s)
{
	if (f < s) {
		return f;
	}
	return s;
}

double maxf(double f, double s)
{
	if (f > s) {
		return f;
	}
	return s;
}

//Реализация вектора

class tipavector
{
private:
	int m_size;
	int m_capacity;
	double* m_data;
public:
	tipavector()
	{
		m_size = 0;
		m_capacity = 0;
		m_data = nullptr;
	}
	tipavector(int n)
	{
		m_size = n;
		m_data = new double[n];
	}
	~tipavector()
	{
		if (m_data)
			delete[] m_data;
	}

	int size()
	{
		return m_size;
	}

	double& operator[] (int i)
	{
		return m_data[i];
	}

	void resize(int newsize)
	{
		if (newsize <= m_capacity)
		{
			m_size = newsize;
			return;
		}

		int newcapacity = maxf(newsize, m_size * 2);
		double* new_data = new double[newcapacity];
		int i;
		for (i = 0; i < min(m_size, newsize); ++i) {
			new_data[i] = m_data[i];
		}
		for (; i < newsize; ++i) {
			new_data[i] = double();
		}
		delete[] m_data;
		m_data = new_data;
		m_size = newsize;
		m_capacity = newcapacity;
	}

	void push_back(double val)
	{
		resize(m_size + 1);
		m_data[m_size - 1] = val;
	}

	void insert(int pos, double val)
	{
		resize(m_size + 1);
		for (int i = m_size - 1; i > pos; --i)
		{
			m_data[i] = m_data[i - 1];
		}
		m_data[pos] = val;
	}

};


double max(tipavector a)
{
	int tmp = a[0];
	for (int i = 1; i < a.size(); ++i)
	{
		if (a[i] > tmp) {
			tmp = a[i];
		}
	}
	return tmp;
}


void sort (tipavector a)
{
	for (int i = a.size(); i > 0; --i) {
		for (int j = 1; j < i; ++j) {
			if (a[j - 1] > a[j]) {
				swap(a[j - 1], a[j]);
			}
		}
	}
}

//реализация стэка

class Stack : public tipavector
{
public:
	void push( double val)
	{
		this->push_back(val);
	}

	double top()
	{
		return (*this)[this->size() - 1];
	}

	void pop()
	{
		this->resize(this->size() - 1);
	}

	bool empty()
	{
		return this->size() == 0;
	}

};

//Задача про скобки

int main()
{

}