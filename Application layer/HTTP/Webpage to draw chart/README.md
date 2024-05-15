# Features

* A multi-threaded HTTP server receives data as sinewave value sent from HTTP client to draw a sinewave chart on webpage at every 20ms
* HTTP client directly sends sinewave value, as a raw string, to HTTP server on POST request at **every 20ms**

**Result**: The output sinewave is not a perfect sinewave as having some broken point in every cycle.

# Program

* HTTP server: [main.cpp](main.cpp) with [http_server.h](http_server.h) library
* HTML webpage: [index.html](index.html)
* JavaScript: [webpage_script.js](webpage_script.js)
* HTTP client: [http_client.c](http_client.c)
