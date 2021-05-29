//#include 
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

// Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 
RF24 radio(9, 10);

int sensorPin = A1;    // select the input pin for the potentiometer
     
byte sensorValue;
byte seninbyte;
                                                                           // Topology
byte addresses[][6] = {"8Node","8Node"};              // Radio pipe addresses for the 2 nodes to communicate.

// Role management: Set up role.  This sketch uses the same software for all the nodes
// in this system.  Doing so greatly simplifies testing.  
typedef enum { role_ping_out = 1, role_pong_back } role_e;                 // The various roles supported by this sketch
const char* role_friendly_name[] = { "invalid", "Ping out", "Pong back"};  // The debug-friendly names of those roles
role_e role = role_pong_back;                                              // The role of the current running sketch

byte counter = 1;                                                          // A single byte to keep track of the data being sent back and forth


void setup(){

  Serial.begin(57600);
  printf_begin();
  printf("\n\rRF24/examples/GettingStarted/\n\r");
  printf("ROLE: %s\n\r",role_friendly_name[role]);
  printf("*** PRESS 'T' to begin transmitting to the other node\n\r");

  // Setup and configure radio

  radio.begin();
  radio.setAutoAck(1);                    // Ensure autoACK is enabled
  radio.enableAckPayload();               // Allow optional ack payloads
  radio.setRetries(0,15);                 // Smallest time between retries, max no. of retries
  radio.setPayloadSize(1);                // Here we are sending 1-byte payloads to test the call-response speed
  radio.openWritingPipe(addresses[1]);        // Both radios listen on the same pipes by default, and switch when writing
  radio.openReadingPipe(1,addresses[0]);      // Open a reading pipe on address 0, pipe 1
  radio.startListening();                 // Start listening
  radio.powerUp();
  radio.printDetails();                   // Dump the configuration of the rf unit for debugging
  
  
  
  role=role_ping_out;

}

void loop(void) {

  sensorValue =    map (analogRead(sensorPin), 500, 988, 0, 180); // wind sensor
  if (sensorValue>-1 && sensorValue < 181){
    seninbyte=sensorValue;
  }



/****************** Ping Out Role ***************************/


  if (role == role_ping_out){                               // Radio is in ping mode

    byte gotByte;                                           // Initialize a variable for the incoming response
    
    radio.stopListening();                                  // First, stop listening so we can talk.      
    printf("Now sending %d as payload\n\r",seninbyte);          // Use a simple byte counter as payload
    unsigned long time = micros();                          // Record the current microsecond count   
                                                            
    if ( radio.write(&seninbyte,1  ) ){                         // Send the counter variable to the other radio 
    //if ( radio.write(&counter,sizeof(counter)) ){                         // Send the counter variable to the other radio 
        if(!radio.available()){                             // If nothing in the buffer, we got an ack but it is blank
            //printf("Got blank response. round-trip delay: %lu microseconds\n\r",micros()-time);     
        }else{      
            while(radio.available() ){                      // If an ack with payload was received
                radio.read( &gotByte, 1 );                  // Read it, and display the response time
                printf("Got response %d, round-trip delay: %lu microseconds\n\r",gotByte,micros()-time);

                //counter++;                                  // Increment the counter variable
            }
        }
    
    }else{        printf("Sending failed.\n\r"); }          // If no ack response, sending failed
    
    delay(100);  // Try again later
  }


}
