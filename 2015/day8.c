#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

#define loop for(;;)

int main(void){
	FILE *file = fopen("input/day8.txt", "r");
	if(!file){
		printf("[error]: failed to open \"input/day8.txt\"\n");
		return 1;
	}

	size_t codeNum = 0;
	size_t charNum = 0;
	size_t extrNum = 0;

	loop {
		char chr = fgetc(file);
		if(chr == EOF)
			break;

		if(chr == '\n' || chr == ' ')
			continue;

		codeNum++;

		if(chr == '"'){
			extrNum+=2;
			continue;
		}

		if(chr == '\\'){
			extrNum+=1;
			chr = fgetc(file);
			if(chr == EOF)
				break;

			codeNum++;

			if(chr == '\n' || chr == ' '){
				printf("[error]: incomplete escape\n");
				continue;
			}

			if(chr == '\\' || chr == '"'){
				charNum++;
				extrNum++;
				continue;
			}

			if(chr == 'x'){
				char buf[3] = {0};
				fread(buf, 1, 2, file);
				unsigned int val = strtol(buf, NULL, 16);
				if(!val)
					printf("[error]: invalid hex\n");
				codeNum+=2;
				charNum++;
			}

			/* TODO hex */

		} else
			charNum++;
	}

	printf("codeNum: %zu\n", codeNum);
	printf("charNum: %zu\n", charNum);
	printf("extrNum: %zu\n", extrNum);
	printf("cod-chr: %zu\n", codeNum - charNum);

	fclose(file);
	return 0;
}
