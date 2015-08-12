#include <stdint.h>
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
  uint8_t* player_history;
}player_t;

/*
 * @brief - Play a round. This will take the players and their attributes, 
 *          and the current history, and get the players decisions.
 * @param players - Pointer to the list of players.
 * 
 * @param number_of_players - The number of players in the list.
 * 
 * @param history - The current history - this will be updated.
 */
void play_round(player_t* players, const int number_of_players, uint8_t* history, const int num_elements);


/*
 * @brief - Simple helper function to help setup players. 
 *          By default the player's decision will be set to 0.
 *
 * @param player  - The player we want to setup
 *
 * @param player_id - The ID we'll give to the player.
 *
 * @param startegy  - The starting strategy we'll give the player.
 */
void player_setup(player_t* player, const int id, const int strategy, const int history_size);

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
void set_player_decision(player_t* player, const int history);

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

/*
 * @brief - Helper function to help us update the history
 *
 * @param history   - The history to update.
 *
 * @param new_value - Value we'll add on to the end of the number.
 */
void update_history(uint8_t* history, const int num_elements, const int new_value);

/*
 * @brief - A function to return the bit representation of data.
 *
 * @param ptr - Pointer to the data.
 *
 * @param size  - Size of data.
 * 
 * @return    Bit representation of data.
 *
 * @example - get_bits(int i = 4, sizeof(int));
 */
char* get_bits(void const * const ptr, size_t const size);


