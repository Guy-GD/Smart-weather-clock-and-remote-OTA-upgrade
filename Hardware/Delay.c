#include "stm32f10x.h"

/**
  * @brief  微秒级延时 (基于 TIM2)
  * @param  xus 延时时长，范围：0~4294967295 (受限于32位计数器)
  * @retval 无
  * @note   使用 TIM2 避免与 FreeRTOS SysTick 冲突
  */
void Delay_us(uint32_t xus)
{
    // 1. 使能 TIM2 时钟
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    
    // 2. 配置 TIM2
    // PSC: 预分频系数。72MHz / (71+1) = 1MHz -> 每个计数周期 1us
    TIM2->PSC = 71; 
    
    // ARR: 自动重装载值。设置为最大值，防止提前溢出
    TIM2->ARR = (uint32_t)0xFFFF; 
    
    // CNT: 清空当前计数值
    TIM2->CNT = 0;
    
    // CR1: 启动定时器 (CEN=1), 向上计数
    TIM2->CR1 |= TIM_CR1_CEN;
    
    // 3. 等待直到计数值达到 xus 适用于短延时
    while (TIM2->CNT < xus);
    
    // 4. 停止定时器并清除标志
    TIM2->CR1 &= ~TIM_CR1_CEN;
    
    // 可选：禁用 TIM2 时钟以省电，但在频繁调用时建议保持开启以减少开销
    // RCC->APB1ENR &= ~RCC_APB1ENR_TIM2EN; 
}

/**
  * @brief  毫秒级延时
  * @param  xms 延时时长
  * @retval 无
  * @note   在 FreeRTOS 环境中，建议任务中使用 vTaskDelay 替代此函数
  */
void Delay_ms(uint32_t xms)
{
    while(xms--)
    {
        Delay_us(1000);
    }
}
 
/**
  * @brief  秒级延时
  * @param  xs 延时时长
  * @retval 无
  */
void Delay_s(uint32_t xs)
{
    while(xs--)
    {
        Delay_ms(1000);
    }
} 
