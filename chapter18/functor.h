#ifndef FUNCTOR_H__
#define FUNCTOR_H__

template <typename T>
class Toobig {
private:
	T cutoff;
public:
	Toobig(const T& t) :cutoff(t) {}
};

void testLamada();




#endif