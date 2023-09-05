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
    enum Operation op;
    int exit = 1;

    s = natsOptions_Create(&opts);
    s = natsConnection_ConnectTo(&conn, changeServer(serverAdress));

    
    while (exit)    
    {
        printf("Select operation number: \n 0.Publish \n 1.Subscribe \n 4.Exit \n");
        scanf("%u", &op);

         switch (op)
        {
        case Publish:   s = natsConnection_PublishString(conn, changeSubject(subject), publishMsg(message)); break;
        case Subscribe: s = natsConnection_SubscribeSync(&sub, conn, changeSubject(subject));
                        s = natsSubscription_NextMsg(&msg, sub, 10000);
                         if (s == NATS_OK)   
                            {   
                                printf("Received msg: %s - %.*s\n",
                                    natsMsg_GetSubject(msg),
                                    natsMsg_GetDataLength(msg),
                                    natsMsg_GetData(msg));

                            //Created things must be destroyed
                                natsMsg_Destroy(msg);
                            }
                            //Message receiving time interval
                            else if (s == NATS_TIMEOUT)
                            {
                                printf("No message received within the timeout.\n");
                            }
                        natsSubscription_Destroy(sub); 
        break;
        case ExitProgram: exit = 0; break;
    
        default:
         break;
        }
    }
    
   

    
    
   
    natsConnection_Destroy(conn);
    natsOptions_Destroy(opts);

	return 0;
}

