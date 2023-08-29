#include <nats/nats.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
    natsConnection *conn = NULL;
    natsSubscription *sub = NULL;
    natsMsg *msg = NULL;
    natsStatus s = NATS_OK;

    
	//Connecting to NATS Server
    s = natsConnection_ConnectTo(&conn, "localhost:4222");
    
    //Connection failed error
    if (s != NATS_OK)
    {
        fprintf(stderr, "Error connecting to NATS server: %s\n", natsStatus_GetText(s));
        return 1;
    }

	//Subscribing to subject(Foo)
    s = natsConnection_SubscribeSync(&sub, conn, "foo");
    
    //Subscription error
    if (s != NATS_OK)
    {
        fprintf(stderr, "Error subscribing: %s\n", natsStatus_GetText(s));
        natsConnection_Destroy(conn);
        return 1;
    }
	
	//Return the next message available to a synchronous subscriber 
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
    //Message not received.
    else
    {
        fprintf(stderr, "Error receiving message: %s\n", natsStatus_GetText(s));
    }
	//Created things must be destroyed
    natsSubscription_Destroy(sub);
    natsConnection_Destroy(conn);

    return 0;
}
