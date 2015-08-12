#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "player.h"
#include "logger.h"

#define NUMBER_OF_PLAYERS     3
#define HISTORY_DEPTH         2
#define STRATEGIES            4   // HISTORY_DEPTH^2
#define MAX_STRAT_VALUE       16  // STRATEGIES^2

player_t players[NUMBER_OF_PLAYERS];

const int number_of_rounds = 10;

int main(int argc, char ** argv){
  int history_size = (int)(number_of_rounds / 8) + 1;
  printf("History size: %i\n", history_size);
  uint8_t* history = calloc(1, history_size);
  
  printf("Game Settings: \n"
         "\tNumber of Plyers: %i\n"
         "\tHistory Depth:    %i\n"
         "\tStrategies:       %i\n",
         NUMBER_OF_PLAYERS,
         HISTORY_DEPTH,
         STRATEGIES);
  
  // Setup the players and their strategies.
  player_setup(&players[0], 0, 12, history_size);
  player_setup(&players[1], 0, 0,  history_size);
  player_setup(&players[2], 0, 15, history_size);

  int i;
  for (i = 0; i < number_of_rounds; i++)
  {
    play_round(players, NUMBER_OF_PLAYERS, history, history_size);
    printf("%s\n", get_bits(history, history_size));
  }
 
  printf("Player %i history %s\n", players[0].player_id,
     get_bits(players[0].player_history, history_size)); 
  printf("Player %i history %s\n", players[1].player_id,
     get_bits(players[1].player_history, history_size)); 
  printf("Player %i history %s\n", players[2].player_id,
     get_bits(players[2].player_history, history_size)); 



#if 0 
  uint8_t number[3] = {0};
  number[0] = 0;
  int x;


  printf("%s%s%s\n", get_bits(&number[2], sizeof(uint8_t)),
    get_bits(&number[1], sizeof(uint8_t)),
    get_bits(&number[0], sizeof(uint8_t)));
  new_history(&number, 3, 1);
  printf("%s%s%s\n", get_bits(&number[2], sizeof(uint8_t)),
    get_bits(&number[1], sizeof(uint8_t)),
    get_bits(&number[0], sizeof(uint8_t)));
  new_history(&number, 3, 1);
  printf("%s%s%s\n", get_bits(&number[2], sizeof(uint8_t)),
    get_bits(&number[1], sizeof(uint8_t)),
    get_bits(&number[0], sizeof(uint8_t)));
  new_history(&number, 3, 1);
  printf("%s%s%s\n", get_bits(&number[2], sizeof(uint8_t)),
    get_bits(&number[1], sizeof(uint8_t)),
    get_bits(&number[0], sizeof(uint8_t)));
  new_history(&number, 3, 1);
  printf("%s%s%s\n", get_bits(&number[2], sizeof(uint8_t)),
    get_bits(&number[1], sizeof(uint8_t)),
    get_bits(&number[0], sizeof(uint8_t)));
  uint8_t number[3] = {0};
  number[0] = 129;
  int x;
  for (x = sizeof(number)/sizeof(number[0]) - 1; x > 0; x--)
  {
    number[x] <<= 1;
    number[x-1] & (1<<7) ? number[x]++ : 0;
  }
  number[0] <<= 1;

  printf("%s%s%s\n", get_bits(&number[2], sizeof(uint8_t)),
    get_bits(&number[1], sizeof(uint8_t)),
    get_bits(&number[0], sizeof(uint8_t)));
  printf("%i %i %i\n", number[2], number[1], number[0]);
  number[2] <<= 1;
  if(number[1] & (1<<7)) number[2]++;
  number[1] <<= 1;
  if(number[0] & (1<<7)) number[1]++;
  number[0] <<= 1;
  
  printf("%s%s%s\n", get_bits(&number[2], sizeof(uint8_t)),
    get_bits(&number[1], sizeof(uint8_t)),
    get_bits(&number[0], sizeof(uint8_t)));
  printf("%i %i %i\n", number[2], number[1], number[0]);
#endif
  return 0;
}
