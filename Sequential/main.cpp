#include <stdio.h>	//Seq Radix Sort by Konstantinos Krestenitis 

int main (){
	int number[5] = {5, 23, 421, 1, 22};
	unsigned int kLength = 0;
	//find largest length number;
	unsigned int counter=0;
	for(unsigned int i=0;i<5;i++){
		if(number[i]==0) break;
		int digit=number[i];
		while((digit = digit/10)!=0){ counter++;}
		if(counter > kLength) kLength = counter;
		counter=0;
	} printf("K:%i\n",kLength);
	//assign radix digit to bucket
	int bucket[10][5] = {0}; bool hasValue[10][5] = {false};
	for(unsigned int i=0;i<kLength+1;i++){
		printf("loop:%i\n", i);
		for(unsigned int y=0;y<5;y++){
			int digit = number[y];
			for(unsigned int k=0;k<i;k++){
				//if(digit/10==0) break;
				digit = digit/10;
			}
			digit = digit%10;
			//if(digit==0 && digit%10==0) continue;
			printf("number:%i digit:%i\n", number[y], digit);
			
			for(unsigned int c=0; c<5;c++){
				if(hasValue[digit-1][c]!=true){
					bucket[digit-1][c] = number[y];
					hasValue[digit-1][c] = true;
					break;
				}
			}
		}
		counter=0;
		for(unsigned int y=0;y<10;y++){
			for(unsigned int x=0;x<5;x++){
				if(hasValue[y][x]==true) {
					number[counter++] = bucket[y][x];
					printf("bucket:%i with digit:%i\n", bucket[y][x], y);
					hasValue[y][x]=false;
				}
			}
		} counter=0;
		for(unsigned int y=0;y<5;y++){
			printf("N%i. V:%i\n", y, number[y]);
		}
	}
	return 0;
}