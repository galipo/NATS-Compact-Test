#ifndef NATS_OPERATIONS_H
#define NATS_OPERATIONS_H

#include <nats/nats.h>

char* publishMsg(char* message);
void onMsg(natsConnection *conn, natsSubscription *sub, natsMsg *msg, void *closure);
char* changeServer(char* serverAddress);
char* changeSubject(char* subject);

#endif // NATS_OPERATIONS_H