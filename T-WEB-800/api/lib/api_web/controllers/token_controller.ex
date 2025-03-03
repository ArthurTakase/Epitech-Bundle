defmodule ApiWeb.TokenController do
  use ApiWeb, :controller

  action_fallback(ApiWeb.FallbackController)

  @salt "monsupermdp"

  def get_token(conn) do
    token =
      get_req_header(conn, "authorization")
      |> List.first()
      |> extract_token()

    case Phoenix.Token.verify(conn, @salt, token) do
      {:ok, user_id} ->
        user_id

      {:error, _reason} ->
        nil
    end
  end

  defp extract_token("Bearer " <> token), do: token
  defp extract_token(_), do: nil
end
