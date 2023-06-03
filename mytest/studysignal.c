#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


// static void handler(int sig){
//     psignal(sig,"The SIGQUIT is deliverd!");  
//     fflush(stdout);
// }

// int main(int argc,char *argv[]){

//     sighandler_t ret;
//     sigset_t blockset,oldset,pendings;

//     sigemptyset(&blockset);
//     sigemptyset(&oldset);
//     sigaddset(&blockset,SIGQUIT);

//     printf("Here is beginning\n");
//     if((ret = signal(SIGQUIT,handler))==SIG_ERR){
//         printf("To registr signal is error\n");
//         exit(1);
//     }

//     if(sigprocmask(SIG_BLOCK,&blockset,&oldset)==-1){
//         printf("To set signal mask is error\n");
//         exit(2);
//     }
//     fflush(stdout);
//     for(int i = 0;i<10;i++){
//         printf("%d\n",i);
//         sleep(1);
//         if(i==5)sigprocmask(SIG_SETMASK,&oldset,NULL);
//         if(i==0) raise(SIGQUIT);
//         if(sigpending(&pendings)==0 && sigismember(&pendings,SIGQUIT)==1)
//             printf("The SIGQUIT has coming.\n");
//     }
//     printf("Here is end");
//     exit(0);

// }

static void handler(int sig){
    static int n = 0;
    psignal(sig,"The SIGALRM is deliverd!"); 
    printf("%d\n",n++); 
    fflush(stdout);
}

int main(int argc,char *argv[]){

    sighandler_t ret;


    printf("Here is beginning\n");
    if((ret = signal(SIGALRM,handler))==SIG_ERR){
        printf("To registr signal is error\n");
        exit(1);
    }

    kill(getpid(),SIGALRM);
    kill(getpid(),SIGALRM);

    printf("Here is end");
    exit(0);

}