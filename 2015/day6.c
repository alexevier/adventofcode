#ifndef _GNU_SOURCE
#	define _GNU_SOURCE
#endif
#include<stdbool.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define INSTR_ON  1
#define INSTR_OFF 2
#define INSTR_TOG 3

struct Point {
	uint16_t x;
	uint16_t y;
};

 // this might crash if the stack is not big enough.
int main(void){
	bool light[1000][1000];
	uint32_t lightBright[1000][1000];
	FILE* file = fopen("input/day6.txt", "r");
	if(!file){
		printf("[error]: failed to open \"input/day6.txt\"\n");
		return 1;
	}
	
	for(uint16_t x = 0; x < 1000; x++){
		for(uint16_t y = 0; y < 1000; y++){
			light[x][y] = false;
			lightBright[x][y] = 0;
		}
	}
	
	bool eof = false;
	while(!eof){
		uint8_t  instr = 0;
		char buf[64] = {0};
		char* line = (char*)buf;
		
		for(uint8_t i = 0; i < 64; i++){
			line[i] = fgetc(file);
			if(line[i] == '\n'){
				line[i] = '\0';
				break;
			}
			if(line[i] == EOF){
				line[i] = '\0';
				eof = true;
				break;
			}
		}
		
		if(line[0] == '\0')
			continue;
		
		struct Point pnt1 = {0, 0};
		struct Point pnt2 = {0, 0};
		
		char* token = NULL;
		#define nextToken {token = strtok_r(line, ", ", &line); if(token == NULL){printf("[incomplete string]\n"); continue;}}
		
		nextToken;
		if(strcmp(token, "turn") == 0){
			nextToken;
			if(strcmp(token, "on") == 0){
				instr = INSTR_ON;
			} else if(strcmp(token, "off") == 0){
				instr = INSTR_OFF;
			}
		} else if(strcmp(token, "toggle") == 0){
			instr = INSTR_TOG;
		}
		
		if(!instr){
			printf("[invalid instruction]: %s\n", token);
			continue;
		}
		
		nextToken;
		pnt1.x = atoi(token);
		nextToken;
		pnt1.y = atoi(token);
		
		nextToken;
		// skip "through"
		
		nextToken;
		pnt2.x = atoi(token);
		nextToken;
		pnt2.y = atoi(token);
		for(uint16_t x = pnt1.x; x <= pnt2.x; x++){
			for(uint16_t y = pnt1.y; y <= pnt2.y; y++){
				switch(instr){
					case INSTR_ON:
						light[x][y] = true;
						lightBright[x][y]++;
						break;
					case INSTR_OFF:
						light[x][y] = false;
						if(lightBright[x][y])
							lightBright[x][y]--;
						break;
					case INSTR_TOG:
						light[x][y] = !light[x][y];
						lightBright[x][y] += 2;
						break;
				}
			}
		}
		
		#undef nextToken
	}
	
	uint32_t total = 0;
	uint32_t totalBright = 0;
	for(uint16_t x = 0; x < 1000; x++){
		for(uint16_t y = 0; y < 1000; y++){
			if(light[x][y]){
				total++;
			}
			totalBright += lightBright[x][y];
		}
	}
	
	fclose(file);
	printf("[total lights on]: %u\n", total);
	printf("[total lights brightness]: %u\n", totalBright);
	return 0;
}
