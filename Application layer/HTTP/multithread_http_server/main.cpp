#include "http_server.h"

int main(){ 
	HTTP_Server http_server(PORT, REUSEADDR, MAXPENDING);
   	cout << "Waiting for a HTTP client to connect ...\n";
    while (1){
		if (http_server.is_new_http_client_connected() > 0){
			http_server.http_client_thread_handling();
		}
	}
}
