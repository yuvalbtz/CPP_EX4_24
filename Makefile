CXX=g++
CXXFLAGS=-std=c++20 -Werror -Wall
VALGRIND_FLAGS=--leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --error-exitcode=99
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

SOURCES=Complex.cpp
TESTSOURCES=tests.cpp
DEMO_SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
DEMO_OBJECTS=$(DEMO_SOURCES:.cpp=.o)
TESTOBJECTS=$(TESTSOURCES:.cpp=.o)

HEADERS=Node.hpp \
        Tree.hpp \
        IteratorType.hpp \
		catch.hpp \
        PreOrderIterator.hpp \
        PostOrderIterator.hpp \
        InOrderIterator.hpp \
        BFSIterator.hpp \
        DFSIterator.hpp \
        MinHeapIterator.hpp \
        Complex.hpp \
        BaseIterator.hpp \


TEMPLATES=Node.tpp \
          Tree.tpp \
          MinHeapIterator.tpp \
          PreOrderIterator.tpp \
          PostOrderIterator.tpp \
          InOrderIterator.tpp \
          BFSIterator.tpp \
          DFSIterator.tpp \


tree: $(DEMO_OBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(DEMO_OBJECTS) $(OBJECTS) -o tree $(LDFLAGS)

tests: $(TESTOBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(TESTOBJECTS) $(OBJECTS) -o tests

runtree: tree
	 ./tree

runtests: tests
	./tests

tidy:
	clang-tidy $(SOURCES) $(DEMO_SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

treevalgrind: tree
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./tree | { egrep "==" || true; }


testsvalgrind: tests
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "==" || true; }

clean:
	rm -f *.o tree tests
