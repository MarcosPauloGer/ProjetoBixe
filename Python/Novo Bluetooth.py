import bluetooth

esp32= "my local bt"
address = ''
devices = bluetooth.discover_devices()

for addr in devices:
    if esp32 == bluetooth.lookup_name(addr):
        address = addr
        break
port = 1
sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
sock.connect((address, port))
sock.send("hey")
sock.close()