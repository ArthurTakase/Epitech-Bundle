require "test_helper"

class WidgetsControllerTest < ActionDispatch::IntegrationTest
  setup do
    @widget = widgets(:one)
  end

  test "should get index" do
    get widgets_url, as: :json
    assert_response :success
  end

  test "should create widget" do
    assert_difference("Widget.count") do
      post widgets_url, params: { widget: { name: @widget.name, user_id: @widget.user_id } }, as: :json
    end

    assert_response :created
  end

  test "should show widget" do
    get widget_url(@widget), as: :json
    assert_response :success
  end

  test "should update widget" do
    patch widget_url(@widget), params: { widget: { name: @widget.name, user_id: @widget.user_id } }, as: :json
    assert_response :success
  end

  test "should destroy widget" do
    assert_difference("Widget.count", -1) do
      delete widget_url(@widget), as: :json
    end

    assert_response :no_content
  end
end
