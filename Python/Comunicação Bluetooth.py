import serial            #biblioteca necessária para a comunicação via blueetooth
import time              #biblioteca necessária para a gestão do tempo no python

#determina a porta serial fictícia usada para a comunicação com o arduino
serial_port = "COM11"
#determina a frequência usada para a comuicação com o arduino 
baud_rate = 9600

#configura a variável 'arduino' a partir dos parâmetros anteriores(a porta de comunicação, a frequencia e o intervalo)
arduino = serial.Serial(serial_port, baud_rate, timeout = 1)
time.sleep(2)

#tenta rodar o código
try:
    while True:
        #variável que recebe a mensagem pelo terminal
        entrada = input('Insira o comando: ')
        #variável que guarda a mensagem a ser enviada para o ESP32 
        mensagem = '0'
        
        #condição que verifica a direção digitada no terminal e envia ser respecctivo código caso a mensagem esteja correta
        if entrada == 'direita':
            arduino.write(mensagem.encode())
        elif entrada == 'esquerda':
            mensagem = 1
            arduino.write(mensagem.encode())
        else:
            print('Comando incorreto')
        
        #fecha a comunicação momentaneamente, envia o dado e reinicia o ciclo
        arduino.close()

#caso algum erro ocorra, avisa o usuário
except serial.SerialException:
    print('O bluetooth não foi conectado')