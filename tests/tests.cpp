#include "gtest/gtest.h"


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
    ASSERT_EQ(przyklad.get_vertex_cost(0,1), 1);
    ASSERT_EQ(przyklad.get_vertex_cost(2,2), wynik);

}

TEST(StageStateTest, reduce_cost_matrix){
    cost_matrix_t x1 =
            {{INF, 10, 8,   19, 12},
             {10, INF, 20,  6,  3},
             {8,   20, INF, 4,  2},
             {19,  6,  4, INF,  7},
             {12,  3,  2,   7, INF}};

    cost_matrix_t wynik =
            {{INF, 1, 0,   9, 4},
             {1, INF, 17,  1,  0},
             {0,   17, INF, 0,  0},
             {9,  1,  0, INF,  3},
             {4,  0,  0,  3, INF}};
    //test 1
    CostMatrix macierz_kosztow(x1);
    StageState przyklad(macierz_kosztow);

    ASSERT_EQ(przyklad.reduce_cost_matrix(), 28);
    ASSERT_EQ(przyklad.get_matrix().get_matrix(), wynik);
}

TEST(StageStateTest, choose_new_vertex){
    cost_matrix_t x1 =
            {{0, 2, 3, 8},
             {5, 0, 2, 2},
             {1, 2, 3, 0},
             {1, 4, 0, 15}
            };


    CostMatrix macierz_kosztow(x1);
    StageState klasa_wykonawcza(macierz_kosztow);

    NewVertex przyklad = klasa_wykonawcza.choose_new_vertex();

    ASSERT_EQ(przyklad.cost, 4);
    ASSERT_EQ(przyklad.coordinates.row, 1);
    ASSERT_EQ(przyklad.coordinates.col, 1);
}

TEST(StageStateTest, update_cost_matrix){
    cost_matrix_t x1 =
            {{INF, 1, 0,   9,   4},
             {1, INF, 17,  1,   0},
             {0,  17, INF, 0,   0},
             {9,  1,  0,   INF, 3},
             {4,  0,  0,   3,   INF}};


    CostMatrix macierz_kosztow(x1);
    StageState klasa_wykonawcza(macierz_kosztow);

    cost_matrix_t wynik =
            {{INF, 1,   INF,  9,   4},
             {INF, INF, INF,  INF, INF},
             {0,   INF,  INF,  0,   0},
             {9,   1,   INF,  INF, 3},
             {4,   0,   INF,  3,   INF}};

    vertex_t vertex_1(1, 2);
    klasa_wykonawcza.update_cost_matrix(vertex_1);

    ASSERT_EQ(klasa_wykonawcza.get_matrix().get_matrix(), wynik);

    ASSERT_EQ(klasa_wykonawcza.reduce_cost_matrix(), 2);

}

TEST(StageStateTest, get_path){
    cost_matrix_t x1 =
            {{0, 2, 3, 8},
             {5, 0, 2, 2},
             {1, 2, 3, 0},
             {1, 4, 0, 15}
            };

    std::vector<vertex_t> unsorted_path;
    std::size_t vertex_number_1 = 0;
    for(std::size_t vertex_number_2 = 1; vertex_number_2 < 6; vertex_number_2++){

        vertex_t vrtx(vertex_number_1, vertex_number_2);
        unsorted_path.push_back(vrtx);

        vertex_number_1 = vertex_number_2;
    }

    CostMatrix macierz_kosztow(x1);
    StageState klasa_wykonawcza(macierz_kosztow, unsorted_path);

    std::vector<std::size_t> wynik = {0, 1, 2, 3, 4, 5};

    std::vector<std::size_t> wartosc_otrzymana = klasa_wykonawcza.get_path();
    ASSERT_EQ(wartosc_otrzymana, wynik);
}

TEST(Rozwiazania, rozwiazanie_1){
    cost_matrix_t cm = {{INF, 10, 8,   19, 12},
                  {10, INF, 20,  6,  3},
                  {8,   20, INF, 4,  2},
                  {19,  6,  4, INF,  7},
                  {12,  3,  2,   7, INF}};

    std::vector<size_t> wynik = {0, 2, 3, 4, 1};

    ASSERT_EQ(solve_tsp(cm)[0].path, wynik);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}