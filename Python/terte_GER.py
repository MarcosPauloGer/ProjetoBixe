import serial
import time

serial_port = "COM5"
baud_rate = 9600

arduino = serial.Serial(serial_port, baud_rate, timeout = 1)
time.sleep(5)

try:
    while True:
        
        entrada = input('Insira o comando: ')
        mensagem = 0
        
        if entrada == 'direita':
            arduino.write(mensagem.encode())
        elif entrada == 'esquerda':
            mensagem = 1
            arduino.write(mensagem.encode())
        else:
            print('Reescreva o comando: ')
        
        arduino.close()

except serial.SerialException:
    print('O bluetooth não foi conectado')