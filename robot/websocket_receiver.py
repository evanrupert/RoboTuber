import websocket

def on_error(ws, error):
  print(error)

def on_close(ws, close_status_code, close_msg):
  print("### closed ###")

def on_open(ws):
  def run(*args):
    print("Yo")

def start(on_message):
  websocket.enableTrace(True)
  ws = websocket.WebSocketApp(
    url="ws://localhost:3000/ws",
    on_open=on_open,
    on_message=on_message,
    on_error=on_error,
    on_close=on_close
  )

  ws.run_forever()
