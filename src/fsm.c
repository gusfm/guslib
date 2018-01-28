#include "fsm.h"

static fsm_state_t fsm_get_next(fsm_t *fsm, fsm_event_t event)
{
    for (size_t i = 0; i < fsm->num_transitions; ++i) {
        fsm_transition_t *trans = &fsm->transition_table[i];
        if (trans->src == fsm->current && trans->event == event)
            return trans->dest;
    }
    return fsm->current;
}

static void fsm_action_exec(fsm_action_cb_t action, void *data)
{
    if (action)
        action(data);
}

void fsm_process_event(fsm_t *fsm, fsm_event_t event)
{
    fsm_state_t current = fsm->current;
    fsm_state_t next = fsm_get_next(fsm, event);
    if (current == next) {
        if (fsm->no_transition)
            fsm->no_transition(event, fsm->data, current);
    } else {
        fsm_action_exec(fsm->action_table[current].on_exit, fsm->data);
        fsm_action_exec(fsm->action_table[next].on_entry, fsm->data);
        fsm->current = next;
    }
}

void fsm_start(fsm_t *fsm)
{
    fsm_action_exec(fsm->action_table[fsm->current].on_entry, fsm->data);
}
