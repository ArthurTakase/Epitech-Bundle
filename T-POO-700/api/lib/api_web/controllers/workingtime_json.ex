defmodule ApiWeb.WorkingtimeJSON do
  alias Api.Workingtimes.Workingtime

  @doc """
  Renders a list of workingtimes.
  """
  def index(%{workingtimes: workingtimes}) do
    %{data: for(workingtime <- workingtimes, do: data(workingtime))}
  end

  @doc """
  Renders a single workingtime.
  """
  def show(%{workingtime: workingtime}) do
    %{data: data(workingtime)}
  end

  defp data(%Workingtime{} = workingtime) do
    %{
      id: workingtime.id,
      start: workingtime.start,
      end: workingtime.end,
      isFinished: workingtime.isFinished
    }
  end
end
