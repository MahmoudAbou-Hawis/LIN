# LIN Protocol Implementation in C++

This repository provides an implementation of the LIN (Local Interconnect Network) protocol using modern C++. The project is designed for embedded systems, featuring modular components for transport, database, and LIN initialization, with support for periodic calls to handle LIN communication timing.

## Features

- **LIN Protocol Stack**: Supports LIN frame sending and receiving.
- **Database and Transport Abstractions**: Modular design with separate adapters for database and transport, allowing flexibility and integration.
- **Embedded-Focused**: Built for embedded systems without dynamic memory allocation, making it ideal for low-resource environments.

## Getting Started

### Prerequisites

- **C++17**

### Cloning the Repository

Clone this repository to your local machine:

```C++
git clone https://github.com/MahmoudAbou-Hawis/LIN.git
cd LIN
```

### Example Code

The following example demonstrates initializing the LIN Master stack with an MSP432 microcontroller, configuring the UART transport, database adapter, and transport adapter, then running LIN protocol communications in a periodic loop.

#### Example Code in `main.cpp`

```C++
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
    // Set system clock to 120 MHz for the MSP432
    uint32_t g_ui32SysClock = MAP_SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                                      SYSCTL_OSC_MAIN |
                                                      SYSCTL_USE_PLL |
                                                      SYSCTL_CFG_VCO_480), 120000000);

    UartTransport uartTransport;          // Initialize UART transport layer
    LINDataBase linDatabase;              // Initialize LIN database
    TransportAdapter transportAdapter(&uartTransport);
    DbAdabter dbAdapter(&linDatabase);
    Lin lin(&dbAdapter, &transportAdapter); // Initialize LIN with database and transport adapters

    lin.start();  // Start LIN protocol

    uint32_t iteration = 0;

    while(1) {
        // Delay to maintain a periodic loop
        SysCtlDelay(g_ui32SysClock / (1000 * 3));
        lin.run(++iteration);  // Run LIN operations periodically
    }

    return 0;
}
```

### Explanation of Components

- **`UartTransport`**: Manages UART-based LIN communication.
- **`LINDataBase`**: Stores LIN message IDs and data, acting as a storage layer.
- **`TransportAdapter`**: Interfaces with the UART transport layer to handle message sending and receiving.
- **`DbAdapter`**: Connects the LIN protocol stack with the LIN database.
- **`Lin`**: Main LIN protocol class that manages protocol operations using the database and transport adapters.

### Running the Example

1. **Compile the Code**:
   - Use your embedded toolchain (such as TI’s Code Composer Studio for MSP432) to compile and upload the code to your MSP432 device.
2. **Run on MSP432**:
   - After uploading, the program initializes the LIN stack, then enters a loop where it periodically calls `lin.run()`, handling LIN message scheduling and transmission.

### Configuration

Modify the `config.h` file to set up parameters for baud rate, frame timings, and error handling to suit your specific LIN network requirements.