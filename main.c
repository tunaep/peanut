#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "player.h"
#include "logger.h"

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
  
  // Setup the players and their strategies.
  player_setup(&players[0], 0, 12);
  player_setup(&players[1], 0, 0);
  player_setup(&players[2], 0, 15);
 
  printf("history [%s]\n", get_bits(&history, sizeof(history)));
  play_round(players, NUMBER_OF_PLAYERS, &history);
  printf("history [%s]\n", get_bits(&history, sizeof(history)));
  play_round(players, NUMBER_OF_PLAYERS, &history);
  printf("history [%s]\n", get_bits(&history, sizeof(history)));
  play_round(players, NUMBER_OF_PLAYERS, &history);
  printf("history [%s]\n", get_bits(&history, sizeof(history)));
  play_round(players, NUMBER_OF_PLAYERS, &history);
  printf("history [%s]\n", get_bits(&history, sizeof(history)));
  play_round(players, NUMBER_OF_PLAYERS, &history);
  printf("history [%s]\n", get_bits(&history, sizeof(history)));
  
  printf("History is now %i\n", history);
  return 0;
}
