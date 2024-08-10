#include "sha256.h"

using namespace std;

int main() {
    string msg = "";
    SHA256 sha256;
    sha256.hex_digest(msg);
    
    return 0;
}
