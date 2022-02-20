test_containers: out/test_containers_dumb.exe


out/test_containers_dumb.exe: test/test_containers.cpp
	g++ $^ -o $@

out/test_containers.exe: out/test_containers.o out/containers.a
	g++ $^ -o $@ 

out/test_containers.o: test/test_containers.cpp
	g++ -c $< -o $@

out/containers.a: out/stack.o
	ar rcs $@ $^

out/stack.o: src/Stack.cpp
	g++ -c $< -o $@

clean:
	rm -rf out/*.o
