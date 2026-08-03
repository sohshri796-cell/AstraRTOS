#include "mpu.h"

void os_mpu_init(){
    SHCSR |= (1 << 16); //enable Mem manage fault
    __asm volatile ("dmb"); //data memory barrier
    MPU_CTRL = 0; //disable the MPU

    MPU_CTRL = (1 << 0)| //enable the MPU
                (1 << 2); //enable PRIVDEFENA mask
    __asm volatile ("dsb"); //data synchronisation barrier
    __asm volatile ("isb"); //instruction synchronisation barrier
}

void os_mpu_configure_region(uint8_t region_num, uint32_t stack_base, uint8_t encoded_region_size, uint8_t access_perm, uint8_t exec_never){
    MPU_RBAR = (stack_base) | //to mask off the lower 5 bits of the address
               (1 << 4) | //region number valid
               (uint32_t)region_num;

    MPU_RASR = (1 << 0) | //enable the region
                ((uint32_t)encoded_region_size << 1) | //log2(size in bytes) - 1
                ((uint32_t)access_perm << 24) | //defines the access permissions 
                ((uint32_t)exec_never << 28);
}
