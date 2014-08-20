#include <stdio.h>	//Seq Radix Sort by Konstantinos Krestenitis
#include <string.h>
#define nSize 5

int main (){
	unsigned int number[nSize] = {5, 23, 421, 1, 22}, counter=0, digit = 0, bucket[16][1000] = {0};
	for(unsigned int i=0;i<3;i++){
		for(unsigned int y=0;y<nSize;y++){
            for(unsigned char c=0; c<nSize;c++){
                if(bucket[digit = (number[y]>>(4*i)) & 0b1111][c]==0){
                    bucket[digit][c] = number[y]; break;
                }
            }
		}counter=counter xor counter;
		for(unsigned char y=0;y<16;y++){
			for(unsigned int x=0;x<nSize;x++){
				if(bucket[y][x]==0) {break;} else {
                    number[counter++] = bucket[y][x];
                }
			}
		}memset(bucket, 0, sizeof(bucket[0][0])*16*1000);
	}
	return 0;
}