import serial

SERIAL_PORT = 'COM15'
BAUD_RATE = 9600

while True:
    try:
        with serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1) as ser:
            print(f"### Conectado à porta serial {SERIAL_PORT}!")
            while True:
                linha = ser.readline().decode('utf-8').strip()
                print(f"# {linha}")

    except serial.SerialException as e:
        print(f"** Erro ao abrir a porta serial: {e}")
        input("** Pressione Enter para tentar novamente...")
