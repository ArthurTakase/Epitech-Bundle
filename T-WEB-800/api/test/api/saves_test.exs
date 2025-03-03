defmodule Api.SavesTest do
  use Api.DataCase

  alias Api.Saves

  describe "saves" do
    alias Api.Saves.Save

    import Api.SavesFixtures
    import Api.UsersFixtures

    @invalid_attrs %{code: nil, data: nil, last_update: nil}

    test "list_saves/0 returns all saves" do
      save = save_fixture()
      assert Saves.list_saves() == [save]
    end

    test "get_save!/1 returns the save with given id" do
      save = save_fixture()
      assert Saves.get_save!(save.id) == save
    end

    test "create_save/1 with valid data creates a save" do
      user = user_fixture()
      valid_attrs = %{data: "some data", user: user.id}

      assert {:ok, %Save{} = save} = Saves.create_save(valid_attrs)
      assert save.code != ""
      assert save.data == "some data"
    end

    test "create_save/1 with invalid data returns error changeset" do
      assert {:error, %Ecto.Changeset{}} = Saves.create_save(@invalid_attrs)
    end

    test "update_save/2 with valid data updates the save" do
      save = save_fixture()

      update_attrs = %{data: "some updated data"}

      assert {:ok, %Save{} = save} = Saves.update_save(save, update_attrs)
      assert save.code != ""
      assert save.data == "some updated data"
    end

    test "update_save/2 with invalid data returns error changeset" do
      save = save_fixture()
      assert {:error, %Ecto.Changeset{}} = Saves.update_save(save, @invalid_attrs)
      assert save == Saves.get_save!(save.id)
    end

    test "delete_save/1 deletes the save" do
      save = save_fixture()
      assert {:ok, %Save{}} = Saves.delete_save(save)
      assert_raise Ecto.NoResultsError, fn -> Saves.get_save!(save.id) end
    end

    test "change_save/1 returns a save changeset" do
      save = save_fixture()
      assert %Ecto.Changeset{} = Saves.change_save(save)
    end
  end
end
