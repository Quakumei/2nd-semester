test_containers: out/test_containers.exe

out/test_containers.exe: out/test_containers.o out/containers.a
	g++ $^ -o $@ 

out/test_containers.o: test/test_containers.cpp
	g++ -c $< -o $@

out/containers.a: out/queue.o out/stack.o out/container.o
	ar rcs $@ $^

out/queue.o: src/Queue.cpp
	g++ -c $< -o $@

out/stack.o: src/Stack.cpp
	g++ -c $< -o $@

out/container.o: src/Container.cpp
	g++ -c $< -o $@

clean:
	rm -rf out/*.o
