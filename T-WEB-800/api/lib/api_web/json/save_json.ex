defmodule ApiWeb.SaveJSON do
  alias Api.Saves.Save

  @doc """
  Renders a list of saves.
  """
  def index(%{saves: saves}) do
    %{data: for(save <- saves, do: data(save))}
  end

  @doc """
  Renders a single save.
  """
  def show(%{save: save}) do
    %{data: data(save)}
  end

  defp data(%Save{} = save) do
    %{
      id: save.id,
      data: save.data,
      code: save.code,
      last_update: save.last_update,
      user: save.user
    }
  end

  def error(%{error: error}) do
    %{
      error: error
    }
  end

  def extracted(%{save: save, edata: edata}) do
    %{
      save: data(save),
      data: edata
    }
  end
end
