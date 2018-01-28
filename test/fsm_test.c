#include <stdlib.h>
#include "fsm.h"
#include "ut.h"

static void unlocked_entry(void *data)
{
    int *i = data;
    (*i)++;
}

static void unlocked_exit(void *data)
{
    int *i = data;
    (*i)++;
}

static void locked_entry(void *data)
{
    int *i = data;
    (*i)++;
}

static void locked_exit(void *data)
{
    int *i = data;
    (*i)++;
}

static void no_transition(fsm_event_t event, void *data, fsm_state_t state)
{
    (void)event;
    (void)state;
    int *i = data;
    (*i)++;
}

/**
 * LOCKED <--> UNLOCKED
 */
enum {
    STATE_UNLOCKED,
    STATE_LOCKED,
};

enum {
    EVENT_LOCK,
    EVENT_UNLOCK,
};

fsm_transition_t transition_table[] = {
    {STATE_UNLOCKED, EVENT_LOCK, STATE_LOCKED},
    {STATE_LOCKED, EVENT_UNLOCK, STATE_UNLOCKED},
};

fsm_action_t action_table[] = {
    {STATE_UNLOCKED, unlocked_entry, unlocked_exit},
    {STATE_LOCKED, locked_entry, locked_exit},
};

static int basic(void)
{
    int data = 0;
    fsm_t fsm = {STATE_UNLOCKED,
                 transition_table,
                 sizeof(transition_table) / sizeof(transition_table[0]),
                 action_table,
                 no_transition,
                 &data};

    /* no transition */
    fsm_start(&fsm);
    ASSERT(fsm.current == STATE_UNLOCKED);
    ASSERT(data == 1);
    fsm_process_event(&fsm, EVENT_UNLOCK);
    ASSERT(fsm.current == STATE_UNLOCKED);
    ASSERT(data == 2);
    /* lock */
    fsm_process_event(&fsm, EVENT_LOCK);
    ASSERT(fsm.current == STATE_LOCKED);
    ASSERT(data == 4);
    /* unlock */
    fsm_process_event(&fsm, EVENT_UNLOCK);
    ASSERT(fsm.current == STATE_UNLOCKED);
    ASSERT(data == 6);
    return 0;
}

void fsm_test(void)
{
    ut_run(basic);
}
