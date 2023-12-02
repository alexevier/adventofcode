CC = clang
CFLAGS = -O3 -s -std=c99 -Wall -Wextra
BUILD = build

default:
	@echo -e "[\e[1;34mtargets\e[0m]"
	@echo "clean"
	@echo "day1"

day1: day1.c
	@echo -e "[\e[1;32mbuild\e[0m]: $@"
	@mkdir -p $(BUILD)
	@$(CC) $(CFLAGS) $^ -o $(BUILD)/$@
	@$(BUILD)/day1

clean:
	@echo -e "[\e[1;31mclean\e[0m]"
	@rm -rf $(BUILD)
