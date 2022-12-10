all:
	clang++ -Wall -O3 -std=c++20 -I./Includes Includes/glad/glad.cpp -LLibs Libs/libSDL2.dylib main.cpp -o Bin/main

	cp -R Libs Bin/Libs
	./Bin/main -rpath @executable_path/Libs