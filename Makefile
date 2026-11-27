CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic
TARGET := sorting_benchmark
SOURCES := src/DynamicArray.cpp src/DataSet.cpp src/SortMetrics.cpp src/main.cpp src/HeapType.cpp src/BenchmarkOutput.cpp
HEADERS := include/DynamicArray.h include/DataSet.h include/SortMetrics.h include/HeapType.h include/BenchmarkOutput.h

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -Iinclude $(SOURCES) -o $@

clean:
	$(RM) $(TARGET) $(TARGET).exe
