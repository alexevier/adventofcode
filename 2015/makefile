CC = clang
CFLAGS = -O3 -s -std=c99 -Wall -Wextra
BUILD = build

default:
	@echo -e "[\e[1;34mtargets\e[0m]"
	@echo "clean | dirs"
	@echo "day1 | day2 | day3 | day4 | day5 | day6 | day8"

day1: day1.c
	@echo -e "[\e[1;32mbuild\e[0m]: $@"
	@$(CC) $(CFLAGS) $^ -o $(BUILD)/$@
	@$(BUILD)/day1

day2: day2.c
	@echo -e "[\e[1;32mbuild\e[0m]: $@"
	@$(CC) $(CFLAGS) $^ -o $(BUILD)/$@
	@$(BUILD)/$@

day3: day3.c
	@echo -e "[\e[1;32mbuild\e[0m]: $@"
	@$(CC) $(CFLAGS) $^ -o $(BUILD)/$@
	@$(BUILD)/$@

day4: day4.c
	@echo -e "[\e[1;32mbuild\e[0m]: $@"
	@$(CC) $(CFLAGS) $^ -o $(BUILD)/$@ -lmd
	@$(BUILD)/$@

day5: day5.c
	@echo -e "[\e[1;32mbuild\e[0m]: $@"
	@$(CC) $(CFLAGS) $^ -o $(BUILD)/$@
	@$(BUILD)/$@

day6: day6.c
	@echo -e "[\e[1;32mbuild\e[0m]: $@"
	@$(CC) $(CFLAGS) $^ -o $(BUILD)/$@
	@$(BUILD)/$@

day8: day8.c
	@echo -e "[\e[1;32mbuild\e[0m]: $@"
	@$(CC) $(CFLAGS) -ansi $^ -o $(BUILD)/$@
	@$(BUILD)/$@

clean:
	@echo -e "[\e[1;31mclean\e[0m]"
	@rm -rf $(BUILD)

dirs:
	@mkdir $(BUILD)
