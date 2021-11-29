#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "TSP.hpp"


TEST(CostMatrixTest, get_min_values_in_rows) {

    cost_matrix_t x =
    {{2, 3, 4},
     {1, 2, 3},
     {3, 4, 5}
    };
    CostMatrix przyklad(x);

    std::vector<cost_t> value = {2, 1, 3};
    EXPECT_EQ(przyklad.get_min_values_in_rows(), value);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}