
#include <string>
#include <unordered_map>
#include <memory>
#include <functional>

#include "gtest/gtest.h"
#include "Timer.hpp"
#include "Ioc.hpp"
 
//test code
struct Base
{
	virtual void Func() {}
	virtual ~Base() {}
};

struct DerivedB : public Base
{
	DerivedB(int a, double b) :m_a(a), m_b(b)
	{
	}
	void Func()override
	{
		cout << m_a + m_b << endl;
	}
private:
	int m_a;
	double m_b;
};

struct DerivedC : public Base
{
};

struct A
{
	A(Base* ptr) :m_ptr(ptr)
	{
	}

	void Func()
	{
		m_ptr->Func();
	}

	~A()
	{
		if (m_ptr != nullptr)
		{
			delete m_ptr;
			m_ptr = nullptr;
		}
	}

private:
	Base* m_ptr;
};

void TestIoc()
{
	IocContainer ioc;
	ioc.RegisterType<A, DerivedC>("C");      //配置依赖关系
	auto c = ioc.ResolveShared<A>("C");

	ioc.RegisterType<A, DerivedB, int, double>("C");   //注册时要注意DerivedB的参数int和double
	auto b = ioc.ResolveShared<A>("C", 1, 2.0); //还要传入参数
	b->Func();
}

TEST(IocTest, AOPInvoke)
{
	TestIoc();
	//ASSERT_EQ(expected, actual);
}

 