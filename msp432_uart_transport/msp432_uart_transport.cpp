#include "msp432_uart_transport.hpp"
extern "C" {
#include "ti/devices/msp432e4/driverlib/driverlib.h"
}
#include "Transport-api/TransportErrorCode.hpp"
#include <stdint.h>
#include <stdbool.h>
#include "LinConf.h"



CallBacks callbacks[3];

uint8_t * mData{nullptr};
uint8_t mLen{0};
uint8_t idx{0};
uint8_t * mByte{nullptr};


#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif

uint32_t g_ui32SysClock ;
TransportErrorCode UartTransport::Init()
{

    g_ui32SysClock = MAP_SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                             SYSCTL_OSC_MAIN |
                                             SYSCTL_USE_PLL |
                                             SYSCTL_CFG_VCO_480), 120000000);
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    MAP_IntMasterEnable();

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    MAP_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);


    MAP_UARTConfigSetExpClk(UART0_BASE, g_ui32SysClock, 115200,
                            (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                             UART_CONFIG_PAR_NONE));

    MAP_IntEnable(INT_UART0);
    MAP_UARTIntDisable(UART0_BASE, UART_INT_RX | UART_INT_RT);
    MAP_UARTIntDisable(UART0_BASE, UART_INT_TX);
#if NODE_TYPE == SLAVE
    MAP_UARTIntEnable(UART0_BASE,UART_INT_BE);
#endif
    return TransportErrorCode::Success;
}
TransportErrorCode UartTransport::send(uint8_t * data, uint8_t len)
{
    MAP_UARTIntDisable(UART0_BASE, UART_INT_RX | UART_INT_RT);
    for(uint8_t cnt = 0 ; cnt < len ; cnt++)    {
            MAP_UARTCharPutNonBlocking(UART0_BASE,data[cnt]);
   }
    if(callbacks[TX_IDX].CB != nullptr)
        callbacks[TX_IDX].CB(callbacks[TX_IDX].args);
   return TransportErrorCode::Success;
}

TransportErrorCode UartTransport::receive(uint8_t * data , uint8_t len)
{
    MAP_UARTIntDisable(UART0_BASE, UART_INT_TX);
    UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT);
    while(MAP_UARTCharsAvail(UART0_BASE))
    {
        MAP_UARTCharGetNonBlocking(UART0_BASE);
    }
    mData = data;
    mLen  = len;
    idx = 0;
    return TransportErrorCode::Success;

}
TransportErrorCode UartTransport::SendBreak ()
{
     MAP_UARTBreakCtl(UART0_BASE,true);
     SysCtlDelay(g_ui32SysClock / (1300 * 3));
    MAP_UARTBreakCtl(UART0_BASE,false);
    return TransportErrorCode::Success;
}
TransportErrorCode UartTransport::sleep() {

    return TransportErrorCode::Success;
}
TransportErrorCode UartTransport::RegisterRxCallBack(void (*CB)(void *),void *arg)    {
    callbacks[RX_IDX].CB = CB;
    callbacks[RX_IDX].args = arg;
    return TransportErrorCode::Success;

}
TransportErrorCode UartTransport::RegisterTxCallBack(void (*CB)(void *),void *arg)    {
    callbacks[TX_IDX].CB = CB;
    callbacks[TX_IDX].args = arg;
    return TransportErrorCode::Success;
}
TransportErrorCode UartTransport::RegisterBreakCallBack(void (*CB)(void *),void *arg) {
    callbacks[BREAK_IDX].CB = CB;
    callbacks[BREAK_IDX].args = arg;
    return TransportErrorCode::Success;

}
TransportErrorCode UartTransport::UnRegisterRxCallBack()
{
    callbacks[RX_IDX].CB = nullptr;
    callbacks[RX_IDX].args = nullptr;
    return TransportErrorCode::Success;
}
TransportErrorCode UartTransport::UnRegisterTxCallBack()    {
    callbacks[TX_IDX].CB = nullptr;
    callbacks[TX_IDX].args = nullptr;
    return TransportErrorCode::Success;

}
TransportErrorCode UartTransport::UnRegisterBreakCallBack() {
    callbacks[BREAK_IDX].CB = nullptr;
    callbacks[BREAK_IDX].args = nullptr;
    return TransportErrorCode::Success;
}

void UartTransport::disableRx()
{
    MAP_UARTIntDisable(UART0_BASE, UART_INT_RX | UART_INT_RT);
}
void UartTransport::disableTx()
{
    MAP_UARTIntDisable(UART0_BASE, UART_INT_TX);
}

void UartTransport::receiveByte(uint8_t * byte)
{
    mByte = byte;
    mLen++;
}

void UartTransport::sendByte(uint8_t  data)
{
    MAP_UARTCharPutNonBlocking(UART0_BASE,data);
}


extern "C" void UART0_IRQHandler(void)
{
    uint32_t ui32Status;


    ui32Status = MAP_UARTIntStatus(UART0_BASE, true);


    MAP_UARTIntClear(UART0_BASE, ui32Status);

     if((ui32Status & (uint32_t)UART_INT_BE) == ((uint32_t)UART_INT_BE))
     {
         callbacks[BREAK_IDX].CB(callbacks[BREAK_IDX].args);
     }
     else
     {
         while(MAP_UARTCharsAvail(UART0_BASE))
         {
             if(mByte != nullptr && idx == mLen -1)
             {
                 *mByte = MAP_UARTCharGetNonBlocking(UART0_BASE);
                 idx++;
                 mByte = nullptr;
             }else
             {
                 uint8_t ch =  MAP_UARTCharGetNonBlocking(UART0_BASE);
                 mData[idx++] = ch;
             }
              if(idx == mLen)
              {
                  idx = 0;
                  callbacks[RX_IDX].CB(callbacks[RX_IDX].args);
              }
         }
     }



}




