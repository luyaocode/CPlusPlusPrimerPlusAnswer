#ifndef CHAPTER14_H__
#define	CHAPTER14_H__

#include <iostream>
class Frabjous
{
private:
	char fab[20];
public:
	Frabjous(const char* s = "C++") { strcpy_s(fab, 20, s); };
	virtual void tell() { std::cout << fab; };
};
class Gloam
{
private:
	int glib;
	Frabjous fb;
public:
	Gloam(int g = 0, const char* s = "C++") :glib(g), fb(s) {}
	Gloam(int g, const Frabjous& f) :glib(g), fb(f) {}
	void tell() { std::cout << glib << "\n"; fb.tell(); };
};

class Work
{
private:
	std::string fullname;
	long id;
public:
	Work(std::string fn = "none", long i = 0) { fullname = fn, id = i; };
	virtual ~Work() {};
	friend std::ostream& operator<<(std::ostream& os, const Work& w);
};

template<typename T>
class Stack
{
private:
	enum { MAX = 10 };
	T items[MAX];
	int top;
public:
	Stack();
	bool isEmpty() const;
	bool isFull() const;
	bool push(const T& cs);
	bool pop(T& cs);
	void show() const;

};
template<typename T>
Stack<T>::Stack() {
	top = -1;
}

template<typename T>
bool Stack<T>::isEmpty() const
{
	return top == -1;
}

template<typename T>
bool Stack<T>::isFull() const
{
	return top == MAX - 1;
}

template<typename T>
bool Stack<T>::push(const T& cs)
{
	if (Stack<T>::isFull()) return false;
	else items[++top] = cs;
	return true;
}

template<typename T>
bool Stack<T>::pop(T& cs)
{
	if (Stack<T>::isEmpty()) return false;
	else  cs = items[top--];
	return true;
}
template<typename T>
void Stack<T>::show() const
{
	for (int i = 0; i <= top; i++)
	{
		std::cout << items[i] << "\n";
	}
	std::cout << "\n";
}

//In C++, you cannot explicitly specialize individual member functions of a class 
//template outside of the class definition. Instead, you need to explicitly 
//specialize the entire class template.
template<>
class Stack<Work*>
{
private:
	enum { MAX = 10 };
	Work* items[MAX];
	int top;
public:
	Stack()
	{
		for (int i = 0; i < MAX; i++)
		{
			items[i] = nullptr;
		}
		top = -1;
	}
	bool isEmpty() const { return top == -1; }
	bool isFull() const { return top == MAX - 1; }
	bool push(Work* const& cs)
	{
		if (isFull()) return false;
		else items[++top] = cs;
		return true;
	}
	bool pop(Work*& cs)
	{
		if (isEmpty()) return false;
		else  cs = items[top--];
		return true;
	}
	void show() const
	{
		for (int i = 0; i <= top; i++)
		{
			std::cout << *items[i];
		}
		std::cout << "\n";
	}
};

void testStackTemplate();







#endif // ! CHAPTER14_H__
