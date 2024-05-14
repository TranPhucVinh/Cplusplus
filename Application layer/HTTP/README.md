# HTTP client
GET request to ``example.com`` by TCP socket, using [std::string](../Data%20structure/String/README.md#stdstring) to form HTTP request: [get_data.cpp](get_data.cpp).

Telemetry data to ThingsBoard: [thingsboard_telemetry.cpp](thingsboard_telemetry.cpp). While sending HTTP request or reading HTTP respose and Internet gets disconnected, program stops immediately (as ``socket_connect(HOST, PORT)``, which includes ``exit()``, is inside ``while(1)`` loop)

## Telemetry to ThingsBoard based on Internet status

* Thread ``monitor_internet_status()`` to monitor Internet status.
* If internet is connected, thread ``telemetry()`` send HTTP request for ``number`` value to ThingsBoard for an interval of time. If HTTP request is sent successfully and the HTTP responsed is received successfully, ``number`` is increased by ``1``
* If Internet is not connected, ``monitor_internet_status()`` suspends ``telemetry()``. ``number`` is kept unchanged at this current value.
* If Internet is recovered after losing connection, ``telemetry()`` will then keep sending HTTP request with the ``number`` value when losing Internet connection value before to ThingsBoard

Program: [thingsboard_telemetry_suspend_resume_by_internet_status.cpp](thingsboard_telemetry_suspend_resume_by_internet_status.cpp)
# HTTP server

**Multithread HTTP server built on TCP API, with OOP structure**

Handle GET request:
* Return HTML as the content of file ``index.html`` for route ``/``. If file ``index.html`` not existed, return text/plain ``File index.html not existed``.
* For routing with unhandled route, return ``Not found %s``
* [HTTP server](multithread_http_server.cpp) starts when there is no HTTP client connected and sending HTTP request, HTTP receiver prints out **Waiting for a TCP sender to connect ...** until a HTTP client is connected.
* Read the whole HTTP POST request and print out
* Multithread, with POSIX thread created by pthread, to handle any newly connected HTTP client
* **Count total numbers of connected TCP client** and **detect disconnected event**

**Program**: [multithread_http_server.cpp](multithread_http_server.cpp)

