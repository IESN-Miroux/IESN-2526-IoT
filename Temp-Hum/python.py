import serial
import json

USB = "/dev/ttyACM0"
SER = serial.Serial(USB, baudrate=115200, dsrdtr=False)

while True:

    ligne = SER.readline()
    strlignes = ligne.decode("utf-8")
    strligne = strlignes.strip()

    print(strligne)

    status = strligne.split()
    print(status[0])

    if status[0] == "Success":

        a = "ok:true"
        a_json = json.dumps(a)

        f = open("myjson.json", "w", encoding="utf-8")
        f.write(a)
        f.close()
