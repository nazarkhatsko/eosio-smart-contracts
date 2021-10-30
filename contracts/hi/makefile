# contract
TAG := $(notdir $(shell pwd))

# compiler
CC := eosio-cpp

DIR_BUILD := build
DIR_INCLUDE := include
DIR_RESOURCE := resource

# sources
SRCS := $(wildcard source/*.cpp)

# flags
CFLAGS := -abigen
CFLAGS += -contract $(TAG)
CFLAGS += -I $(DIR_INCLUDE)
CFLAGS += -R $(DIR_RESOURCE)

# mode list
.PHONY: build clean

# build mode
build: $(DIR_BUILD)/$(TAG).wasm

$(DIR_BUILD)/$(TAG).wasm: $(SRCS)
	@echo "[BUILD] -> $(TAG)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) $^ -o $@

# clean mode
clean:
	@echo "[CLEAN] -> $(TAG)"
	@rm -r -f $(DIR_BUILD)
