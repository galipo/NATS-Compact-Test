#include <stdio.h>
#include <nats/nats.h>
#include "nats_operations.h"

char* publishMsg(char* message)
{
    printf("Enter message you want to publish: \n");
    scanf("%s", message);
    return message;
    
};

void subscribeToSubj()
{

};

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