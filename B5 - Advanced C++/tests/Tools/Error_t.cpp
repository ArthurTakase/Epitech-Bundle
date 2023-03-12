#include <NetworkLib/HostHandler.hpp>
#include <gtest/gtest.h>
#include <Error/Error.hpp>

TEST(ErrorHandlingMessage, TestErrorHasCertainMessage)
{
    std::vector<std::string> vt = {"-1"};
        try {
            HostHandler::getClientPort(vt);

        } catch (const Error& e) {
            EXPECT_STREQ("Port must be a positive number", e.what());
        }
}