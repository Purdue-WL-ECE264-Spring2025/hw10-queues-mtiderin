#include "queue.h"
#include "tile_game.h"

// use list and serialize to queue, USE DEFINED SERIALIZE FUNC
void enqueue(struct queue *q, struct game_state state) {}

//use list and deserialize to dequeue,  USE DEFINED DESERIALIZE FUNC
struct game_state dequeue(struct queue *q) { return (struct game_state){0}; }

//use queue to implement a BFS to determine shortest number of moves
int number_of_moves(struct game_state start) { return 0; }
