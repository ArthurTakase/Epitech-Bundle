defmodule ApiWeb.AuthJSON do
  def show(%{role: role, user_id: user_id, username: username, token: token}) do
    %{
      data: %{
        user_role: role,
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
