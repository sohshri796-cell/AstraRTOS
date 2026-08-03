#ifndef OVERFLOW_H
#define OVERFLOW_H

#include<stdint.h>
#include "task.h"

void apply_guard_region(os_tcb_t* task);

#endif