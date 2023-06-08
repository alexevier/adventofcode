#include<stdint.h>
#include<stddef.h>
#include<string.h>
#include<stdio.h>
#include<md5.h>

int main(void){
	const char input[] = "bgvyzdsv";
	uint8_t key[255] = {0};
	uint8_t hash[16];
	uint8_t key5 = 0;
	uint8_t key6 = 0;
	
	for(size_t i = 0; i < SIZE_MAX; i++){
		snprintf((void*)key, 255, "%s%zu", input,i);
		
		MD5_CTX mdctx;
		MD5Init(&mdctx);
		MD5Update(&mdctx, key, strlen((char*)key));
		MD5Final(hash, &mdctx);
		
		if( !key5 &&
			(hash[0] == 0x00) &&
			(hash[1] == 0x00) &&
			(hash[2]  < 0x10)
		){
			printf("[key5]: %s | %s\n", input, key+strlen(input));
			key5 = 1;
		}
		
		if( !key6 &&
			(hash[0] == 0x00) &&
			(hash[1] == 0x00) &&
			(hash[2] == 0x00)
		){
			printf("[key6]: %s | %s\n", input, key+strlen(input));
			key6 = 1;
		}
		
		if(key5 && key6)
			break;
	}
}
