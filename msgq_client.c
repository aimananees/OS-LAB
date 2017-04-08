#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE  	128
void die(char *s)
{
  perror(s);
  exit(1);
}

struct msgbuf
{
    long    mtype;
    char    mtext[MAXSIZE];
};

void main()
{
    int msqid;    
    int msgflg = IPC_CREAT | 0666;
    key_t key,key1;
    struct msgbuf rcvbuffer;
    struct msgbuf sbuf;
    size_t buflen;
    key = 1234;
    key1 = 4321;
    while(1)
	{
		if ((msqid = msgget(key, 0666)) < 0)
        die("msgget()");
        //Receive an answer of message type 1.
        if (msgrcv(msqid, &rcvbuffer, MAXSIZE, 1, 0) < 0)
        die("msgrcv");
        printf("%s\n", rcvbuffer.mtext);
       if(strcmp(sbuf.mtext,"bye")==0 || strcmp(rcvbuffer.mtext,"bye")==0)
       break;
        //
        if ((msqid=msgget(key1,msgflg))< 0) //Get the message queue ID for the given key
	    die("msgget");
 	    //Message Type
 	    sbuf.mtype = 1;
 	    printf("Enter a message to add to message queue : ");
 	    scanf("%[^\n]",sbuf.mtext);
 	    getchar();
 	    buflen = strlen(sbuf.mtext) + 1 ;
 	    if (msgsnd(msqid, &sbuf, buflen, IPC_NOWAIT) < 0)
 	    {
 	        printf ("%d, %ld, %s, %ld\n", msqid, sbuf.mtype, sbuf.mtext, buflen);
 	        die("msgsnd");
 	    }
 	    else
 	        printf("Message Sent\n");
       if(strcmp(sbuf.mtext,"bye")==0 || strcmp(rcvbuffer.mtext,"bye")==0)
       break;
    }
    exit(0);
}