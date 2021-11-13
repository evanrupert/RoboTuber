defmodule SessionState do
  use GenServer

  # Server

  @impl true
  def init(session) do
    {:ok, session}
  end

  @impl true
  def handle_call(:get, _from, session) do 
    {:reply, session, session}
  end

  @impl true
  def handle_cast({:set, new_session}, _old_session) do
    {:noreply, new_session}
  end

  # Client

  def start_link(initial_session) do
    GenServer.start_link(__MODULE__, initial_session, name: __MODULE__)
  end

  def get do
    GenServer.call(__MODULE__, :get)
  end

  def set(session) do
    GenServer.cast(__MODULE__, {:set, session})
  end

end