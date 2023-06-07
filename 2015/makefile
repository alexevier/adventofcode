CC = clang
CFLAGS = -O3 -s -std=c99 -Wall -Wextra
BUILD = build

default:
	@echo -e "[\e[1;34mtargets\e[0m]"
	@echo "clean | dirs"
	@echo "day1"

day1: day1.c
	@echo -e "[\e[1;32mbuild\e[0m]: day1"
	@$(CC) $(CFLAGS) $^ -o $(BUILD)/$@
	@$(BUILD)/day1

clean:
	@ rm -rf $(BUILD)

dirs:
	mkdir $(BUILD)
