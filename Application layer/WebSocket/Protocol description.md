The WebSocket frame format defines how data is transmitted between the client and server once the WebSocket connection is established.

```sh
0                   1                   2                   3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-------+-+-------------+-------------------------------+
|F|R|R|R| opcode|M| Payload len |    Extended payload length    |
|I|S|S|S|  (4)  |A|     (7)     |             (16/64)           |
|N|V|V|V|       |S|             |   (if payload len==126/127)   |
| |1|2|3|       |K|             |                               |
+-+-+-+-+-------+-+-------------+ - - - - - - - - - - - - - - - +
|     Extended payload length continued, if payload len == 127  |
+ - - - - - - - - - - - - - - - +-------------------------------+
|                               |Masking-key, if MASK set to 1  |
+-------------------------------+-------------------------------+
| Masking-key (continued)       |          Payload Data         |
+-------------------------------- - - - - - - - - - - - - - - - +
:                     Payload Data continued ...                :
+ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +
|                     Payload Data continued ...                |
+---------------------------------------------------------------+
```

**FIN (1 bit)**:
* This bit indicates if the current frame is the final frame in a message.
* If FIN = 1, it’s the last frame for this message.
* If FIN = 0, more frames will follow.

**RSV1, RSV2, RSV3 (3 bits)**:
* These bits are reserved for extensions and are usually set to 0 unless an extension requires them to be set otherwise.

**Opcode (4 bits)**: This field defines the type of frame being sent. Some common opcodes:
* 0x0: Continuation frame
* 0x1: Text frame
* 0x2: Binary frame
* 0x8: Connection close
* 0x9: Ping
* 0xA: Pong

**MASK (1 bit)**:
* If this bit is ``1``, the frame is masked, meaning it contains a masking key.
* This bit is always ``1`` for frames sent from the client to the server and ``0`` for frames from the server to the client.

**Payload Length (7 bits initially)**: This field represents the length of the payload data. If it’s 126 or 127, it indicates that an extended payload length follows:
* 126: Payload length is represented by the next 16 bits.
* 127: Payload length is represented by the next 64 bits.

**Extended Payload Length (16/64 bits)**:
* Only present if the initial payload length is 126 or 127. So if the initial payload length isn't 126 or 127, the "Extended payload length" field **does not exist at all** in the frame structure. It’s completely omitted.
* If the payload length is 126, a 16-bit unsigned integer follows.
* If the payload length is 127, a 64-bit unsigned integer follows.

**Masking Key** (32 bits, optional):
* This is a 4-byte key used to mask the payload data.
* It’s present only if the MASK bit is 1 (always required from the client to server).
* To XOR each byte of the payload with the 4-byte masking key, follow those steps:
    1. Iterate through each byte of the payload.
    2. For each byte at index ``i`` in the payload, XOR it with the byte at index ``i % 4`` in the masking key. This ensures the 4-byte masking key repeats across the entire payload.

**Payload Data**:
* This is the actual data being transmitted.
* If MASK is 1, the payload is XOR’d with the masking key before it’s sent (client) or after it’s received (server).