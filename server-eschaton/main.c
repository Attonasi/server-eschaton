#include "eserver.h"


int main(int argc, char const *argv[])
{

  srand(time(NULL));

  // Server Variables
  int port = PORT;
  Instance_t instance;
  int serverStatus = 1;
  char input[BUFFER] = "\0";
  int inputLen = 0;
  char output[BUFFER] = "\0";
  int outputLen = 0;

  // JSON
  json_t *root_j = json_object();
  json_t *map_j = json_object();
  json_error_t error_j;


  Key_t* map_k = "map";

  // Model Variables
  int map[170][6];
  for (int i = 0; i < 170; i++)
  {

  }

  int players[6][100];
  for (int i = 0; i < 6; i++)
  {
    (players[i], "%d ", i);
  }

  ModelData* md = createModelData(map, players);
  JsonData* jd = createJsonData(root_j, map_j, map_k, error_j);
  ServerData* sv = createServer(port, serverStatus, instance, input, inputLen, output, outputLen);
  GameObject* game = createGameObj(sv, jd, md);

  INITIATE_R(game);

  free(jd);
  free(sv);
  free(game);

  return 0;
}