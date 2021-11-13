defmodule UDPServer do
  use GenServer

  def start_link(opts) do
    GenServer.start_link(__MODULE__, opts)
  end

  def init(port: port) do
    IO.puts("Starting...")

    :gen_udp.open(port, [:binary, active: true])
  end

  def handle_info({:udp, _socket, _address, _port, data}, socket) do
    handle_packet(data, socket)
  end

  def handle_packet(data, socket) do
    IO.inspect data

    <<frame::big-integer-unsigned-size(32),
      right_eye_open::integer-unsigned-size(8),
      left_eye_open::integer-unsigned-size(8),
      mouth_open::big-float-size(32),
      mouth_wide::big-float-size(32)>> = data

      IO.puts "Frame: #{frame}, Right Eye: #{right_eye_open}, Left Eye: #{left_eye_open}, Mouth Open: #{mouth_open}, Mouth Wide: #{mouth_wide}"

    {:noreply, socket}
  end

end
