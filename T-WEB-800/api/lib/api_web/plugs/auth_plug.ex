defmodule ApiWeb.Plugs.Auth do
  import Plug.Conn

  alias Phoenix.Token

  import Plug.Conn

  @unauthorized_message "Unauthorized"
  @salt "monsupermdp"

  def init(default), do: default

  def call(conn, _default) do
    jwt =
      get_req_header(conn, "authorization")
      |> List.first()
      |> extract_token()

    case verify_token(jwt, conn) do
      {:ok, decoded} ->
        userId = conn.path_params["userID"]

        if userId == nil do
          conn
        else
          userId = String.to_integer(userId)

          if userId != decoded do
            conn
            |> put_status(:unauthorized)
            |> send_resp(401, @unauthorized_message)
            |> halt()
          else
            conn
          end
        end

      {:error, _reason} ->
        conn
        |> put_status(:unauthorized)
        |> send_resp(401, @unauthorized_message)
        |> halt()
    end
  end

  defp extract_token("Bearer " <> token), do: token
  defp extract_token(_), do: nil

  defp verify_token(nil, _conn), do: {:error, :no_token}

  defp verify_token(token, conn) do
    case Token.verify(conn, @salt, token) do
      {:ok, decoded} -> {:ok, decoded}
      {:error, reason} -> {:error, reason}
    end
  end
end
