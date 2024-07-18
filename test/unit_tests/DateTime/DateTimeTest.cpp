// #define CATCH_CONFIG_MAIN
#include "catch.hpp"

// Write your test cases using TEST_CASE macro
TEST_CASE("Addition operation", "[math]") {
    int a = 10;
    int b = 20;

    REQUIRE(a + b == 30);
}

TEST_CASE("Subtraction operation", "[math]") {
    int a = 30;
    int b = 20;

    REQUIRE(a - b == 10);
}