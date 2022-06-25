#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>


  int main()
{

int fd[2], i = 0;
pipe(fd);
pid_t pid = fork();

if(pid > 0) {
    wait(NULL);

    // closing the standard input
    close(0);

    // no need to use the write end of pipe here so close it
    close(fd[1]);

    // duplicating fd[0] with standard input 0
    dup(fd[0]);
    int num,c;

    // n stores the total bytes read successfully
    int n = read(fd[0], &num, sizeof(num));
    int i,flag = 0; 
    if (num == 0 || num == 1){
        flag = 1;}

    for (i = 2; i <= num / 2; ++i) {

        // if n is divisible by i, then n is not prime
        // change flag to 1 for non-prime number
        if (num % i == 0) {
              flag = 1;
              break;
        }
      }

  // flag is 0 for prime numbers
  if (flag == 0)
    printf("%d is a prime number.\n", num);
  else
    printf("%d is not a prime number.\n", num);

}
else if( pid == 0 ) {
    int num;
    printf("Please enter a number: ");
    scanf("%d", &num);

    // closing the pipe
    close(fd[0]);

    // closing the standard output
    close(1);

    // duplicating fd[0] with standard output 1
    dup(fd[1]);
    write(1, &num, sizeof(num));

}

else {
    perror("error\n"); //fork()
}
}
