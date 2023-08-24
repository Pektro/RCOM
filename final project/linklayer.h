#ifndef LINKLAYER
#define LINKLAYER

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct linkLayer{
    char serialPort[50];
    int role; //defines the role of the program: 0==Transmitter, 1=Receiver
    int baudRate;
    int numTries;
    int timeOut;
} linkLayer;

typedef enum {
    Start,
    FlagRCV,
    ARCV,
    CRCV,
    BccOK,
    Data,
    Stop
} stateNames;

typedef struct frameHeader {
    unsigned char A;
    unsigned char C;
} frameHeader;

//ROLE
#define NOT_DEFINED -1
#define TRANSMITTER 0
#define RECEIVER 1

//SIZE of maximum acceptable payload; maximum number of bytes that application layer should send to link layer
#define MAX_PAYLOAD_SIZE 1000

//CONNECTION deafault values
#define BAUDRATE_DEFAULT B38400
#define MAX_RETRANSMISSIONS_DEFAULT 3
#define TIMEOUT_DEFAULT 4
#define _POSIX_SOURCE 1 /* POSIX compliant source */

//MISC
#define FALSE 0
#define TRUE 1

//FLAG
#define FLAG 0x5c
//ADDRESS
#define TX 0x01
#define RX 0x03
//CONTROL
#define SET 0x03
#define UA 0x07
#define DISC 0x0b
#define I_0 0x00
#define I_1 0x02
#define RR_0 0x01
#define RR_1 0x21
#define REJ_0 0x05
#define REJ_1 0x25


// Opens a connection using the "port" parameters defined in struct linkLayer, returns "-1" on error and "1" on sucess
int llopen(linkLayer connectionParameters);
// Sends data in buf with size bufSize
int llwrite(char* buf, int bufSize);
// Receive data in packet
int llread(char* packet);
// Closes previously opened connection; if showStatistics==TRUE, link layer should print statistics in the console on close
int llclose(linkLayer connectionParameters, int showStatistics);

// Sends control frame with the frameHeader set before | Used as the alarm callback function
int send_ctrl_frame();

// Sends information frame with the frameHeader set before and data passed to llwrite | Used as the alarm callback function
int send_info_frame();

// 
int stuffing(char *str, int len);
// 
int destuffing(char *str, int len);

void frame_state_machine(char ch, frameHeader *fh);

void debugString(char *str);

#endif
