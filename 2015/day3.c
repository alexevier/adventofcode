#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

struct Int2 {
	int x, y;
};

struct VecInt2 {
	struct Int2* val;
	size_t len;
};

#define loop while(1)

#define VECINT2_ZERO ((struct VecInt2){NULL, 0})
static void vecInt2Destroy(struct VecInt2* vec);
static void vecInt2Push(struct VecInt2* vec, const struct Int2* int2);
static long int vecInt2Find(const struct VecInt2* vec, const struct Int2* int2);

int main(void){
	struct VecInt2 vec = VECINT2_ZERO;
	struct Int2 pos = {0, 0};
	FILE* file = fopen("input/day3.txt", "r");
	if(!file){
		printf("[error]: failed to open \"input/day3.txt\"\n");
		return 1;
	}
	
	// part 1
	vecInt2Push(&vec, &pos);
	loop {
		char chr = fgetc(file);
		if(chr == EOF)
			break;
		if(chr == '\n')
			continue;
		
		switch(chr){
			case '^':
				pos.y++;
				break;
			case 'v':
				pos.y--;
				break;
			case '<':
				pos.x--;
				break;
			case '>':
				pos.x++;
				break;
		}
		
		if(vecInt2Find(&vec, &pos) == -1){
			vecInt2Push(&vec, &pos);
		}
	}
	printf("[unique]: %zu\n", vec.len);
	vecInt2Destroy(&vec);
	
	//part2
	rewind(file);
	bool realSanta = true;
	pos.x = pos.y = 0;
	struct Int2 posb = {0, 0};
	struct Int2* posc = &pos;
	vecInt2Push(&vec, posc);
	loop {
		char chr = fgetc(file);
		if(chr == EOF)
			break;
		if(chr == '\n')
			continue;
		
		switch(chr){
			case '^':
				posc->y++;
				break;
			case 'v':
				posc->y--;
				break;
			case '<':
				posc->x--;
				break;
			case '>':
				posc->x++;
				break;
		}
		
		if(vecInt2Find(&vec, posc) == -1){
			vecInt2Push(&vec, posc);
		}
		
		realSanta = !realSanta;
		if(realSanta){
			posc = &pos;
		} else {
			posc = &posb;
		}
	}
	printf("[both]: %zu\n", vec.len);
	vecInt2Destroy(&vec);
	
	fclose(file);
	return 0;
}

static void vecInt2Destroy(struct VecInt2* vec){
	if(vec->val)
		free(vec->val);
	vec->val = NULL;
	vec->len = 0;
}

static void vecInt2Push(struct VecInt2* vec, const struct Int2* int2){
	vec->len++;
	if(vec->val){
		vec->val = realloc(vec->val, vec->len * sizeof(struct Int2));
	} else {
		vec->val = malloc(vec->len * sizeof(struct Int2));
	}
	
	if(!vec->val){
		puts("[OUT OF MEMORY]");
		abort();
	}
	
	vec->val[vec->len - 1] = *int2;
}

static long int vecInt2Find(const struct VecInt2* vec, const struct Int2* int2){
	for(size_t i = 0; i < vec->len; ++i){
		if(
			vec->val[i].x == int2->x &&
			vec->val[i].y == int2->y
		) return i;
	}
	
	return -1;
}
