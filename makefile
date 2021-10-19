# project name
TAG := contract

# compiler name
CC := eosio-cpp

# source
SRC := $(wildcard source/*.cpp)

# include
INC := -Iinclude/

# flag
CFLAG := -Wall
CFLAG += -std=c++17

# mode list
.PHONY: build clean set push

# build mode
build: build/$(TAG)/$(TAG).wasm

build/$(TAG)/$(TAG).wasm: $(SRC)
	@echo "[BUILD]"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAG) $(INC) $^ -o $@

# clean mode
clean:
	@echo "[CLEAN]"
	@rm -r -f build/

# set mode
set:
	@echo "[SET]"
	@cleos set contract $(TAG) build/$(TAG) --abi $(TAG).abi -p $(TAG)@active

# push mode
push:
	@echo "[PUSH]"
	@cleos push action $(TAG) hi '[$(TAG)]' -p $(TAG)@active
