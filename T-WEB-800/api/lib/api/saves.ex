defmodule Api.Saves do
  @moduledoc """
  The Saves context.
  """

  import Ecto.Query, warn: false
  alias Api.Repo

  alias Api.Saves.Save

  @doc """
  Returns the list of saves.

  ## Examples

      iex> list_saves()
      [%Save{}, ...]

  """
  def list_saves do
    Repo.all(Save)
  end

  @doc """
  Gets a single save.

  Raises `Ecto.NoResultsError` if the Save does not exist.

  ## Examples

      iex> get_save!(123)
      %Save{}

      iex> get_save!(456)
      ** (Ecto.NoResultsError)

  """
  def get_save!(id), do: Repo.get!(Save, id)

  def get_save_by_code!(code), do: Repo.get_by!(Save, code: code)

  def get_saves_by_user!(user_id) do
    Repo.all(from(s in Save, where: s.user == ^user_id))
  end

  @doc """
  Creates a save.

  ## Examples

      iex> create_save(%{field: value})
      {:ok, %Save{}}

      iex> create_save(%{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def create_save(attrs \\ %{}) do
    %Save{}
    |> Save.changeset(attrs)
    |> Repo.insert()
  end

  @doc """
  Updates a save.

  ## Examples

      iex> update_save(save, %{field: new_value})
      {:ok, %Save{}}

      iex> update_save(save, %{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def update_save(%Save{} = save, attrs) do
    save
    |> Save.changeset(attrs)
    |> Repo.update()
  end

  @doc """
  Deletes a save.

  ## Examples

      iex> delete_save(save)
      {:ok, %Save{}}

      iex> delete_save(save)
      {:error, %Ecto.Changeset{}}

  """
  def delete_save(%Save{} = save) do
    Repo.delete(save)
  end

  @doc """
  Returns an `%Ecto.Changeset{}` for tracking save changes.

  ## Examples

      iex> change_save(save)
      %Ecto.Changeset{data: %Save{}}

  """
  def change_save(%Save{} = save, attrs \\ %{}) do
    Save.changeset(save, attrs)
  end
end
