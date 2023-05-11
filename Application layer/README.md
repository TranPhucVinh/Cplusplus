GET request to ``example.com`` by TCP socket, using [std::string](../Data%20structure/String/README.md#stdstring) to form HTTP request: [get_data.cpp](get_data.cpp)

Telemetry data to ThingsBoard: [thingsboard_telemetry.cpp](thingsboard_telemetry.cpp)

# Telemetry to ThingsBoard based on Internet status

* Thread ``monitor_internet_status()`` to monitor Internet status.
* If internet is connected, thread ``telemetry()`` send HTTP request for ``number`` value to ThingsBoard for an interval of time. If HTTP request is sent successfully and the HTTP responsed is received successfully, ``number`` is increased by ``1``
* If Internet is not connected, ``monitor_internet_status()`` suspends ``telemetry()``. ``number`` is kept unchanged at this current value.
* If Internet is recovered after losing connection, ``telemetry()`` will then keep sending HTTP request with the ``number`` value when losing Internet connection value before to ThingsBoard

Program: [thingsboard_telemetry_suspend_resume_by_internet_status.cpp](thingsboard_telemetry_suspend_resume_by_internet_status.cpp)