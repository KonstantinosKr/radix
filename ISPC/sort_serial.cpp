 //Seq Radix Sort by Konstantinos Krestenitis
#include <string.h>

void sort_serial (int nSize, unsigned int number[], int order[]){
  unsigned int counter=0, bucket[16][50000] = {0}; unsigned char digit;
  for(unsigned char i=0;i<8;i++){
    for(unsigned int y=0;y<nSize;y++){
      for(unsigned int c=0; c<nSize;c++){
        if(bucket[digit = (number[y]>>(4*i)) & 0b1111][c]==0){
          bucket[digit][c] = number[y]; break;
        }
      }
    } counter=counter xor counter;
    for(unsigned char y=0;y<16;y++){
      for(unsigned int x=0;x<nSize;x++){
          if(bucket[y][x]==0) {break;} else {
            number[counter++] = bucket[y][x];
          }
      }
    } memset(bucket, 0, sizeof(bucket[0][0])*16*50000); 
  }
}