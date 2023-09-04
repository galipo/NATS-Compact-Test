#include <stdio.h>
#include <nats/nats.h>
#include <time.h>

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

enum Operation
{
    Publish,
    Subscribe,
    ChangeServer,
    ChangeSubject,
    ExitProgram
};


int main(int argc, char **argv)
{
    natsConnection      *conn      = NULL;
    natsOptions         *opts      = NULL;
    natsSubscription    *sub       = NULL;
    natsMsg             *msg       = NULL;
    natsStatus          s          = NATS_OK;

    char subject[255];
    char serverAdress[255];
    char message[255];

    s = natsOptions_Create(&opts);
    s = natsConnection_ConnectTo(&conn, changeServer(serverAdress));
    s = natsConnection_PublishString(conn, changeSubject(subject), publishMsg(message));
    natsConnection_Destroy(conn);
    natsOptions_Destroy(opts);

	return 0;
}

