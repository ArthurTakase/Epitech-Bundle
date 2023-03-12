#include <gtest/gtest.h>

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;

TEST(JsonParsingTest, TestFile)
{
    std::ifstream file("tests/Tools/test1.json");
    ASSERT_TRUE(file.good()); // Check if file exists and can be opened

    json data;
    file >> data; // Parse the JSON data

    ASSERT_EQ(data.size(), 2); // Ensure we have the correct number of levels

    EXPECT_EQ(data[0].size(), 1);
    EXPECT_EQ(data[0][0]["type"].get<std::string>(), "basic");
    EXPECT_EQ(data[0][0]["positions"][0].get<int>(), 255);
    EXPECT_EQ(data[0][0]["positions"][1].get<int>(), 30);

    EXPECT_EQ(data[1].size(), 1);
    EXPECT_EQ(data[1][0]["type"].get<std::string>(), "boss");
    EXPECT_EQ(data[1][0]["positions"][0].get<int>(), 200);
    EXPECT_EQ(data[1][0]["positions"][1].get<int>(), 100);
}
