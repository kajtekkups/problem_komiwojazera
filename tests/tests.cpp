#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "TSP.hpp"


TEST(CostMatrixTest, get_min_values_in_rows) {

    cost_matrix_t x =
    {{2, 3, 4},
     {1, 2, 3},
     {3, 4, 5}
    };
    cost_matrix_t x1 =
            {{2, 3, 4,-1},
             {1, 2, 3, 3},
             {3, 4, 5,-2}
            };
    CostMatrix przyklad(x);
    CostMatrix przyklad1(x1);

    std::vector<cost_t> value = {2, 1, 3};
    std::vector<cost_t> value1 = {-1, 1, -2};
    EXPECT_EQ(przyklad.get_min_values_in_rows(), value);
    EXPECT_EQ(przyklad1.get_min_values_in_rows(), value1);
}

TEST(CostMatrixTest, get_min_values_in_col){
    cost_matrix_t x =
            {{2, 3, 4},
             {1, 2, 3},
             {3, 4, 5}
            };
    cost_matrix_t x1 =
            {{2, 3, 4,-1},
             {1, 2, 3, 3},
             {3, 4, 5,-2}
            };

    CostMatrix przyklad(x);
    CostMatrix przyklad1(x1);

    std::vector<cost_t> value = {1, 2, 3};
    std::vector<cost_t> value1 = {1, 2, 3, -2};

    EXPECT_EQ(przyklad.get_min_values_in_cols(), value);
    EXPECT_EQ(przyklad1.get_min_values_in_cols(), value1);
}

TEST(CostMatrixTest, reduce_row){
    cost_matrix_t x1 =
            {{2, 3, 4, 1},
             {1, 2, 3, 3},
             {3, 4, 5, 2}
            };

    cost_matrix_t wynik =
            {{1, 2, 3, 0},
             {0, 1, 2, 2},
             {1, 2, 3, 0}
            };
    CostMatrix przyklad(x1);
    CostMatrix przyklad_1(x1);

    przyklad.reduce_rows();
    ASSERT_EQ(przyklad.get_matrix(), wynik);
    ASSERT_EQ(przyklad_1.reduce_rows(), 4);
}

TEST(CostMatrixTest, reduce_col){
    cost_matrix_t x1 =
            {{1, 2, 3, 0},
             {0, 1, 2, 2},
             {1, 2, 3, 0}
            };

    cost_matrix_t wynik =
            {{1, 1, 1, 0},
             {0, 0, 0, 2},
             {1, 1, 1, 0}
            };
    CostMatrix przyklad(x1);
    CostMatrix przyklad_1(x1);

    przyklad.reduce_cols();
    ASSERT_EQ(przyklad.get_matrix(), wynik);
    ASSERT_EQ(przyklad_1.reduce_cols(), 3);
}

TEST(CostMatrixTest, get_vertex_cost){
    cost_matrix_t x1 =
            {{1, 2, 3, 0},
             {0, 1, 2, 2},
             {1, 2, 3, 0}
            };

    CostMatrix przyklad(x1);
    int wynik = 2;

    ASSERT_EQ(przyklad.get_vertex_cost(1,1), wynik);


}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}