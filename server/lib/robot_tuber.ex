defmodule RoboTuber do
  def start(_type, _args) do
    [
      {UDPServer, [port: 11573]},
      {Riverside, [handler: WebsocketHandler]},
      {SessionState, nil}
    ]
    |> Supervisor.start_link(strategy: :one_for_one)
  end
end
