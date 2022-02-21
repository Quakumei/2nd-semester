main: out/main.exe
test-containers: out/test-containers.exe

out/main.exe: src/main.cpp
	g++ $^ -o $@

out/test-containers.exe: test/test-containers.cpp src/Stack.hpp
	g++ $< -o $@

# out/main.o: src/main.cpp
# 	g++ -c $< -o $@

# out/stack.o: src/Stack.hpp
# 	g++ -c $< -o $@
	
clean:
	rm -rf out/*.o
