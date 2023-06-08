#include<inttypes.h>
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

#define loop while(1)

struct Char2 {
	char x,y;
};

// quick Vector implementation
struct VecChar2 {
	struct Char2* val;
	size_t len;
};
static void vecChar2Destroy(struct VecChar2* vec);
static void vecChar2Push(struct VecChar2* vec, const struct Char2* char2);
static long int vecChar2Find(const struct VecChar2* vec, const struct Char2* char2);

int main(void){
	FILE* file = fopen("day5input.txt", "r");
	if(!file){
		printf("[error]: failed to open \"day5input.txt\"\n");
		return 1;
	}
	
	uint64_t nice = 0;
	uint64_t nice2 = 0;
	
	// part 1
	loop {
		char chr = 0;
		char lst = 0;
		uint64_t vow = 0;
		bool dbl = 0;
		bool inv = 0;
		loop {
			chr = fgetc(file);
			if(chr == EOF)
				goto breaker;
			if(chr == '\n')
				break;
			if(chr == '\0')
				break;
			
			if( chr == 'a' ||
				chr == 'e' ||
				chr == 'i' ||
				chr == 'o' ||
				chr == 'u'
			){
				vow++;
			}
			
			if(chr == lst){
				dbl = true;
			}
			
			if(!inv){
				if(lst == 'a' && chr == 'b'){inv = true;}
				if(lst == 'c' && chr == 'd'){inv = true;}
				if(lst == 'p' && chr == 'q'){inv = true;}
				if(lst == 'x' && chr == 'y'){inv = true;}
			}
			
			lst = chr;
		}
		
		if(inv)
			continue;
		if(vow < 3)
			continue;
		if(!dbl)
			continue;
		
		nice++;
	}
	breaker:
	
	// part 2
	rewind(file);
	loop {
		char chr = 0;
		char lst = 0;
		char pst = 0;
		bool rep = false;
		bool bet = false;
		struct VecChar2 vec = {NULL, 0};
		loop {
			chr = fgetc(file);
			if(chr == EOF)
				goto breaker2;
			if(chr == '\n')
				break;
			if(chr == '\0')
				break;
			
			if(pst == chr){
				bet = true;
			}
			
			if(!(chr == lst && chr == pst)){
				if(vecChar2Find(&vec, &(struct Char2){chr, lst}) != -1){
					rep = true;
				}
				vecChar2Push(&vec, &(struct Char2){chr, lst});
			}
			
			pst = lst;
			lst = chr;
		}
		
		vecChar2Destroy(&vec);
		
		if(!rep)
			continue;
		if(!bet)
			continue;
		
		nice2++;
	}
	breaker2:
	
	printf("[nice]: %"PRIu64"\n", nice);
	printf("[nice2]: %"PRIu64"\n", nice2);
	fclose(file);
	return 0;
}

static void vecChar2Destroy(struct VecChar2* vec){
	if(vec->val)
		free(vec->val);
	vec->val = NULL;
	vec->len = 0;
}

static void vecChar2Push(struct VecChar2* vec, const struct Char2* char2){
	vec->len++;
	if(vec->val){
		vec->val = realloc(vec->val, vec->len * sizeof(struct Char2));
	} else {
		vec->val = malloc(vec->len * sizeof(struct Char2));
	}
	
	if(!vec->val){
		puts("[OUT OF MEMORY]");
		abort();
	}
	
	vec->val[vec->len - 1] = *char2;
}

static long int vecChar2Find(const struct VecChar2* vec, const struct Char2* char2){
	for(size_t i = 0; i < vec->len; ++i){
		if(
			vec->val[i].x == char2->x &&
			vec->val[i].y == char2->y
		) return i;
	}
	
	return -1;
}
