#include "queue.h"
#include "tile_game.h"
bool compare_states(struct game_state current)
{
    //check if equal to answer?
        int valid = 1;
        for (int i = 0; i < 4;i++)
        {
            for (int j = 0; j < 4;j++)
            {
                if(valid == current.tiles[i][j])
                {
                    valid++;
                }
                if (valid == 16)
                {
                    return (true);
                }
            }
        }
        return(false);
}
// use list and serialize to queue, USE DEFINED SERIALIZE FUNC
void enqueue(struct queue *q, struct game_state state) 
{
    insert_at_tail(&q->data, (serialize(state)));
}

//use list and deserialize to dequeue,  USE DEFINED DESERIALIZE FUNC
struct game_state dequeue(struct queue *q)
{
    return (deserialize(remove_from_head(&q->data)));
}

//use queue to implement a BFS to determine shortest number of moves
int number_of_moves(struct game_state start) 
{
    struct queue q;
    q.data.head = NULL;
    enqueue(&q, start);
    
    while(q.data.head != NULL)
    {
        struct game_state current = dequeue(&q);
        if(current.empty_row != 0)
        {
            struct game_state new = current;
            move_down(&new);
            enqueue(&q, new);
        }
        if (current.empty_row != 3)
        {
            struct game_state new = current;
            move_up(&new);
            enqueue(&q, new);
        }
        if(current.empty_col != 0)
        {
            struct game_state new = current;
            move_right(&new);
            enqueue(&q, new);
        }
        if(current.empty_col != 3)
        {
            struct game_state new = current;
            move_left(&new);
            enqueue(&q, new);
        }
        if (compare_states(current) == true)
        {
            free_list(q.data);
            return (current.num_steps);
        }
    }
    return -1;
}
