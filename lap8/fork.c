#include<stdio.h>
int main(){
   int pid;
   pid = fork();
   if (pid == 0){
      //this is the child process
      printf("This is child Process\n");
   }
   else {
      //This is the Parent process.
      printf("This is parent process and PID of child process is %d \n" , pid);
   }
}
