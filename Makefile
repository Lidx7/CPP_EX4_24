# Compiler
CXX = g++

# Qt specific
QT_MODULES = Core Gui Widgets
QT_INCPATH = $(shell pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets)
QT_LIBS = $(shell pkg-config --libs Qt5Core Qt5Gui Qt5Widgets)

# Qt tools
MOC = moc
UIC = uic

# Compiler flags
CXXFLAGS = -I. $(QT_INCPATH) -Wall -Wextra -std=c++17 -fPIC

# Linker flags
LDFLAGS = $(QT_LIBS)

# Source and object directories
SRCDIR = .
OBJDIR = obj

# Source files
COMMON_SRCS = $(filter-out $(SRCDIR)/main.cpp $(SRCDIR)/test_tree.cpp, $(wildcard $(SRCDIR)/*.cpp))
HEADERS = $(wildcard $(SRCDIR)/*.h) $(wildcard $(SRCDIR)/*.hpp)

# Generated files
UI_HEADER = ui_mainwindow.h
MOC_SRCS = moc_mainwindow.cpp

# Object files
COMMON_OBJS = $(filter-out $(OBJDIR)/main.o $(OBJDIR)/test_tree.o, $(COMMON_SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)) $(MOC_SRCS:%.cpp=$(OBJDIR)/%.o)

# Demo executable
DEMO_TARGET = demo
DEMO_OBJS = $(COMMON_OBJS) $(OBJDIR)/main.o
DEMO_SRCS = $(COMMON_SRCS) $(SRCDIR)/main.cpp

# Test executable
TEST_TARGET = test
TEST_SRCS = $(COMMON_SRCS) $(SRCDIR)/test_tree.cpp
TEST_OBJS = $(COMMON_OBJS) $(OBJDIR)/test_tree.o

# Default target
all: $(UI_HEADER) $(MOC_SRCS) $(DEMO_TARGET) $(TEST_TARGET)

# Link the demo executable
$(DEMO_TARGET): $(DEMO_OBJS)
	@echo "Building demo executable..."
	$(CXX) $(DEMO_OBJS) -o $@ $(LDFLAGS)

# Link the test executable
$(TEST_TARGET): $(TEST_OBJS)
	@echo "Building test executable..."
	$(CXX) $(TEST_OBJS) -o $@ $(LDFLAGS)

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(UI_HEADER) | $(OBJDIR)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile moc sources
$(OBJDIR)/moc_%.o: moc_%.cpp | $(OBJDIR)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Generate moc sources
moc_%.cpp: %.h
	@echo "Generating moc file for $<..."
	$(MOC) $(QT_INCPATH) $< -o $@

# Generate UI header
$(UI_HEADER): mainwindow.ui
	@echo "Generating UI header..."
	$(UIC) $< -o $@

# Create object directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean up
clean:
	@echo "Cleaning up..."
	rm -rf $(OBJDIR) $(DEMO_TARGET) $(TEST_TARGET) $(UI_HEADER) $(MOC_SRCS)

# Run the demo program
run: $(DEMO_TARGET)
	./$(DEMO_TARGET)

# Build the test executable
build_test: $(TEST_TARGET)

# Run the tests
run_test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Phony targets
.PHONY: all clean run build_test run_test