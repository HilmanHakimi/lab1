#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
void childTask() {
	char name[10];
	printf("Enter your name: ");
	fgets(name, 10, stdin);
	printf("Hello %s", name); 
}
 
void parentTask() {
	printf("\nJob is done\n");
}
 
int main(void) {

	for(int i = 1; i <5; i++) {
		pid_t pid = fork();
		if(pid == 0) {
    			childTask();
			
   	 		exit(0);
    		}
   		else if(pid > 0) {
    			wait(NULL);
		}
    		else {
   	 		printf("Unable to create child process.");
    		}	
 }
   
   	 parentTask(); 
 
 	 return EXIT_SUCCESS;
}
	
