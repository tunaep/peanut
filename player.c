#include <stdio.h>
#include <math.h>
#include "player.h"
#include "logger.h"
#include <stdint.h>

int logging = 0;

/*
 * @brief - Play a round. This will take the players and their attributes, 
 *          and the current history, and get the players decisions.
 */
void play_round(player_t* players, const int number_of_players, uint8_t *history, const int num_elements)
{
  // First set the players decision based on a given history
  if (players)
  {
    int i;
    for (i = 0; i < number_of_players; i++)
    {
      set_player_decision(&players[i], *history);
      update_history(players[i].player_history, num_elements, players[i].player_decision);
    }
  }

  // Then get the tally of the decisions
  int round_result = get_round_result(players, number_of_players);
  //dbg_printf("The round result was %i\n", round_result);

  // Finally, update the current history with our result.
  update_history(history, num_elements, round_result);
}

/*
 * @brief - Simple helper function to help setup players. 
 *          By default the player's decision will be set to 0.
 */
void player_setup(player_t* player, const int id, const int strategy, const int history_size)
{
  if(player)
  {
    player->player_id       = id;
    player->player_strategy = strategy;
    player->player_decision = 0;
    player->player_history  = calloc(1, history_size);
  }
  else
  {
    dbg_printf("player is NULL!");
  }
}

/*
 * @brief - Get the players decision based on a given history.
 */
void set_player_decision(player_t* player, const int history)
{
  dbg_printf("Player strategy: %i", player->player_strategy);
  dbg_printf("History: %i", history);

  if(check_bit(player->player_strategy, history))
  {
    dbg_printf("Returning 1");
    player->player_decision = 1;
  }
  else
  {
    dbg_printf("Returning 0");
    player->player_decision = 0;
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
    dbg_printf("Player %i picked %i", players[i].player_id, players[i].player_decision);
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
 
  return one_count < zero_count ? 1 : 0;
}

/*
 * @brief - Check if a bit is set on a given number
 */
int check_bit(const int number, const int bit)
{
  return number & (1<<bit);
}


/*
 * @brief - A function to return the bit representation of data.
 */
char* get_bits(void const * const ptr, size_t const size)
{
  int bits = (size*8);
  char* buffer = calloc(1, bits + 1);
  char* write_ptr = buffer;
  
  unsigned char *b = (unsigned char*) ptr;
  unsigned char byte;
  int i, j;

  for (i=size-1;i>=0;i--)
  {
      for (j=7;j>=0;j--)
      {
          byte = b[i] & (1<<j);
          byte >>= j;
          sprintf(write_ptr, "%u", byte);
          ++write_ptr;
      }
  }
  return buffer;
}

void update_history(uint8_t* history, const int num_elements, const int new_value)
{
  int x;
  for (x = num_elements - 1; x > 0; x--)
  {
    history[x] <<= 1;
    history[x-1] & (1<<7) ? history[x]++ : 0;
  }
  history[0] <<= 1;
  history[0] += new_value;
}
