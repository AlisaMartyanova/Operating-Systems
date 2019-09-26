#include  <stdio.h>
#include  <signal.h>
#include  <stdlib.h>

void  handler(int sig)
{
     char  c;

     signal(sig, SIG_IGN);
     printf("Do you want to quit? [y/n] ");
     c = getchar();
     if (c == 'y' || c == 'Y')
          exit(0);
     else
          signal(SIGINT, handler);
     getchar();
}

int  main()
{
     signal(SIGINT, handler);
     while (1)
          pause();
     return 0;
}


