main: out/main.exe
	
run_main: out/main.exe
	$^

run_test: out/test.out
	out/test.exe

out/main.exe: out/main.o 
	g++ $^ -o $@

out/main.o: src/main.cpp 
	g++ -c $< -o $@

clean:
	rm -rf out/*
