CXX      = g++
CXXFLAGS = -O3 -Wall -g

.PHONY: all

SOURCES  = $(wildcard ./*.cpp)
TARGETS  = $(basename $(SOURCES))

define MACRO
$(1): $(1).cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
endef

all: clean $(TARGETS)
	$(foreach VAR, $(TARGETS), $(eval $(call MACRO $(VAR))))


clean:
	rm -f $(TARGETS)
