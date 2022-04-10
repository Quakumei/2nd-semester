main: out/main.exe

run_main: out/main.exe
	$<

run_test: out/test.out
	out/test.exe

out/main.exe: src/main.cpp src/shape.cpp src/rectangle.cpp src/base-types.cpp
	g++ $^ -o $@

clean:
	rm -rf out/*
