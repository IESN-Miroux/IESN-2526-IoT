import serial

USB = "/dev/ttyACM0"
SER = serial.Serial(USB, baudrate=9600, dsrdtr=False)

while True:

    ligne = SER.readline()
    strlignes = ligne.decode("utf-8")
    strligne = strlignes.strip()

    print(strligne)

    status = strligne.split()
    print(status[0])
    print(status[0] is "Success")
