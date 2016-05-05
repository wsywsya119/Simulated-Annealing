SRCS:=main.cpp point.cpp read.cpp K-means.cpp process.cpp SA.cpp
OBJS:=$(SRCS:.cpp=.o)
EXEC:=k-means
CXX:=g++ -g -O6 -Wall

.PHONEY: dep depend

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS)

dep: .depend

depned: .depend

.depend:
	$(CXX) -M $(SRCS) > $@ 


clean:
	rm -rf *.o $(EXEC) .depend


sinclude .depend
