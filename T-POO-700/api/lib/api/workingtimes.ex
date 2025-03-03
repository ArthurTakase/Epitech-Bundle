defmodule Api.Workingtimes do
  @moduledoc """
  The Workingtimes context.
  """

  import Ecto.Query, warn: false
  alias Api.Repo

  alias Api.Workingtimes.Workingtime

  def list_workingtimes do
    Repo.all(Workingtime)
  end

  def get_workingtime!(id), do: Repo.get!(Workingtime, id)

  def create_workingtime(attrs \\ %{}) do
    attrs = Map.put(attrs, "isFinished", attrs["start"] < attrs["end"])

    %Workingtime{}
    |> Workingtime.changeset(attrs)
    |> Repo.insert()
  end

  def update_workingtime(%Workingtime{} = workingtime, attrs) do
    attrs = Map.put(attrs, "isFinished", attrs["start"] < attrs["end"])

    workingtime
    |> Workingtime.changeset(attrs)
    |> Repo.update()
  end

  def delete_workingtime(%Workingtime{} = workingtime) do
    Repo.delete(workingtime)
  end

  def delete_workingtime_by_user_id(user_id) do
    workingtimes = from(w in Workingtime, where: w.user == ^user_id)
    Repo.delete_all(workingtimes)
  end

  def change_workingtime(%Workingtime{} = workingtime, attrs \\ %{}) do
    Workingtime.changeset(workingtime, attrs)
  end

  def get_all_workingtimes_between(user, startDate, endDate) do
    startDate = if startDate == "null 00:00:00", do: "2000-01-01 00:00:00", else: startDate
    endDate = if endDate == "null 00:00:00", do: "3000-01-01 00:00:00", else: endDate

    query =
      from(w in Workingtime,
        where: w.user == ^user and w.start >= ^startDate and w.end <= ^endDate,
        select: w
      )

    query = from(w in query, order_by: [asc: w.start])

    Repo.all(query)
  end

  def get_user_workingtime!(user, id) do
    query =
      from(w in Workingtime,
        where: w.user == ^user and w.id == ^id,
        select: w
      )

    Repo.one!(query)
  end
end
