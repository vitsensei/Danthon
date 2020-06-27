import serial

port_name = "/dev/ttyACM0"
ser = serial.Serial(port=port_name, baudrate=115200, timeout=0.5)
ser.write(bytearray([5, 1, 2, 3, 4, 5]))
ser.flush()

return_length = ser.read(1)
return_length = int.from_bytes(return_length,byteorder='big') # convert byte to int
if return_length == 0:
    print("Receive no message back.")
else:
    return_message = ser.read(return_length)
    print(list(return_message)) # Without warping return_message in a list, you will print byte array instead.

ser.close()
