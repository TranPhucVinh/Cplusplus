# Single TCP receiver for multiple TCP senders, handled by multithread

## Features
1. Start a TCP sender (from [tcp_multi_sndr_sgl_rx.cpp](tcp_multi_sndr_sgl_rx.cpp)) when the TCP receiver (from [tcp_sgl_rx_multi_sndr.cpp](tcp_sgl_rx_multi_sndr.cpp)) is not started: TCP sender prints out ``TCP receiver hasn't been started or TCP receiver doesn't support connection``
2. [TCP receiver](tcp_sgl_rx_multi_sndr.cpp) starts when there is no TCP sender connected/started, TCP receiver prints out **Waiting for a TCP sender to connect ...** until a TCP sender is connected.
3. [TCP receiver](tcp_sgl_rx_multi_sndr.cpp) only **accepts a specific number of connected TCP senders**, defined by **MAX_CONNECTIONS** in [TCP receiver](tcp_sgl_rx_multi_sndr.cpp) source code
4. **TCP receiver** starts then a TCP sender connects to it, TCP receiver then prints out that TCP sender IP address. Then TCP sender sends data to TCP receiver properly.
When receving message, TCP receiver will print out: ``Message from TCP sender with fd %d: %s``
5. **TCP receiver** is able to count how many **TCP senders** are connected. Every TCP sender to connect TCP receiver will receive a responsed message from it to know whether **MAX_CONNECTIONS** of connected TCP senders have been reached.

If receiving responsed message "Y", TCP receiver has reached **MAX_CONNECTIONS** of connected TCP senders and that newly connected TCP sender is rejected.    

If receiving responsed message "N", TCP receiver hasn't reached **MAX_CONNECTIONS** of connected TCP senders and that newly connected TCP sender is accepted for sending message.

10. If a connected TCP sender is disconnected, there is 1 slot for a new TCP sender.

## Implementation
![](https://github.com/TranPhucVinh/C/blob/master/Environment/Images/tcp_rx_accepts_max_tcp_sndr.png)
**Program**:
* TCP receiver: [tcp_sgl_rx_multi_sndr.cpp](tcp_sgl_rx_multi_sndr.cpp)
* TCP sender: [tcp_multi_sndr_sgl_rx.cpp](tcp_multi_sndr_sgl_rx.cpp)