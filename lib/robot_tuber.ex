defmodule RoboTuber do
  def start(_type, _args) do
    Supervisor.start_link([{UDPServer, [port: 11573]}], strategy: :one_for_one)
  end
end
