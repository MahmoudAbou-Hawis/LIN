#include "msp432_uart_transport/msp432_uart_transport.hpp"
#include "Adapters/dbadabter.hpp"
#include "Adapters/transportadabter.hpp"
#include "storage/db/LINDataBase.hpp"
#include "initializer/Lin.hpp"
extern "C" {
#include "ti/devices/msp432e4/driverlib/driverlib.h"
}

int main()
{
   uint32_t g_ui32SysClock = MAP_SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                             SYSCTL_OSC_MAIN |
                                             SYSCTL_USE_PLL |
                                             SYSCTL_CFG_VCO_480), 120000000);
    UartTransport x;
    LINDataBase dabase;
    TransportAdapter tb(&x);
    DbAdabter db(&dabase);
    Lin lin(&db,&tb);

    lin.start();

    uint32_t i = 0;

    while(1){


        SysCtlDelay(g_ui32SysClock / (1000 * 3));
        lin.run(++i);

    }


    return 0;
}
