#pragma once
#include "Calc.h"
#include <cxxtest/TestSuite.h>

class CalcTestSuite : public CxxTest::TestSuite {
public:
	void testAddition(void)
	{
		Calc calculator;
		TS_ASSERT_EQUALS(calculator.add(1,2), 3);
		TS_ASSERT_EQUALS(4, 4);
	}
};
