#ifndef NATS_OPERATIONS_H
#define NATS_OPERATIONS_H

#include <nats/nats.h>

char* publishMsg(char* message);
void subscribeToSubj();
char* changeServer(char* serverAddress);
char* changeSubject(char* subject);

#endif // NATS_OPERATIONS_H