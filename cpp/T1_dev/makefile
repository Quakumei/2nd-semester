main: out/main.exe

run_main: out/main.exe
	$<

run_test: out/test.out
	out/test.exe

out/main.exe: src/main.cpp src/shape.cpp src/base-types.cpp src/rectangle.cpp src/circle.cpp src/ellipse.cpp
	g++ $^ -o $@

clean:
	rm -rf out/*
