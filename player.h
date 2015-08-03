#include <stdlib.h>

/* 
 * All the properties that the players will have
 *    - ID
 *    - Strategy
 *    - Decision for a round
 */
typedef struct {
  int player_id;
  int player_strategy;
  int player_decision;
}player_t;

/*
 * @brief - Check if a bit is set on a given number
 *
 * @param - The number we want to check
 *
 * @param - The bit we want to check.
 *          The left-most bit is bit 0, etc.
 * 
 * @return  0 if the bit isn't set, otherwise a non-zero number.
 */
int check_bit(const int number, const int bit);

/*
 * @brief - Get the players decision based on a given history.
 *
 * @param player  - The player whose decision we want to get
 *
 * @param history - The histroy the player's decision will be based on
 *
 * @return  The player's decision - 1 or 0.
 */
int get_player_decision(player_t player, const int history);

/*
 * @brief - Get the round result based on an array of players' decisions.
 *
 * @param players - A pointer to a list of players.
 *
 * @param number_of_players - The number of players in the list.
 *
 * @return  The round result - 1 or 0
 */
int get_round_result(player_t* players, const int number_of_players);
