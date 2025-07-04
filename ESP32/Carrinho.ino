#include "BluetoothSerial.h" //Inclui a biblioteca do bluetooth

const int trigPin = 9;
const int echoPin = 10;

BluetoothSerial bt; //
uint8_t counter = 0; //

long duration;
int distance;

#define motor_A1 7 //Pino para a porta IN1 do motor 1
#define motor_A2 8 //Pino para a porta IN2 do motor 1
#define motor_B1 9 //Pino para a porta IN1 do motor 2
#define motor_B2 10 //Pino para a porta IN2 do motor 2


void setup() {
    Serial.begin(9600);
    bt.begin("Melhor Robô");

    pinMode(motor_A1, OUTPUT); //Define o pino 1 do motor 1 como output
    pinMode(motor_A2, OUTPUT); //Define o pino 2 do motor 1 como output
    pinMode(motor_B1, OUTPUT); //Define o pino 1 do motor 2 como output
    pinMode(motor_B2, OUTPUT); //Define o pino 2 do motor 2 como output

    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}


void loop(){

    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;

    if (distance > 15) {
        digitalWrite(motor_A1, HIGH);
        digitalWrite(motor_A2, HIGH);
        digitalWrite(motor_B1, HIGH);
        digitalWrite(motor_B2, HIGH);
    }
    else {
        digitalWrite(motor_A1, LOW);
        digitalWrite(motor_A2, LOW);
        digitalWrite(motor_B1, LOW);
        digitalWrite(motor_B2, LOW);
        char str = bt.read();
        Serial.println(str);
        if (str == 0){
            gira_esquerda();
        }
        else if (str == 1){
            gira_direita();
        }
    }
}


void gira_esquerda(){
    digitalWrite(motor_A1, HIGH);
    digitalWrite(motor_A2, HIGH);
    digitalWrite(motor_B1, LOW);
    digitalWrite(motor_B2, LOW);
    delay(5000);
}


void gira_direita(){
    digitalWrite(motor_A1, LOW);
    digitalWrite(motor_A2, LOW);
    digitalWrite(motor_B1, HIGH);
    digitalWrite(motor_B2, HIGH);
    delay(5000);
}