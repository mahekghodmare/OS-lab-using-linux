#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
pid_t pid;
printf("Parent Process started\n");
printf("Parent PID: %d\n",getpid());
pid = fork();
if(pid<0){
printf("Process creation failed\n");
}
else if(pid==0){
printf("\nChildProcess\n");
printf("Child PID: %d\n", getppid());
execl("/bin/ls","ls","-1",NULL);
printf("Exec failed\n");
} else{
wait(NULL);
printf("\nChild process completed\n");
printf("Parent process exiting\n");
}
return 0;
}
