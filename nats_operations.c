#include <stdio.h>
#include <nats/nats.h>
#include "nats_operations.h"

char* publishMsg(char* message)
{
    
    printf("Enter message you want to publish: \n");
    scanf("%s", message);
    return message;
    
};

static void
onMsg(natsConnection *conn, natsSubscription *sub, natsMsg *msg, void *closure)
{
    printf("Received msg: %s - %.*s\n",
           natsMsg_GetSubject(msg),
           natsMsg_GetDataLength(msg),
           natsMsg_GetData(msg));

    // Need to destroy the message!
    natsMsg_Destroy(msg);
}

char* changeServer(char* serverAdress)
{
    printf("Enter server adress for connection: \n");
    scanf("%s", serverAdress);
    return serverAdress;
};

char* changeSubject(char* subject)
{
    printf("Enter subject of connection: \n");
    scanf("%s", subject);
    return subject;
};