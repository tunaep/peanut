#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "player.h"


#define NUMBER_OF_PLAYERS     3
#define HISTORY_DEPTH         2
#define STRATEGIES            4   // HISTORY_DEPTH^2
#define MAX_STRAT_VALUE       16  // STRATEGIES^2

player_t players[NUMBER_OF_PLAYERS];

int history = 0;
const int number_of_rounds = 100;



int main(int argc, char ** argv){
  
  printf("Game Settings: \n"
         "\tNumber of Plyers: %i\n"
         "\tHistory Depth:    %i\n"
         "\tStrategies:       %i\n",
         NUMBER_OF_PLAYERS,
         HISTORY_DEPTH,
         STRATEGIES);
  

  
  players[0].player_id = 0;
  players[1].player_id = 1;
  players[2].player_id = 2;

  players[0].player_strategy = 3;   // 0011
  players[1].player_strategy = 12;  // 1100
  players[3].player_strategy = 7;   // 1001

  players[0].player_decision = 1;
  players[1].player_decision = 0;
  players[2].player_decision = 1;

  get_player_decision(players[0], 1);
  
  int i;
  for (i = 0; i < NUMBER_OF_PLAYERS; i++)
  {
    get_player_decision(players[i], 2);
  }
  
  get_round_result(players, NUMBER_OF_PLAYERS);


  return 0;
}
