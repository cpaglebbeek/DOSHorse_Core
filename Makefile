# DOSHorse_Core — Public API stub-impl build
# v0.0.4-Mazor — eerste libdoshorse_core.a build
#
# Build: 'make' produceert libdoshorse_core.a uit src/doshorse/*.c
# tegen include/doshorse/*.h
# Test:  'make smoke' compileert+linkt een trivial C-program dat
#        de API aanroept en de version-string print
#
# v0.0.4 scope: STUB-impl. doshorse_create/destroy/version werken;
#   doshorse_load_image/step_frame/save_state/load_state retourneren
#   pretend-success of -1 (not-implemented). Volwaardige impl in v0.0.7+
#   wanneer bindings/sdl2/, bindings/wasm/, bindings/jni/ klaarliggen.

CC := cc
CFLAGS := -std=c99 -Wall -Wextra -pedantic -O2 -I include
AR := ar
ARFLAGS := rcs

SRC_DIR := src/doshorse
BUILD_DIR := build
LIB := $(BUILD_DIR)/libdoshorse_core.a

SOURCES := $(SRC_DIR)/version.c $(SRC_DIR)/core.c $(SRC_DIR)/savestate.c
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

SMOKE_SRC := test/smoke.c
SMOKE_BIN := $(BUILD_DIR)/smoke

.PHONY: all lib smoke clean help version apply-patches clean-patches

all: lib

help:
	@echo "DOSHorse_Core v0.0.4-Mazor"
	@echo ""
	@echo "Targets:"
	@echo "  make lib            Build libdoshorse_core.a (default)"
	@echo "  make smoke          Compile + run test/smoke.c against the lib"
	@echo "  make apply-patches  Apply patches/*.patch to upstream/dosbox-x/"
	@echo "  make clean-patches  Revert all patches (git checkout in submodule)"
	@echo "  make clean          Remove build/"
	@echo "  make version        Show Core version"

version:
	@cat VERSION

lib: $(LIB)

$(LIB): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(AR) $(ARFLAGS) $@ $^
	@echo "✓ Built $@ ($$(du -h $@ | cut -f1))"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

smoke: $(SMOKE_BIN)
	@echo "Running $<..."
	@$(SMOKE_BIN)

$(SMOKE_BIN): $(SMOKE_SRC) $(LIB)
	$(CC) $(CFLAGS) -o $@ $< $(LIB)

apply-patches:
	@./tools/apply-patches.sh

clean-patches:
	@test -d upstream/dosbox-x && cd upstream/dosbox-x && git checkout . && echo "✓ All patches reverted" || true

clean:
	rm -rf $(BUILD_DIR)
