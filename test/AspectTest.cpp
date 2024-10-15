
#include <string>
#include <unordered_map>
#include <memory>
#include <functional>

#include "gtest/gtest.h"
#include "Timer.hpp"
#include "Aspect.hpp"


/*TEST CODE*/
struct TimeElapsedAspect
{
	void Before(int i)
	{
		m_lastTime = m_t.elapsed();
	}

	void After(int i)
	{
		std::cout <<"time elapsed: "<< m_t.elapsed() - m_lastTime << std::endl;
	}

private:
	double m_lastTime;
	Timer m_t;
};

struct LoggingAspect
{
	void Before(int i)
	{
		std::cout <<"entering"<< std::endl;
	}

	void After(int i)
	{
		std::cout <<"leaving"<< std::endl;
	}
};

void foo(int a)
{
	std::cout <<"real HT function: "<<a<< std::endl;
}

//int main()
//{
//	Invoke<LoggingAspect, TimeElapsedAspect>(&foo, 1); //织入方法
//cout <<"-----------------------"<< endl;
//	Invoke<TimeElapsedAspect, LoggingAspect>(&foo, 1);
//
//	return 0;
//}

TEST(AspectTest, AOPInvoke)
{ 
	Invoke<LoggingAspect, TimeElapsedAspect>(&foo, 1); //织入方法
	cout << "-----------------------" << endl;
	Invoke<TimeElapsedAspect, LoggingAspect>(&foo, 1);
	//ASSERT_EQ(expected, actual);
}


TEST(AspectTest, TestName1)
{
    int expected = 3;
    int actual = 1;//add(1, 2);
    ASSERT_EQ(expected, actual);
}

TEST(AspectTest, TestName2)
{
	int expected = 1;
	int actual = 1;//add(1, 2);
	ASSERT_EQ(expected, actual);
}