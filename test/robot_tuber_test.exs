defmodule RobotTuberTest do
  use ExUnit.Case
  doctest RobotTuber

  test "greets the world" do
    assert RobotTuber.hello() == :world
  end
end
