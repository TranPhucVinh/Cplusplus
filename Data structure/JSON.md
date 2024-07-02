# Create a JSON string from map

```cpp
#include <iostream>
#include <map>

using namespace std;

string map_to_json(map<string, int> json) {
    map<string, int>::iterator el = json.begin();
    string json_str = "{";

    while (el != json.end()) {
        if (el != json.begin()) {
           json_str.append(",");
        }
        json_str.append("\"");
        json_str.append(el->first);
        json_str.append("\":");
        json_str.append(to_string(el->second));
        el++;
    }
    json_str.append("}");
    return json_str;
}

int main() {
    map<string, int> json;
    json["field_1"] = 123;
    json["field_2"] = 456;
    json["field_3"] = 789;
    string json_str = map_to_json(json);
    
	cout << json_str << endl;
    return 0;
}
```
For [thingsboard_telemetry.cpp](thingsboard_telemetry.cpp), with JSON formed by map:
```cpp

void telemetry() {
    // Other parts are same with thingsboard_telemetry.cpp
    while (1){
        // Other parts are same with thingsboard_telemetry.cpp
        
        map<string, int> json;
        json["unix_tcp_client"] = send_number;

        send_json = map_to_json(json);
        
        string http_request = form_http_request(send_json);

        // Other parts are same with thingsboard_telemetry.cpp

        if (wsz == http_request.size()) send_number += 1;
        else cout << "Fail to send HTTP request\n" << endl;
        sleep(1);
    }
    // Other parts are same with thingsboard_telemetry.cpp
}
```