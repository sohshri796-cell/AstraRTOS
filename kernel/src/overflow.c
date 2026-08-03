#include "overflow.h"
#include "mpu.h"

void apply_guard_region(os_tcb_t* task){
    
    os_mpu_configure_region(1, (uint32_t)(task->stack_base), 0x04, 0, 1);
}