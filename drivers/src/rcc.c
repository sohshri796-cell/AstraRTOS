#include "rcc.h"
#include "pwm.h"

void rcc_enable_gpio(uint8_t port) {
    if(port <= 10) {
        RCC_AHB1ENR |= (1 << port); // Enables particular GPIO family
    }
}

void rcc_disable_gpio(uint8_t port) {
    if(port <= 10) {
        RCC_AHB1ENR &= ~(1 << port); // Disables particular GPIO family
    }
}

void rcc_enable_uart(uint8_t uart) {
    switch(uart) {
    case USART1_EN:
        RCC_APB2ENR |= (1 << 4);
        break;
    case USART2_EN:
        RCC_APB1ENR |= (1 << 17);
        break;
    case USART3_EN:
        RCC_APB1ENR |= (1 << 18);
        break;
    }
}

void rcc_disable_uart(uint8_t uart) {
    switch(uart) {
    case USART1_EN:
        RCC_APB2ENR &= ~(1 << 4);
        break;
    case USART2_EN:
        RCC_APB1ENR &= ~(1 << 17);
        break;
    case USART3_EN:
        RCC_APB1ENR &= ~(1 << 18);
        break;
    }
}

void rcc_enable_timer(uint32_t timer) {
    switch(timer) {
    case TIM1_BASE:
        RCC_APB2ENR |= (1 << 0);
        break;
    case TIM2_BASE:
        RCC_APB1ENR |= (1 << 0);
        break;
    case TIM3_BASE:
        RCC_APB1ENR |= (1 << 1);
        break;
    case TIM4_BASE:
        RCC_APB1ENR |= (1 << 2);
        break;
    case TIM5_BASE:
        RCC_APB1ENR |= (1 << 3);
        break;
    case TIM8_BASE:
        RCC_APB2ENR |= (1 << 1);
        break;
    case TIM9_BASE:
        RCC_APB2ENR |= (1 << 16);
        break;
    case TIM10_BASE:
        RCC_APB2ENR |= (1 << 17);
        break;
    case TIM11_BASE:
        RCC_APB2ENR |= (1 << 18);
        break;
    case TIM12_BASE:
        RCC_APB1ENR |= (1 << 6);
        break;
    case TIM13_BASE:
        RCC_APB1ENR |= (1 << 7);
        break;
    case TIM14_BASE:
        RCC_APB1ENR |= (1 << 8);
        break;
    default:
        break;
    }
}
