# Minitalk
Minitalk is a simple client-server communication program that utilizes a custom communication protocol to transmit data between the client and server processes using binary signals.

## Installation
To compile the Minitalk program, follow these steps:

1. Clone the repository:

```
git clone https://github.com/DimiOui/42-minitalk.git
```

2. Navigate to the project directory:

```
cd minitalk
```

3. Build the server and client executables:
```
make
```

## Usage
### Server
The server program receives and displays messages sent by the client. To run the server, use the following command:
```
./server
```
The server will display its process ID (PID) on startup.

### Client
The client program sends messages to the server. To send a message, use the following command:

```
./client [SERVER_PID] [MESSAGE]
```
Replace `[SERVER_PID]` with the PID of the server process, which is displayed when the server starts. Replace `[MESSAGE]` with the desired message to be sent.

For example, to send the message "Hello" to a server with PID 12345, use the following command:
```
./client 12345 Hello
```

## Protocol
Minitalk uses a simple protocol to transmit data between the client and server processes. The communication is performed character by character, with each character encoded as a series of binary signals.

The server displays each received character as it receives the corresponding binary signals.
The server sends an acknowledgement signal back to the client after successfully receiving a complete message.

<details>
  <summary>Protocol Overview</summary>

  #### Overview
The Minitalk protocol is a simple communication protocol that transmits data character by character using binary signals. It utilizes two signals: `SIGUSR1` and `SIGUSR2`, to represent binary values `0` and `1`, respectively.

The server program is responsible for receiving and processing the messages, while the client program sends the messages to the server.

### Server Implementation
In the `server.c` file, the server program sets up a signal handler `my_handler_to_char` to receive and process the binary signals sent by the client.

```c
static void my_handler_to_char(int signum, siginfo_t *siginfo, void *context)
{
    // ...
}
```
Inside the signal handler, the received binary signals are interpreted to reconstruct characters. Each character is accumulated bit by bit until a complete character is received.

```c
static void my_handler_to_char(int signum, siginfo_t *siginfo, void *context)
{
    // ...

    if (signum == SIGUSR1)
        bit = 0;
    else
        bit = 1;

    g_char.c += bit << g_char.bits;
    g_char.bits--;

    if (g_char.bits < 0)
    {
        // A complete character is received
        // Process the character or save it for further use
        // Reset the bit and bits count for the next character
    }

    // Acknowledge the received signal by sending SIGUSR1 back to the client
    kill_to_client(SIGUSR1);
}
```
Once a complete character is received, it can be processed or saved for further use. In the provided code, the server calls the `received_string` function, which displays the received string and sends a `SIGUSR2` signal back to the client to acknowledge successful reception.

```c
static char *received_string(char *str)
{
    // Display or process the received string
    // ...

    // Free the previous string and return NULL
    free(g_char.str);
    return (NULL);
}
```

### Client Implementation
In the `client.c` file, the client program is responsible for converting the input message into binary signals and sending them to the server.

The `my_handler_to_binary` function takes care of converting the message into binary signals and sending them to the server process.

```c
static void my_handler_to_binary(pid_t pid, char *str)
{
    // ...

    while (str[i])
    {
        // Convert each character into binary signals
        shift = 7;
        while (shift >= 0)
        {
            if ((str[i] & (1 << shift)))
                kill_to_server(SIGUSR2, pid);
            else
                kill_to_server(SIGUSR1, pid);

            // Wait a short period of time between each signal transmission
            usleep(1000);
            shift--;
        }
        i++;
    }

    // Send a series of null signals to signify the end of the message
    kill_null(pid);
}
```
The `kill_to_server` function is responsible for sending the `SIGUSR1` and `SIGUSR2` signals to the server process.

```c
static void kill_to_server(int signum, int pid)
{
    if (kill(pid, signum) == -1)
        error(0);
}
```
The kill_null function sends a series of null signals to signify the end of the message transmission.

```c
static int kill_null(int pid)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		kill_to_server(SIGUSR1, pid);
		usleep(500);
		i++;
	}
	return (1);
}
```

### Protocol Workflow
The Minitalk protocol follows the following workflow:

1. The client program converts the message into binary signals character by character.
2. The client sends the binary signals to the server using the `SIGUSR1` and `SIGUSR2` signals.
3. The server program receives the binary signals and reconstructs the characters.
4. Once a complete character is received, the server processes it or saves it for further use.
5. If a `null` character `(0)` is received, it signifies the end of a message transmission.
6. The server sends an acknowledgement signal (`SIGUSR2`) back to the client after successfully receiving a complete message.
7. The client program waits for the acknowledgement signal and exits after receiving it.
<br/>
The communication between the client and server is performed through the transmission of binary signals, allowing the exchange of messages in a simple and efficient manner.

</details>

## Implementation Details
The Minitalk program consists of the following source files:

- `server.c`: Implements the server functionality, including signal handling and message processing.
- `client.c`: Implements the client functionality, including sending messages to the server.
- `utils.c`: Contains utility functions used by the server and client programs.
- `minitalk.h`: Defines the data structures and function prototypes used in the program.
