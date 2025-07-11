defmodule Api.UsersTest do
  use Api.DataCase

  alias Api.Users

  describe "users" do
    alias Api.Users.User

    import Api.UsersFixtures

    @invalid_attrs %{username: nil, password: nil, email: nil}

    test "list_users/0 returns all users" do
      user = user_fixture()
      assert Users.list_users() == [user]
    end

    test "get_user!/1 returns the user with given id" do
      user = user_fixture()
      assert Users.get_user!(user.id) == user
    end

    test "create_user/1 with valid data creates a user" do
      valid_attrs = %{
        username: "some username",
        password: "P@ssw0rd",
        email: "mail@mail.com"
      }

      assert {:ok, %User{} = user} = Users.create_user(valid_attrs)
      assert user.username == "some username"
      assert user.password == "#{encrypt_password("P@ssw0rd")}"
      assert user.email == "mail@mail.com"
    end

    test "create_user/1 with invalid data returns error changeset" do
      assert {:error, %Ecto.Changeset{}} = Users.create_user(@invalid_attrs)
    end

    test "create_user/1 with invalid password returns error changeset" do
      invalid_password_attrs = %{
        username: "some username",
        password: "some password",
        email: "mail@mail.com"
      }

      assert {:error, %Ecto.Changeset{}} = Users.create_user(invalid_password_attrs)
    end

    test "update_user/2 with valid data updates the user" do
      user = user_fixture()

      update_attrs = %{
        username: "some updated username",
        password: "P@ssw0rd2",
        email: "mail2@mail.com"
      }

      assert {:ok, %User{} = user} = Users.update_user(user, update_attrs)
      assert user.username == "some updated username"
      assert user.password == "#{encrypt_password("P@ssw0rd2")}"
      assert(user.email == "mail2@mail.com")
    end

    test "update_user/2 with invalid data returns error changeset" do
      user = user_fixture()
      assert {:error, %Ecto.Changeset{}} = Users.update_user(user, @invalid_attrs)
      assert user == Users.get_user!(user.id)
    end

    test "delete_user/1 deletes the user" do
      user = user_fixture()
      assert {:ok, %User{}} = Users.delete_user(user)
      assert_raise Ecto.NoResultsError, fn -> Users.get_user!(user.id) end
    end

    test "change_user/1 returns a user changeset" do
      user = user_fixture()
      assert %Ecto.Changeset{} = Users.change_user(user)
    end
  end

  defp encrypt_password(password) do
    Base.encode16(:crypto.hash(:sha256, "#{password}HelloWorld"))
  end
end
