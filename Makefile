ThreeSum: ThreeSum.o
	g++ -g -o ThreeSum.exe ThreeSum.o -pthread    

ThreeSum.o: ThreeSum/ThreeSum.cpp
	g++ -g  -c -pthread ThreeSum/ThreeSum.cpp
