defmodule WebsocketHandler do
  use Riverside, otp_app: :robo_tuber

  @impl Riverside
  def init(session, state) do
    IO.puts "Connecting"
    SessionState.set(session)

    {:ok, session, state}
  end

  @impl Riverside
  def handle_message(msg, session, state) do
    IO.puts msg

    {:ok, session, state}
  end

  # @impl Riverside
  # def handle_info(into, session, state) do
  #   IO.puts into

  #   {:ok, session, state}
  # end

  def send(thing) do
    session = SessionState.get()
    deliver_session(session.user_id, session.session_id, thing)
  end

end
