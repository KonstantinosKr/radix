#include <stdio.h>	//Sequential Radix Sort by Konstantinos Krestenitis 
#define nSize 5

int main (){
	int number[nSize] = {5, 23, 421, 1, 22};
	unsigned int kLength = 0;
	//find largest length number;
	unsigned int counter=0;
	for(unsigned int i=0;i<nSize;i++){
		if(number[i]==0) break;
		int digit=number[i];
		while((digit = digit/10)!=0){counter++;}
		if(counter > kLength) kLength = counter;
		counter=0;
	} printf("K:%i\n",kLength);
	//assign radix digit to bucket
	int bucket[nSize][nSize] = {0}; bool hasValue[nSize][nSize] = {false};
	for(unsigned int i=0;i<kLength+1;i++){
		//printf("loop:%i\n", i);
		for(unsigned int y=0;y<nSize;y++){
			int digit = number[y];
			for(unsigned int k=0;k<i;k++){digit = digit/10;}
			digit = digit%10;
			//printf("number:%i digit:%i\n", number[y], digit);
			for(unsigned int c=0; c<nSize;c++){
				if(hasValue[digit][c]!=true){
					bucket[digit][c] = number[y];
					hasValue[digit][c] = true;
					break;
				}
			}
		}
		counter=0;
		for(unsigned int y=0;y<nSize;y++){
			for(unsigned int x=0;x<nSize;x++){
				if(hasValue[y][x]==true) {
					number[counter++] = bucket[y][x];
					//printf("bucket:%i with digit:%i\n", bucket[y][x], y);
					hasValue[y][x]=false;
				}
			}
		} counter=0;
	}
	for(unsigned int y=0;y<nSize;y++){ printf("N%i. V:%i\n", y, number[y]); }
	return 0;
}