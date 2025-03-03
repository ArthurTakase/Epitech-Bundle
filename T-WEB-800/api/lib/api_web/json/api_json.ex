defmodule ApiWeb.ApiJSON do
  def show(%{data: data}) do
    %{
      data: data
    }
  end

  def error(%{error: error}) do
    %{
      error: error
    }
  end
end
