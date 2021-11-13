from websocket_receiver import start
import struct
import serial

def handle_frame(ws, data):
  right_eye = int.from_bytes(data[0:1], byteorder='big')
  left_eye = int.from_bytes(data[1:2], byteorder='big')

  
  #print("right eye read" + str(right_eye))
  #print("left eye read" + str(left_eye))

  return [ "R "+ str(right_eye)+"\n","L "+ str(left_eye) +"\n" ]


if __name__ == '__main__':
  start(handle_frame)


  
