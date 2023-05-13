#include "emp.h"

void testEmployee()
{
	HighFink hf("Jack", "Ki", "Cook", "Jk", 10);
	hf.showAll();
	hf.setAll();
	hf.showAll();
	AbstrEmp* p = &hf;

	p->showAll();
}

