require "test_helper"

class ActionsControllerTest < ActionDispatch::IntegrationTest
  setup do
    @action = actions(:one)
  end

  test "should get index" do
    get actions_url, as: :json
    assert_response :success
  end

  test "should create action" do
    assert_difference("Action.count") do
      post actions_url,
params: { action: { klass: @action.klass, options: @action.options, reaction_id: @action.reaction_id } }, as: :json
    end

    assert_response :created
  end

  test "should show action" do
    get action_url(@action), as: :json
    assert_response :success
  end

  test "should update action" do
    patch action_url(@action),
params: { action: { klass: @action.klass, options: @action.options, reaction_id: @action.reaction_id } }, as: :json
    assert_response :success
  end

  test "should destroy action" do
    assert_difference("Action.count", -1) do
      delete action_url(@action), as: :json
    end

    assert_response :no_content
  end
end
