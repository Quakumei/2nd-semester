/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_CalcTestSuite_init = false;
#include "CalcTestSuite.h"

static CalcTestSuite suite_CalcTestSuite;

static CxxTest::List Tests_CalcTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_CalcTestSuite( "CalcTestSuite.h", 5, "CalcTestSuite", suite_CalcTestSuite, Tests_CalcTestSuite );

static class TestDescription_suite_CalcTestSuite_testAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CalcTestSuite_testAddition() : CxxTest::RealTestDescription( Tests_CalcTestSuite, suiteDescription_CalcTestSuite, 7, "testAddition" ) {}
 void runTest() { suite_CalcTestSuite.testAddition(); }
} testDescription_suite_CalcTestSuite_testAddition;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
