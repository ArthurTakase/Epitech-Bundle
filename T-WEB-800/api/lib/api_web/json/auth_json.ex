defmodule ApiWeb.AuthJSON do
  def show(%{user_id: user_id, username: username, token: token}) do
    %{
      data: %{
        token: token,
        user_id: user_id,
        username: username
      }
    }
  end

  def error(%{error: error}) do
    %{
      error: error
    }
  end
end
