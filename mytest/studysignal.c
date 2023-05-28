#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void handler(int sig){
    psignal(sig,"\nThe SIGQUIT is deliverd!");
}

int main(int argc,char *argv[]){

    sighandler_t ret;
    sigset_t blockset,oldset;

    sigemptyset(&blockset);
    sigaddset(blockset,SIGQUIT);

    printf("Here is beginning\n");
    if((ret = signal(SIGQUIT,handler))==SIG_ERR){
        printf("To registr signal is error\n");
        exit(1);
    }

    if(sigprocmask(SIG_BLOCK,&blockset,&oldset)==-1){
        printf("To set signal mask is error\n");
        exit(2);
    }
    fflush(stdout);
    for(int i = 0;i<10;i++){
        printf("%d\n",i);
        sleep(1);
        if(i>5)sigprocmask(SIG_BLOCK,&oldset,NULL);
        else kill();
    }
    printf("Here is end");
    exit(0);

}