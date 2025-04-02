#include "queue.h"
#include "tile_game.h"

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
    int num = 0;
    struct queue q;
    q.data.head = NULL;
    enqueue(&q, start);
    
    //check if equal to answer?
    while(q.data.head != NULL)
    {
        struct game_state current = dequeue(&q);
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
                    break;
                }
            }
        }
        if(current.empty_row != 0)
        {
            move_up(&current);
            enqueue(&q, current);
            num++;
        }
        if (current.empty_row != 3)
        {
            move_down(&current);
            enqueue(&q, current);
            num++;
        }
        if(current.empty_col != 0)
        {
            move_left(&current);
            enqueue(&q, current);
            num++;
        }
        if(current.empty_col != 3)
        {
            move_right(&current);
            enqueue(&q, current);
            num++;
        }
    
    }
    free_list(q.data);
    return (num);
}
