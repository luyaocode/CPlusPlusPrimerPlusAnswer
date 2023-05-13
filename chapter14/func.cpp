#include "func.h"

std::ostream& operator<<(std::ostream& os, const Work& w)
{
	os << w.fullname << ", " << w.id << "\n";
	// TODO: �ڴ˴����� return ���
	return os;
}

void testStackTemplate()
{
	Stack<Work*> sw;
	Work work[4] = { {"A",0},{"B",1},{"C",2},{"D",3} };
	for (int i = 0; i < 4; i++)
	{
		sw.push(&work[i]);
	}
	sw.show();
}
