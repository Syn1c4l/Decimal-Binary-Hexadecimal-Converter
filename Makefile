all:
	g++ -Wall Converter.cpp -o convert

run:
	./convert

try: all run