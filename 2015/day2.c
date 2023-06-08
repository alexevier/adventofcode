#include<string.h>
#include<stdlib.h>
#include<stdio.h>

static int smallest(int x, int y, int z){
	if(x <= y && x <= z){
		return x;
	} else if(y <= z){
		return y;
	} else {
		return z;
	}
}

static int middlest(int x, int y, int z){
	if((x >= y && x <= z) ||
	   (x <= y && x >= z)){
		return x;
	} else if((y >= x && y <= z) ||
	   (y <= x && y >= z)){
		return y;
	} else {
		return z;
	}
}

int main(void){
	unsigned int totalWrap = 0;
	unsigned int totalRibbon = 0;
	unsigned int eof = 0;
	FILE* file = fopen("day2input.txt", "r");
	if(!file){
		printf("[error]: failed to open \"day2input.txt\"\n");
		return 1;
	}
	
	while(!eof){
		union {
			int iter[4];
			struct{int l,w,h;};
		} val;
		
		unsigned int i = 0;
		char buf[8] = {0};
		for(int j = 0; j < 3;){
			char chr = fgetc(file);
			switch(chr){
				case EOF:
					eof = 1;
					break;
				case '\n':
					if(j != 2){
						printf("[error]: missing arg\n");
						return 2;
					}
				case 'x':
					val.iter[j++] = atoi(buf);
					i = 0;
					memset(buf, 0, 8);
					break;
				default:
					buf[i++] = chr;
			}
			if(eof) // goto :)
				goto end;
		}
		
		int lx = val.l * val.w;
		int wx = val.w * val.h;
		int hx = val.h * val.l;
		totalWrap += ((lx + wx + hx) * 2) + smallest(lx, wx, hx);
		
		int smoll = smallest(val.l, val.w, val.h) * 2;
		int midle = middlest(val.l, val.w, val.h) * 2;
		totalRibbon += smoll + midle + (val.l * val.w * val.h);
	}
	
	end:
	printf("[total ribbon]: %u\n", totalRibbon);
	printf("[total wrapping paper]: %u\n", totalWrap);
	fclose(file);
	return 0;
}
