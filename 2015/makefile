CC = clang
CFLAGS = -O3 -s -std=c99 -Wall -Wextra
BUILD = build

default:
	@echo -e "[\e[1;34mtargets\e[0m]"
	@echo "clean | dirs"
	@echo "day1 | day2"

day1: day1.c
	@echo -e "[\e[1;32mbuild\e[0m]: day1"
	@$(CC) $(CFLAGS) $^ -o $(BUILD)/$@
	@$(BUILD)/day1

day2: day2.c
	@echo -e "[\e[1;32mbuild\e[0m]: day2"
	@$(CC) $(CFLAGS) $^ -o $(BUILD)/$@
	@$(BUILD)/$@

day3: day3.c
	@echo -e "[\e[1;32mbuild\e[0m]: $@"
	@$(CC) $(CFLAGS) $^ -o $(BUILD)/$@
	@$(BUILD)/$@

clean:
	@echo -e "[\e[1;31mclean\e[0m]"
	@rm -rf $(BUILD)

dirs:
	@mkdir $(BUILD)
