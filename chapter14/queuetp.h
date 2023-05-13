#ifndef QUEUE_TP_H__
#define QUEUE_TP_H__
#include <string>
#include <stdexcept>
#include <iostream>
namespace QUEUE
{
	using namespace std;
	class Worker
	{
	private:
		string fullname;
		long id;
	protected:
		virtual void data() const {}
		virtual void get() const {}
	public:
		Worker() :fullname("none"), id(0) {}
		Worker(const string& s, long n) :fullname(s), id(n) {}
		virtual ~Worker() {}
		virtual void set(const string& fn, long n)
		{
			fullname = fn;
			id = n;
		}
		virtual void show() const
		{
			std::cout << fullname << ", " << id<<"\n";
		}
	};

	template<typename T>
	class QueueTp
	{
	private:
		struct Node
		{
			T item;
			struct Node* next;
		};
		enum { QSIZE = 10 };
		Node* front;
		Node* rear;
		int items;//current number of items
		const int qsize; //maxinum number of items
		QueueTp(const QueueTp& q) :qsize(0), items(0), front(nullptr), rear(nullptr) {}
		QueueTp& operator=(const QueueTp& q) { return *this; }
	public:
		//QueueTp() :qsize(QSIZE), items(0) {}
		explicit QueueTp(int qs = QSIZE) :qsize(qs), items(0) {}
		virtual ~QueueTp();
		bool isEmpty() const { return items == 0; }
		bool isFull() const { return items == qsize; }
		int count() const { return items; }
		bool enqueue(const T& item);
		bool dequeue(T& item);
		T* head() const;
		void print() const;
	};
	template<>
	class QueueTp<Worker*>
	{
	private:
		struct Node
		{
			Worker* item;
			struct Node* next;
		};
		enum { QSIZE = 10 };
		Node* front;
		Node* rear;
		int items;//current number of items
		const int qsize; //maxinum number of items
		QueueTp(const QueueTp& q) :qsize(0), items(0), front(nullptr), rear(nullptr) {}
		QueueTp& operator=(const QueueTp& q) { return *this; }
	public:
		//QueueTp() :qsize(QSIZE), items(0)
		//{
		//	front = new Node;
		//	front->item = nullptr;
		//	front->next = nullptr;
		//	rear = front;
		//}
		explicit QueueTp(int qs = QSIZE) :qsize(qs), items(0)
		{
			if (qs < 0) throw invalid_argument("Invalid argument.");
			front = new Node;
			front->item = nullptr;
			front->next = nullptr;
			rear = front;
		}
		virtual ~QueueTp()
		{
			Node* temp;
			if (front != nullptr)
			{
				temp = front;
				front = front->next;
				delete temp;
			}
		}
		bool isEmpty() const { return items == 0; }
		bool isFull() const { return items == qsize; }
		int count() const { return items; }
		bool enqueue(Worker* const& item)
		{
			if (isFull()) return false;
			else
			{
				Node* temp = new Node;
				temp->item = item;
				temp->next = nullptr;
				rear->next = temp;
				rear = temp;
				items++;
			}
			return true;
		}
		bool dequeue(Worker*& item)
		{
			if (isEmpty()) return false;
			else
			{
				item = front->next->item;
				Node* temp;
				temp = front->next->next;
				front->next = temp;
				items--;
				if (items == 0)
					rear = front;
			}
			return true;
		}
		Worker** head() const
		{
			return &front->next->item;
		}
		void print() const
		{
			Node* temp = front;
			while (temp != rear)
			{
				temp->next->item->show();
				temp = temp->next;
			}
		}
	};

	void testQueueTp();
}

#endif