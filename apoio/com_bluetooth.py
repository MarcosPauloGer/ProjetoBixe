import serial            #biblioteca necessária para a comunicação via blueetooth
import time              #biblioteca necessária para a gestão do tempo no python

#determina a porta serial fictícia usada para a comunicação com o arduino
serial_port = "COM16"
#determina a frequência usada para a comuicação com o arduino 
baud_rate = 9600

#configura a variável 'arduino' a partir dos parâmetros anteriores(a porta de comunicação, a frequencia e o intervalo)
espBT = serial.Serial(serial_port)
time.sleep(2)

print(f"### Conectado ao bluetooth - {serial_port}!")

try:
    while True:
        #variável que recebe a mensagem pelo terminal
        entrada = input('Insira o comando: ')
        #code = b'd'
        #code = b'e'

        espBT.write(entrada[0].encode('utf-8'))

except KeyboardInterrupt:
    print("\n### ENCERRANDO COMUNICAÇÃO.")
finally:
    espBT.close()
