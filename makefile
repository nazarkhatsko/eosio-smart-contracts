# contracts directory
DIR_CONTRACTS := contracts
CONTRACTS := $(sort $(dir $(wildcard $(DIR_CONTRACTS)/*/)))

# mode list
.PHONY: build clean

# build mode
build: $(CONTRACTS)
	@$(foreach item, $^, make --directory $(item) build;)

# clean mode
clean: $(CONTRACTS)
	@$(foreach item, $^, make --directory $(item) clean;)
