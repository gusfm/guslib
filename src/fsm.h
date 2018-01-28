#ifndef GUSLIB_FSM_H
#define GUSLIB_FSM_H

#include <stddef.h>

typedef unsigned int fsm_state_t;
typedef unsigned int fsm_event_t;
typedef void (*fsm_action_cb_t)(void *data);
typedef void (*fsm_no_transition_cb_t)(fsm_event_t event, void *data,
                                       fsm_state_t state);

typedef struct {
    fsm_state_t src;
    fsm_event_t event;
    fsm_state_t dest;
} fsm_transition_t;

typedef struct {
    fsm_state_t state;
    fsm_action_cb_t on_entry;
    fsm_action_cb_t on_exit;
} fsm_action_t;

typedef struct {
    fsm_state_t current;
    fsm_transition_t *transition_table;
    size_t num_transitions;
    fsm_action_t *action_table;
    fsm_no_transition_cb_t no_transition;
    void *data;
} fsm_t;

void fsm_start(fsm_t *fsm);
void fsm_process_event(fsm_t *fsm, fsm_event_t event);

#endif /* GUSLIB_FSM_H */
