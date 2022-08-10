/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

void PressedHandler ()
{   
    NVIC_ClearPendingIRQ(Pressed_IRQ_cfg.intrSrc);
}
int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    /* Enable CM4.  CY_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
    Cy_SysEnableCM4(CY_CORTEX_M4_APPL_ADDR); 

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    Cy_SysInt_Init(&Pressed_IRQ_cfg, PressedHandler);
    NVIC_EnableIRQ(Pressed_IRQ_cfg.intrSrc);

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
