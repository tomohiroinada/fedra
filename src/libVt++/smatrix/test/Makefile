CXX = g++
#CXXFLAGS = -g -ggdb -Wall
CXXFLAGS = -DXXX1 -I../include -I/var/local/root/include  -O2 -funroll-loops -finline-functions -Wall
LD = g++

%o: %.C
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Dsinv.o 
tstit: main.o
	@echo "Compiling $@"
	$(LD) $^ -o $@

clean:
	rm *.o tstit
