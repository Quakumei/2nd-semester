main: out/main.exe
test-containers: out/test-containers.exe

out/main.exe: src/main.cpp out/ExpressionCalculator.o
	g++ $^ -o $@

out/ExpressionCalculator.o: src/ExpressionCalculator.cpp
	g++ -c $< -o $@

out/test-containers.exe: test/test-containers.cpp src/Stack.hpp src/Queue.hpp
	g++ $< -o $@


clean:
	rm -rf out/*.o
