main: out/main.exe

run_main: out/main.exe
	out/main.exe

run_test: out/test.exe
	out/test.exe

out/test.exe: test/tests.cpp 
	g++ $^ -o $@

out/main.exe: out/main.cpp
	g++ $^ -o $@


clean:
	rm -rf out/*
