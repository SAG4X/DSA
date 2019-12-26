#include<stdio.h>
#include<string.h>

int main() {
	
   char mainString[100] = "ABCCBACABACABACABACACAACBABAC";
   char pattern[50] = "BAC";
   int result[strlen(mainString)];
   int index = -1;
   printf("source String: ");
	printf("pattern String: %s \n\n",pattern);
	int patLen = strlen(pattern);
   int strLen = strlen(mainString);
int i;
   for(i = 0; i<=(strLen - patLen); i++) {
      int j;
      for(j = 0; j<patLen; j++) {     
         if(mainString[i+j] != pattern[j])
            break;
      }

      if(j == patLen) { 
         index++;
         result[index] = i;
      }
   }
	
   for(i = 0; i <= index; i++) {
      printf("Pattern found at position: %d\n",result[i]);
   }
}
