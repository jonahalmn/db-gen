CC=g++
FLAGS=-Wall -Weffc++ -Wextra -pedantic-errors -Werror -std=c++17
LIBS=curl

default:
	${CC} `Magick++-config --cxxflags --cppflags` \
	./src/*.cpp ./src/utils/*.cpp -o ./build/gen \
	${FLAGS} \
	-lcurl \
	-I/usr/local/Cellar/nlohmann-json/3.9.1_1/include \
	`Magick++-config --ldflags --libs` \
	-I/usr/local/Cellar/imagemagick/7.0.10-48/include