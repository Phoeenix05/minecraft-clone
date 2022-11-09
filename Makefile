CXX=g++
CXXFLAGS=-I./src -I./vendor -g -Wall -std=c++17
LIBS = -lglfw -lglew -framework OpenGL

OUTDIR = build
_OBJ = main.o program.o window.o shader.o
OBJ = $(patsubst %,$(OUTDIR)/%,$(_OBJ))

DEPS = $()

BIN = minecraft-clone

$(shell mkdir -p $(OUTDIR))

# SECTION - Executable
$(BIN): $(OBJ)
	$(CXX) -o $@ build/*.o $(CXXFLAGS) $(LIBS)

# SECTION - Files
$(OUTDIR)/main.o: src/main.cpp
	@echo $<
	@$(CXX) -c -o $@ $< $(CXXFLAGS)

$(OUTDIR)/program.o: src/core/program.cpp src/core/program.hpp
	@echo $<
	@$(CXX) -c -o $@ $< $(CXXFLAGS)

$(OUTDIR)/window.o: src/core/window.cpp src/core/window.hpp
	@echo $<
	@$(CXX) -c -o $@ $< $(CXXFLAGS)

$(OUTDIR)/shader.o: src/graphics/shader.cpp src/graphics/shader.hpp
	@echo $<
	@$(CXX) -c -o $@ $< $(CXXFLAGS)

$(OUTDIR)/mesh.o: src/graphics/mesh.cpp src/graphics/mesh.hpp
	@echo $<
	@$(CXX) -c -o $@ $< $(CXXFLAGS)
# End Files

release: CXXFLAGS += -DRELEASE
release: $(BIN)

run:
	@./$(BIN)

clean:
	@rm -rf $(BIN) build/
