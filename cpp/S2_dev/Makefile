main: out/main.exe

run_main: out/main.exe
	out/main.exe

out/main.exe: out/main.cpp
	g++ $^ -o $@

clean:
	rm -rf out/*
