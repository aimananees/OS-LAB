#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE     128

struct msgbuf
{
    long    mtype;
    char    mtext[MAXSIZE];
};

main()
{
    int msgqid;
    int msgflg = IPC_CREAT | 0666;
    key_t key;
    struct msgbuf sbuf;
    size_t buflen;
    key = 1234;
 if ((msgqid=msgget(key,msgflg))< 0) //Get the message queue ID for the given key
      perror("msgget");
    //Message Type
    sbuf.mtype = 1;
    printf("Enter a message to add to message queue : ");
    scanf("%[^\n]",sbuf.mtext);
    buflen = strlen(sbuf.mtext) + 1 ;
    if (msgsnd(msgqid, &sbuf, buflen, IPC_NOWAIT) < 0)
    {
        printf ("%d, %d, %s, %d\n", msgqid, sbuf.mtype, sbuf.mtext, buflen);
        perror("msgsnd");
    }
    else
        printf("Message Sent\n");
          exit(0);
}
