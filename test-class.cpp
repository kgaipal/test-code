#include <typeinfo>
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>

class A_static
{
public:
	void printI()
	{
		std::cout << "A::" << s_i << "\n";
	}

	static void setI(int i)
	{
		s_i = i;
	}

private:
	static int s_i;
};

int A_static::s_i = 0;

class A
{
public:
	A(int i)
		:m_i(i)
	{
		std::cout << "A(" << m_i << ")\n";
	}

	virtual ~A()
	{
		std::cout << "~A(" << m_i << ")\n";
	}

	virtual void abstract() = 0;

protected:
	int m_i;
};

class B : public A
{
public:
	B(int i, int j)
		: A(i)
		, m_j(j)
	{
		std::cout << "B(" << A::m_i << "," << m_j << ")\n";
	}

	virtual ~B()
	{
		std::cout << "~B(" << A::m_i << "," << m_j << ")\n";
	}

	void abstract()
	{
		std::cout << "B::abstract(" << A::m_i << "," << m_j << ")\n";
	}

private:
	int m_j;
};

class C : public A
{
public:
	C(int i, int j)
		: A(i)
		, m_j(j)
	{
		std::cout << "C(" << A::m_i << "," << m_j << ")\n";
	}

	virtual ~C()
	{
		std::cout << "~C(" << A::m_i << "," << m_j << ")\n";
	}

	void abstract()
	{
		std::cout << "C::abstract(" << A::m_i << "," << m_j << ")\n";
	}

private:
	int m_j;
};

int main()
{
	{
		A_static::setI(7);
	}

	A_static a;
	a.printI();
	A_static::setI(99);
	a.printI();

	// std::unordered_map< int, std::unique_ptr<A> > um;

	// um[0] = std::unique_ptr<A>(new B(2,99));
	// um[1].reset(new C(-2,-99));

	// std::vector< std::unique_ptr<A> > vt;

	// vt.push_back(std::unique_ptr<A>(new B(2,99)));
	// vt.push_back(std::unique_ptr<A>(new C(-2,-99)));

	// std::unique_ptr<A> x(new C(-1,-100));
	// vt.push_back(std::move(x));

	// for (size_t i = 0; i < vt.size(); i++) {

	// 	A* a = vt[i].get();
	// 	std::cout << "-\n";
	// 	if (typeid(*a) == typeid(B)) {
	// 		vt[i]->abstract();
	// 	} else if (typeid(*a) == typeid(C)) {
	// 		vt[i]->abstract();
	// 	}
	// }

	return 0;
}