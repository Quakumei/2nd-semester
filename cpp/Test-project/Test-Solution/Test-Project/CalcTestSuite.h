#pragma once
#include "Calc.h"
#include <cxxtest/TestSuite.h>

class CalcTestSuite : public CxxTest::TestSuite {
public:
	void testAddition(void)
	{
		Calc obj;
		TS_ASSERT(obj.add(1, 3), 2);
	}
};