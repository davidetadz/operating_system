/*
 * Illustrates system call fork
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main (
  int argc,
  char *argv[]
  )
{
  int tC, tF;
  pid_t pid;

  tC = atoi (argv[1]);
  tF = atoi (argv[2]);

  fprintf (stdout, "Main  :                  ");
  fprintf (stdout, "PID=%d; My parent PID=%d\n",
    getpid(), getppid());

  pid = fork();
  if (pid == 0){
    // Child
    sleep (tC);

    fprintf(stdout, "Child : PIDreturned=%d    ", pid);
    fprintf (stdout, "PID=%d; My parent PID=%d\n",
      getpid(), getppid());
  } else {
    // Father
    sleep (tF);

    fprintf(stdout, "Father: PIDreturned=%d ", pid);
    fprintf (stdout, "PID=%d; My parent PID=%d\n",
      getpid(), getppid());
  }

  return 0;
}
