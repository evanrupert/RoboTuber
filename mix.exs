defmodule RoboTuber.MixProject do
  use Mix.Project

  def project do
    [
      app: :robo_tuber,
      version: "0.1.0",
      elixir: "~> 1.12",
      start_permanent: Mix.env() == :prod,
      deps: deps()
    ]
  end

  def application do
    [
      mod: {RoboTuber, []},
      extra_applications: [:logger]
    ]
  end

  defp deps do
    [

    ]
  end
end
