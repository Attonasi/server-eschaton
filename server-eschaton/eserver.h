#ifndef FINAL_H
#define FINAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <jansson.h>
#include <ulfius.h>
#include <time.h>

// typedef #define

#define BUFFER 1000
#define PORT 8080

typedef struct _u_instance Instance_t;
typedef const struct _u_request U_Request_t;
typedef const char Key_t;
typedef struct _u_response U_Response_t;


typedef struct {

  json_t *root_j;

  json_t *map_j;

  Key_t* map_k;

  json_error_t error_j;

} JsonData;

JsonData* createJsonData(json_t* root_j, json_t* map_j, Key_t* map_k, json_error_t error_j);

typedef struct {

  int port;
  int serverStatus;
  struct _u_instance instance;
  char input[BUFFER];
  int inputLen;
  char output[BUFFER];
  int outputLen;

} ServerData;

ServerData* createServer(int port, int serverStatus, struct _u_instance instance, char* input, int inputLen, char* output, int outputLen);

typedef struct {

  int map[170][5];
  int players[6][100];

} ModelData;

ModelData* createModelData(int map[170][6], int players[6][100]);

typedef struct {

  ServerData* sv;
  JsonData* jd;
  ModelData* md;

} GameObject;

GameObject* createGameObj(ServerData* sv, JsonData* jd, ModelData* md);

void INITIATE_R(GameObject* game);

int shutdownGET_R(U_Request_t* request, struct _u_response* response, void* input);

int initGameGET_R(U_Request_t* request, struct _u_response* response, void* input);

int harvestPOST_R(U_Request_t* request, U_Response_t* response, void* input);

#endif