#include <stdio.h>
int main(){
   printf("Here comes the data : \n");
   execl("/bin/date","date",0);
   printf("Hello");
   return 0;
}
