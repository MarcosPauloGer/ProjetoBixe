import serial

port = 'COM15'

ser = serial.Serial(port, 9600, timeout=1)

print(f"Lendo dados da porta {port}. Pressione Ctrl+C para sair.")

try:
    while True:
        if ser.in_waiting > 0:
            linha = ser.readline().decode('utf-8', errors='ignore').strip()
            if linha:
                print(f"Recebido: {linha}")
except KeyboardInterrupt:
    print("\nEncerrando leitura.")
finally:
    ser.close()

