#include "queuetp.h"
#include <iostream>

void QUEUE::testQueueTp()
{
	const int SIZE = 15;
	Worker ws[SIZE] = { {"ZhangSan",1001},{"Lisi",1002},
		{"WangEr",1003},{"Mike",1004},{"Kangkang",1005 } };
	QueueTp<Worker*> q;
	Worker* temp;
	q.print();
	for (int i = 0; i < SIZE; i++)
	{
		q.enqueue(&ws[i]);
	}
	q.print();
	for (int i = 0; i < SIZE; i++)
	{
		q.dequeue(temp);
		temp->show();
	}
	q.print();
}
