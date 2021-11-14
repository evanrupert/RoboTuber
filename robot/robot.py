from websocket_receiver import start
import struct
import time
import serial

#count = 0

def handle_frame(ws,data):
  #right_eye = from_bytes(data[0:1], byteorder='big')
  #left_eye = int.from_bytes(data[1:2], byteorder='big')
  #count = count+1
  #print("count: " + count)
  #print("Raw data from server 1 " +str(data[0:1]))
  #print("Raw data from server 2 " +str(data[1:2]))
  #print("From server: right eye read " + str(right_eye))
  #print("From server: left eye read " + str(left_eye))

  

  cmdList = ["L ","R ","B 0","M 0","P 0","T 0"]
  
  #cmdList[0] = "L " + str(left_eye) +"\n"
  #cmdList[1] = "R " + str(right_eye) +"\n"
  #cmdList[2] = "B " + str(right_eye) +"\n"
  #cmdList[3] = "M " + str(right_eye) +"\n"
  #cmdList[4] = "M " + str(right_eye) +"\n"
  
  ser.write(data.encode('utf-8'))
  line = ser.readline().decode('utf-8').rstrip()
  print("From Arduino: " + line)

  #for i in range(3):
  #    ser.write(cmdList[i].encode('utf-8'))
  #    line = ser.readline().decode('utf-8').rstrip()
  #    print("From Arduino: " + line)
  print("\n")


#time.sleep(.05)
  #return [ "R "+ str(right_eye)+"\n","L "+ str(left_eye) +"\n" ]


if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
    ser.flush()

    start(handle_frame)

