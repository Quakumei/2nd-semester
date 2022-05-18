main: out/main.exe

run_working: out/working.exe
	$<
out/working.exe: src/working.cpp
	g++ $< -o $@

run_test: out/test.exe
	out/test.exe

run_main: out/main.exe
	$<

out/main.exe: src/main.cpp src/iofmtguard.cpp src/DataStruct.cpp
	g++ $^ -o $@

out/test.exe: test/test.cpp
	g++ $< -o $@


clean:
	rm -rf out/*
