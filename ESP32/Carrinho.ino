#include <Ultrasonic.h> //Inclui a biblioteca do ultrassônico
#include "BluetoothSerial.h" //Inclui a biblioteca do bluetooth
Ultrasonic ultrassom(5, 4); //Cria o objeto ultrassom, do tipo Ultrassonic, e define os pinos onde está ligado o TRIG(pino 5) e o ECHO(pino 4) respectivamente

long distancia; //cria a variável distancia do tipo long

BluetoothSerial SerialBT; //
uint8_t counter = 0; //

#define motor_A1 7 //Pino para a porta IN1 do motor 1
#define motor_A2 8 //Pino para a porta IN2 do motor 1
#define motor_B1 9 //Pino para a porta IN1 do motor 2
#define motor_B2 10 //Pino para a porta IN2 do motor 2


void setup() {
    Serial.begin(9600); //Inicializa a comunicação serial, com velocidade de comunicação de 9600
    SerialBT.begin("Equipe 1"); //Nome do dispositivo Bluetooth

    pinMode(motor_A1, OUTPUT); //Define o pino 1 do motor 1 como output
    pinMode(motor_A2, OUTPUT); //Define o pino 2 do motor 1 como output
    pinMode(motor_B1, OUTPUT); //Define o pino 1 do motor 2 como output
    pinMode(motor_B2, OUTPUT); //Define o pino 2 do motor 2 como output
}


void loop(){
    
    //verifica a mensagem recebida pelo bluetooth enquanto houver loop
    if (Serial.available()) {
        SerialBT.write(Serial.read());
    }
    if (SerialBT.available()) {
        Serial.write(SerialBT.read());
    }
    delay(500);
    SerialBT.write(counter);
    counter = counter > 254 ? 0 : counter+1;

    //condição que verfica se a distancia do carrinho à parede é menor que 15 cm.
    //Se não for, anda em linha reta, se for, para o robô, espera o comando e gira para o lado apropriado
    if (calcula_distancia() > 15){
        digitalWrite(motor_A1, HIGH);
        digitalWrite(motor_A2, HIGH);
        digitalWrite(motor_B1, HIGH);
        digitalWrite(motor_B2, HIGH);
    } 
    else{
        digitalWrite(motor_A1, LOW);
        digitalWrite(motor_A2, LOW);
        digitalWrite(motor_B1, LOW);
        digitalWrite(motor_B2, LOW);

        if (Serial.read() == 0){
            gira_esquerda();
        }
        elif (Serial.read() == 1){
            gira_direira();
        }
    }
}


void calcula_distancia(){
    distancia = ultrassom.Ranging(CM); //ultrassom.Ranging(CM) retorna a distancia em centímetros(CM)
    delay(500); //Intervalo de meio segundo
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