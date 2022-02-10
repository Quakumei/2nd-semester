```
cxxtestgen --error-printer -o runner.cpp CalcTestSuite.h && g++ -I$cxxtest -o runner.o Calc.cpp runner.cpp && ./runner.o
```
To run cxxtestgen from console: add cxxtest-4.4/bin to $PATH (both windows and linux)
To compile runner without I flag: (linux): add cxxtest-4.4 to $CPATH (folder where g++ looks for include files)
(windows(untested):) add cxxtest-4.4 to $INCLUDE, but probably $CPATH as long as you use g++ compiler.

