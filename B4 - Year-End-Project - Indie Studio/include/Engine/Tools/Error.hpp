/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Error
*/

#pragma once

#include <exception>
#include <string>
#include <string_view>

enum class ReturnCode : std::size_t {
    SUCCESS_CODE = 0,
    ERROR_CODE   = 84,
};

class Error : public std::exception
{
  public:
    explicit Error(const std::string_view& message) noexcept;
    Error(const Error& other) noexcept = default;
    Error(Error&& other) noexcept      = default;
    ~Error() noexcept override         = default;

    Error&      operator=(const Error&) noexcept = default;
    Error&      operator=(Error&&) noexcept = default;
    const char* what() const noexcept override;

  protected:
  private:
    std::string message_;
};
