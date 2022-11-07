CXX=g++
CXXFLAGS=-I./src -g -Wall -std=c++17
LIBS = -lglfw -lglew -framework OpenGL

OUTDIR = build
_OBJ = main.o program.o window.o shader.o
OBJ = $(patsubst %,$(OUTDIR)/%,$(_OBJ))

DEPS = $()

BIN = minecraft-clone
ARCH = $(shell arch)

$(shell mkdir -p $(OUTDIR))

# SECTION - Executable
$(BIN)-$(ARCH): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

# SECTION - Files
$(OUTDIR)/main.o: src/main.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(OUTDIR)/program.o: src/core/program.cpp src/core/program.hpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(OUTDIR)/window.o: src/core/window.cpp src/core/window.hpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(OUTDIR)/shader.o: src/graphics/shader.cpp src/graphics/shader.hpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)
# End Files

release: CXXFLAGS += -DRELEASE
release: $(BIN)-$(ARCH)

run:
	@./$(BIN)-$(ARCH)

clean:
	@rm -rf $(BIN)-$(ARCH) build/
