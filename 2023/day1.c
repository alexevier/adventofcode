#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

int main(void){
	FILE *file = fopen("input/day1.txt", "r");
	if(!file){
		perror("input/day1.txt");
		return 1;
	}

	int total = 0;
	char num[3] = {0,0,'\0'};
	while(1){
		int ichr = fgetc(file);
		if(ichr == EOF)
			break;

		if(isdigit(ichr)){
			if(num[0])
				num[1] = ichr;
			else
				num[0] = ichr;
		}

		if(ichr == '\n'){
			if(!num[1])
				num[1] = num[0];

			total += atoi(num);

			num[0] = num[1] = 0;
		}
	}

	printf("part 1: %i %s\n", total, (total == 56506)? "\x1b[92mok\x1b[0m" : "\x1b[91mwrong\x1b[0m");

	fclose(file);
	return 0;
}
