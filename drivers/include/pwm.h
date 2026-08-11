#ifndef PWM_H
#define PWM_H

#include <stdint.h>

#define TIM1_BASE 0x40010000
#define TIM2_BASE 0x40000000
#define TIM3_BASE 0x40000400
#define TIM4_BASE 0x40000800
#define TIM5_BASE 0x40000C00
#define TIM8_BASE 0x40010400
#define TIM9_BASE 0x40014000
#define TIM10_BASE 0x40014400
#define TIM11_BASE 0x40014800
#define TIM12_BASE 0x40001800
#define TIM13_BASE 0x40001C00
#define TIM14_BASE 0x40002000

#define CH1 1
#define CH2 2
#define CH3 3
#define CH4 4

#define TIM_CR1(base) (*(volatile uint32_t *)((base) + 0x00))
#define TIM_CNT(base) (*(volatile uint32_t *)((base) + 0x24))
#define TIM_ARR(base) (*(volatile uint32_t *)((base) + 0x2C))
#define TIM_PSC(base) (*(volatile uint32_t *)((base) + 0x28))
#define TIM_EGR(base) (*(volatile uint32_t *)((base) + 0x14))
#define TIM_CCR1(base) (*(volatile uint32_t *)((base) + 0x34))
#define TIM_CCR2(base) (*(volatile uint32_t *)((base) + 0x38))
#define TIM_CCR3(base) (*(volatile uint32_t *)((base) + 0x3C))
#define TIM_CCR4(base) (*(volatile uint32_t *)((base) + 0x40))
#define TIM_CCMR1(base) (*(volatile uint32_t *)((base) + 0x18))
#define TIM_CCMR2(base) (*(volatile uint32_t *)((base) + 0x1C))
#define TIM_CCER(base) (*(volatile uint32_t *)((base) + 0x20))
#define TIM_BDTR(base) (*(volatile uint32_t *)((base) + 0x44))

typedef struct pwm_config_t {
    uint8_t channel;
    uint32_t timer;
    uint32_t port;
    uint32_t pin;
    uint32_t freq;
} pwm_config_t;

void pwm_set_af(pwm_config_t *config);
void pwm_configure_channel(uint32_t channel, uint32_t timer);
void pwm_set_compare_value(uint32_t compare_value, uint32_t channel, uint32_t timer);
void pwm_enable_timer(uint32_t timer);
void pwm_config_timer(uint32_t timer, uint32_t freq);
void os_pwm_init(pwm_config_t *config);
void os_pwm_set_duty(pwm_config_t *config, uint8_t duty);
void os_pwm_set_pulse_us(pwm_config_t *config, uint32_t pulse_us);
#endif
