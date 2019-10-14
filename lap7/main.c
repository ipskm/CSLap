#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
extern int errno;
//finish
int create_file(){
   char filename[80];
   printf("Enter name of the file to be created : ");
   scanf("%s", filename);
   int fd=open(filename,O_CREAT, S_IRUSR | S_IWUSR);
   printf("fd = %d\n",fd);
   if (fd ==-1){
       printf("Error Number % d\n", errno);
       perror("Program");
   }
   else{
      printf("File %s is created\n",filename);
   }
   close(fd);
}
//has some bug on display content
int read_file(){
   char filename[80];
   char content[200];
   printf("Enter name of th file to be read : ");
   scanf("%s", filename);
   int fd = open(filename,O_RDONLY);
//   ssize_t sz = read(fd,content,sizeof(content));
   //lseek(fd,0,SEEK_SET);
   read(fd,content,sizeof(content)); 
   printf("The content of this file is : %s", &content);
   if(fd == -1){
      printf("Error Number % d\n",errno);
      perror("Program");
   }
   close(fd);
}
//finish
int write_file(){
   char filename[80];
   char content[200];
   char temp;
   printf("Enter the name of file : ");
   scanf("%s",&filename);
   printf("Enter text to be entered in %s file : ",&filename);
   scanf("%c",&temp);
   fgets(content,200,stdin);
   //scanf("%[^\n]", content);
   printf("%s",content);
   int fd = open(filename,O_WRONLY,0644);
   ssize_t wr = write(fd,content,strlen(content));
   if (fd == -1)printf("Error Number %d\n",errno);
   close(fd);
}
//
int link_file(){
   char filename[80];
   printf("Enter name of the file to be link : ");
   scanf("%s", filename);
   size_t lnk = link(filename, SEEK_SET);
   printf("Enter anme of link file : ");
   scanf("%s", filename);
   size_t fd = open(filename,O_CREAT, S_IRUSR | S_IWUSR);
   if(lnk == -1 && fd == -1) 
      printf("Error Number : %d", errno); 
   else
      printf("Link file %s is create\n",filename);
   close(fd);
}
//not yet
int unlink_file(){
   char filename[80];
   printf("Enter filename of directory to unlink : ");
   scanf("%s",filename);
   int ulk =  unlink(filename);
   if(ulk == 0){
       printf("Link file %s is deleted", filename);
   }else{
       printf("Error Number %d", errno);
   }
}
//finish
int delete_file(){
   char filename[80];
   printf("Enter name of the file to be delete : ");
   scanf("%s",filename);
   int rm = remove(filename);
   if (rm == 0) printf("file %s is deleted.",filename);

}
//finish
int copy_file(){
   char filename1[80];
   char filename2[80];
   char content[200];
   printf("Enter the name of first file : ");
   scanf("%s", filename1);
   printf("Enter the name of file to copy : ");
   scanf("%s", filename2);
   int fd1 = open(filename1,O_RDONLY);
   size_t rd = read(fd1,content,sizeof(content));
   int fd2 = open(filename2, O_CREAT|O_WRONLY,0644);
   size_t wr = write(fd2,content,strlen(content));
   close(fd1);
   close(fd2);
   if (rd != -1 && wr != -1) printf("File %s is copy successful with file name is %s",filename1,filename2);
}
//finish
int main(){
   int choice=0;
   while(choice!=8){
       printf("\nMenu\n");
       printf("1. CREATE\n");
       printf("2. READ\n");
       printf("3. WRITE\n");
       printf("4. LINK\n");
       printf("5. UNLINK\n");
       printf("6. DELETE\n");
       printf("7. COPY\n");
       printf("8. EXIT\n");
       printf("Enter your choice:");
       scanf("%d", &choice);
       switch(choice){
           case 1:
              create_file();
              break;
           case 2:
              read_file();
              break;
           case 3:
              write_file();
              break;
           case 4:
              link_file();
              break;
           case 5:
              unlink_file();
              break;
           case 6:
              delete_file();
              break;
           case 7:
              copy_file();
              break;
       }
   }
   return 0;
}

