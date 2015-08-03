#include <stdio.h>
#include "player.h"
#include "logger.h"

/*
 * @brief - Get the players decision based on a given history.
 */
int get_player_decision(player_t player, const int history)
{
//  dbg_printf("Player strategy: %i", player.player_strategy);
//  dbg_printf("History: %i", history);

  if(check_bit(player.player_strategy, history))
  {
    dbg_printf("Returning 1");
    return 1;
  }
  else
  {
    dbg_printf("Returning 0");
    return 0;
  }
}  

/*
 * @brief - Get the round result based on an array of players' decisions.
 */
int get_round_result(player_t* players, const int number_of_players)
{
  int i;
  int zero_count = 0;
  int one_count  = 0;
  for (i = 0; i < number_of_players; i++)
  {
    if (players[i].player_decision == 1)
    {
      dbg_printf("Increment 1");
      one_count++;
    }
    else
    {
      dbg_printf("Increment 0");
      zero_count++;
    }
  }
  
  if(one_count > zero_count)
  {
    dbg_printf("Round result is 1");
    return 1;
  }
  else{
    dbg_printf("Round result is 0");
    return 0;
  }
}

/*
 * @brief - Check if a bit is set on a given number
 */
int check_bit(const int number, const int bit)
{
  return number & (1<<bit);
}








