# Script for populating the database. You can run it as:
#     mix run priv/repo/seeds.exs

defmodule MySeeds do

  alias Api.Repo
  alias Api.Users.User
  alias Api.Users
  alias Api.Teams.Team
  alias Api.Teams
  alias Api.Workingtimes.Workingtime
  alias String

  defp hashed_password(clear_password) do
      Base.encode16(:crypto.hash(:sha256, "#{clear_password}HelloWorld"))
  end

  defp user_exists?(mail) do
    user = Users.get_user_by_email(mail)
    user != nil
  end

  # return month or day with a 0 in front if not formatted correctly
  defp fs_date(subdate) when subdate < 10 do
    updated_subdate = "0#{subdate}"
    updated_subdate
  end

  defp fs_date(subdate) do
    subdate
  end

  defp seed_whole_team(team_user_count, team_name) do
    if Teams.get_team_by_name(team_name) == [] do
      IO.puts("Seeding #{team_name} team with #{team_user_count} users")
      def_pass = "team#{team_name}"

      low_team_name = String.downcase(team_name)

      # Create the team manager changeset
      team_manager_changeset = %User{}
      |> Api.Users.User.changeset(%{
        username: "manager_of_#{low_team_name}",
        email: "manager@#{low_team_name}.com",
        password: hashed_password(def_pass),
        user_role: 2,
        })

      # Insert the team manager into the database
      case Repo.insert(team_manager_changeset) do
        {:ok, team_manager} ->
          IO.puts("#{team_name} manager created and added to the DB\nCreating team...")

          # Create the team changeset
          team_changeset = %Team{}
          |> Api.Teams.Team.changeset(%{
            name: team_name,
            manager: team_manager.id,
          })

          # Insert the team into the database
          case Repo.insert(team_changeset) do
            {:ok, team} ->
              IO.puts("#{team_name} created.\nAdding manager to the new team...")

              # Create a changeset for the team_manager and update their teams
              team_manager_changeset = Ecto.Changeset.change(team_manager, teams: [team.id])
              case Repo.update(team_manager_changeset) do
                {:ok, _updated_team_manager} ->
                  IO.puts("#{team_name} manager added.\nCreating users....")

                  low_team_name = String.downcase(team_name)

                  # Add the users
                  for n <- 0..team_user_count do
                    user_changeset = %User{}
                    |> Api.Users.User.changeset(%{
                      username: "user#{n}_of_#{low_team_name}",
                      email: "user#{n}@#{low_team_name}.com",
                      password: hashed_password(def_pass),
                      user_role: 1,
                      teams: [team.id]
                      })


                      IO.puts("Password: #{def_pass}\nSHA-256 password: #{hashed_password(def_pass)}")

                      case Repo.insert(user_changeset) do
                      {:ok, _user} ->
                        :ok
                        {:error, changeset} ->
                          IO.puts("Failed to insert user: #{inspect(changeset.errors)}")
                        end

                    seed_working_times(Users.get_user_by_email("user#{n}@#{low_team_name}.com"))
                  end

                  IO.puts("#{team_name} team seed finished")

                  {:error, changeset} ->
                    IO.puts("Failed to update team manager: #{inspect(changeset.errors)}")
                  end

                  {:error, changeset} ->
                    IO.puts("Failed to insert team: #{inspect(changeset.errors)}")
                  end

                  {:error, changeset} ->
                    IO.puts("Failed to insert team manager: #{inspect(changeset.errors)}")
                  end
    else
      IO.puts("### TEAM #{team_name} ALREADY EXISTS! ABORTING SEEDING FOR #{team_name} TEAM...")
    end
  end

  def seed_working_times(user) do
    IO.puts("Seeding working times for #{user.username}...")
    seed_months(2023, 1, user)
  end

  defp seed_months(year, 13, _user), do: :ok  # Base case for recursion

  defp seed_months(year, month, user) do
    is_working = :rand.uniform(10)
    if is_working > 1, do: seed_days(year, month, 1, user)

    seed_months(year, month + 1, user)  # Recursive call for next month
  end

  defp seed_days(_year, _month, 31, _user), do: :ok  # Base case for recursion

  defp seed_days(year, 2, 27, user), do: seed_days(year, 3, 1, user)  # February case

  defp seed_days(year, month, day_n, user) do
    if user == nil do
      IO.puts("### USER IS NIL -- CANNOT SEED WORKING TIMES ###")
    else
      date = Date.new!(year, month, day_n)
      day_of_week = Date.day_of_week(date)
      if day_of_week == 6 or day_of_week == 7 do
        # weekend
      else
        IO.puts("Seeding working times for #{user.username}...")
        base_day_start_hour = 9
        base_day_end_hour = 18
        day_start_hour = base_day_end_hour + :rand.uniform(2)
        day_end_hour = base_day_end_hour + :rand.uniform(4)
        test = case DateTime.from_iso8601("#{year}-#{fs_date(month)}-#{fs_date(day_n)}T#{fs_date(day_start_hour)}:00:00Z") do
          {:ok, test_, _offset} -> test_
          {:error, _reason} ->
            IO.puts("Couldn't convert the shift start time correctly")
          end
          IO.puts(test)
          is_working = :rand.uniform(10)
          if is_working > 0 do
            start_datetime = case DateTime.from_iso8601("#{year}-#{fs_date(month)}-#{fs_date(day_n)}T#{fs_date(day_start_hour)}:00:00Z") do
              {:ok, datetime, _offset} -> datetime
              {:error, _reason} ->
                IO.puts("Couldn't convert the shift start time correctly")
          end

          end_datetime = case DateTime.from_iso8601("#{year}-#{fs_date(month)}-#{fs_date(day_n)}T#{fs_date(day_end_hour)}:00:00Z") do
            {:ok, datetime, _offset} -> datetime
            {:error, _reason} ->
            IO.puts("Couldn't convert the shift end time correctly")
          end

          Repo.insert!(%Workingtime{
          start: start_datetime,
        end: end_datetime,
        user: user.id,
          isFinished: true
        }
        )
      end
      end
    end
    seed_days(year, month, day_n + 1, user)  # Recursive call for next day
  end

  #################################################################################

  IO.puts("Start seeding...")

  def run do
    # Denis Super Admin
    # user = Users.get_user_by_email("admin@admin.admin")

    if !user_exists?("admin@admin.admin") do
      password = Base.encode16(:crypto.hash(:sha256, "adminHelloWorld"))

      Repo.insert!(%User{
        username: "Denis",
        email: "admin@admin.admin",
        password: password,
        user_role: 3,
        })
      end

    IO.puts("Denis seeded")

    # General seeding

    seed_whole_team(5, "Poppy")
    seed_whole_team(7, "Lotus")
    seed_whole_team(2, "Rose")

  end

  end

  MySeeds.run()

  IO.puts("Seeding ended")
