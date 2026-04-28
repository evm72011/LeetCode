DEBUG ?= 1
ENABLE_WARNINGS	?= 1
WARNINGS_AS_ERRORS ?= 0
TARGET ?= 011

INCLUDE_DIR = include
SOURCE_DIR  = .
BUILD_DIR   = build
BIN := $(BUILD_DIR)/$(TARGET)

ifeq ($(ENABLE_WARNINGS), 1)
	CXX_WARNINGS = -Wall -Wextra -Wpedantic -Wconversion -Wshadow
endif

ifeq ($(WARNINGS_AS_ERRORS), 1)
	CXX_WARNINGS += -Werror
endif

CXX						= g++
CXX_STANDARD	= c++23
CXXFLAGS			= $(CXX_WARNINGS) -std=$(CXX_STANDARD)
CPPFLAGS			= -I $(INCLUDE_DIR)
LDFLAGS				=

ifeq ($(DEBUG), 1)
	CXXFLAGS +=  -fsanitize=address,undefined -g -O0
	EXE_NAME = mainDebug
else
	CXXFLAGS += -O3
	EXE_NAME = mainRelease
endif

COMPILER_CALL = $(CXX) $(CXXFLAGS) ${CPPFLAGS} ${LDFLAGS}

SOURCES = $(wildcard $(SOURCE_DIR)/*.cpp)
BINS    = $(patsubst $(SOURCE_DIR)/%.cpp,$(BUILD_DIR)/%,$(SOURCES))

all: create $(BIN)

create:
	@mkdir -p $(BUILD_DIR)

$(BIN): $(SOURCE_DIR)/$(TARGET).cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $< -o $@ $(LDFLAGS)

run: all
	./$(BIN)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all create run clean
