epoll_http_server:
	g++ main.cpp http_server.cpp

http_server_lib:
	g++ -c http_server.cpp
	ar r libhttp_server.a http_server.o
	rm http_server.o
