#include "TSP.hpp"

#include <algorithm>
#include <stack>
#include <optional>


std::ostream& operator<<(std::ostream& os, const CostMatrix& cm) {
    for (std::size_t r = 0; r < cm.size(); ++r) {
        for (std::size_t c = 0; c < cm.size(); ++c) {
            const auto& elem = cm[r][c];
            os << (is_inf(elem) ? "INF" : std::to_string(elem)) << " ";
        }
        os << "\n";
    }
    os << std::endl;

    return os;
}

/* PART 1 */

/**
 * Create path from unsorted path and last 2x2 cost matrix.
 * @return The vector of consecutive vertex.
 */
path_t StageState::get_path() {

    unsorted_path_t unsorted_copy = unsorted_path_;
    path_t scierzka = {unsorted_path_[0].row, unsorted_path_[0].col};

    unsorted_copy.erase(unsorted_copy.begin());

    while(scierzka.size() != unsorted_path_.size()+1){
        for(auto vertex: unsorted_copy){

            if (scierzka.back() == vertex.row){
                scierzka.push_back(vertex.col);
            }
        }
    }

    return scierzka;
}

/**
 * Get minimum values from each row and returns them.
 * @return Vector of minimum values in row.
 */
std::vector<cost_t> CostMatrix::get_min_values_in_rows() const {
    std::vector<cost_t> minimum_in_row;

    for(auto row: matrix_){
        int min = *std::min_element(std::begin(row), std::end(row));
        minimum_in_row.push_back(min);
    }
    return minimum_in_row;
}

/**
 * Reduce rows so that in each row at least one zero value is present.
 * @return Sum of values reduced in rows.
 */
cost_t CostMatrix::reduce_rows() {
    std::vector<cost_t> min_value_vector =CostMatrix::get_min_values_in_rows(); //tworzy wektor minimalnych wartosci
    std::size_t row_number = 0; //zmienna pomocnicza
    int row_size = int(matrix_[0].size());

    for(std::size_t elem=0; elem < min_value_vector.size(); elem++){
        if(min_value_vector[elem] == INF){
            min_value_vector[elem] = 0;
        }
    }

    for(const auto& row: matrix_){
        for(std::size_t element = 0; int(element) < row_size; element++){
            if(matrix_[row_number][element] != INF){
                matrix_[row_number][element] -= min_value_vector[row_number];
            }

        }
        row_number++;
    }

    return std::accumulate(min_value_vector.begin(), min_value_vector.end(), 0);
}

/**
 * Get minimum values from each column and returns them.
 * @return Vector of minimum values in columns.
 */
std::vector<cost_t> CostMatrix::get_min_values_in_cols() const {

    std::vector<cost_t> min_values; //wektor wartosci minimalnych w kolumnach
    int column_number = int(matrix_[0].size()); //liczba kolumn w macierzy

    //podwojna petla sprawdzajaca najpierw w ktorej kolumnie jetesmy
    //nastepnie najmniejsza wartosc w kazdej kolumnie
    for(std::size_t kolumna = 0; int(kolumna) < column_number; kolumna++){
        int wartosc_min_kolumna = matrix_[0][kolumna]; //pomocnicza zmienna

        for(auto row: matrix_){
            if(wartosc_min_kolumna > row[kolumna]){
                wartosc_min_kolumna = row[kolumna];
            }
        }
        min_values.push_back(wartosc_min_kolumna);
    }
    return (min_values);
}

/**
 * Reduces rows so that in each column at least one zero value is present.
 * @return Sum of values reduced in columns.
 */
cost_t CostMatrix::reduce_cols() {
    std::vector<cost_t> min_value_col = CostMatrix::get_min_values_in_cols();
    std::size_t matrix_size_col = min_value_col.size(); //ile kolumn w macierzy
    std::size_t row_iter = 0; //bedzie sluzyl do kontrolowania numeru wiersza w petli for

    for(std::size_t elem=0; elem < min_value_col.size(); elem++){
        if(min_value_col[elem] == INF){
            min_value_col[elem] = 0;
        }
    }

    for(auto row: matrix_){

        for(std::size_t col_number = 0; col_number < matrix_size_col; col_number++){
            if(matrix_[row_iter][col_number] != INF){
                matrix_[row_iter][col_number] -= min_value_col[col_number];
            }
        }
        row_iter++;
    }

    return int(std::accumulate(min_value_col.begin(), min_value_col.end(), 0));
}

/**
 * Get the cost of not visiting the vertex_t (@see: get_new_vertex())
 * @param row
 * @param col
 * @return The sum of minimal values in row and col, excluding the intersection value.
 */
cost_t CostMatrix::get_vertex_cost(std::size_t row, std::size_t col) const {

    std::vector<cost_t> row_values = matrix_[row]; //moga wystapic problemy

    row_values.erase(row_values.begin() + (long long)col); //usuwa wspolny element kolumny i wiersza

    int min_elm_row = *std::min_element(row_values.begin(), row_values.end()); // szuka najmniejszego elementu w wierszu

    if(min_elm_row == INF){
        min_elm_row = 0; // ustawia wartosc zabronionych przejsc na 0
    }
    std::vector<cost_t> column;
    for (const auto &row_number: matrix_) {
        column.push_back(row_number[col]); // tworzy wektor wartosci w kolumnie
    }
    column.erase(column.begin() + (long long)row);

    int min_elm_col = *std::min_element(column.begin(), column.end());

    if(min_elm_col == INF){
        min_elm_col = 0;
    }
    return int(min_elm_col + min_elm_row);
}

void CostMatrix::change_to_inf(vertex_t new_vertex, const std::vector<vertex_t>& zakaz_przejsc) {
    auto row = new_vertex.row;
    auto col = new_vertex.col;

    //wykresla wiersz i kolumne
    for(size_t element = 0; element < matrix_[row].size(); element++){
        matrix_[row][element] = INF;
    }
    for(size_t row_number = 0; row_number < matrix_.size(); row_number++){
        matrix_[row_number][col] = INF;
    }

    //zakaz przejsc ze scierzki
    for(auto vertex: zakaz_przejsc){
        matrix_[vertex.row][vertex.col] = INF;
    }

    //zakaz przejscia odwrotnie
    matrix_[col][row] = INF;
}
/* PART 2 */

/**
 * Choose next vertex to visit:
 * - Look for vertex_t (pair row and column) with value 0 in the current cost matrix.
 * - Get the vertex_t cost (calls get_vertex_cost()).
 * - Choose the vertex_t with maximum cost and returns it.
 * @param cm
 * @return The coordinates of the next vertex.
 */
NewVertex StageState::choose_new_vertex() {

    vertex_t maximum_cost_vertex;
    int maximum_cost_guard = -1;

    //sprawdzamy gdzie są zera
    for(std::size_t row_guard = 0; row_guard < (matrix_.get_matrix()).size(); row_guard++){
        for(std::size_t col_guard = 0; col_guard < (matrix_.get_matrix())[0].size(); col_guard++){
        //petle po elementach macierzy kosztow

            // jezeli element = 0
            if(matrix_.get_matrix()[row_guard][col_guard] == 0){

                //jezeli koszt dla danego rzedu i kolumny jest wiekszy niz poprzedni
                if(matrix_.get_vertex_cost(row_guard, col_guard) > maximum_cost_guard){

                    maximum_cost_guard = matrix_.get_vertex_cost(row_guard, col_guard);
                    maximum_cost_vertex = vertex_t(row_guard, col_guard);
                }
            }
        }
    }

    return NewVertex(maximum_cost_vertex, maximum_cost_guard);
}

/**
 * Update the cost matrix with the new vertex.
 * @param new_vertex
 */
void StageState::update_cost_matrix(vertex_t new_vertex) {

    //zabrania przejsc niebedacych w cyklu
    unsorted_path_t unsorted_copy = unsorted_path_; //TODO: sprawdzic czy nie ma problemu
    std::vector<vertex_t> zakazane_przejscia;

    for(auto vertex_1: unsorted_copy){
        for(auto vertex_2: unsorted_copy){

            if(vertex_1.col == vertex_2.row) {
                vertex_t zakaz_przejscia   (vertex_2.col, vertex_1.col);
                vertex_t zakaz_przejscia_1 (vertex_2.col, vertex_1.row);
                zakazane_przejscia.push_back(zakaz_przejscia);
                zakazane_przejscia.push_back(zakaz_przejscia_1);

                //sprawdzam kolejne cykle
                for(auto vertex_3: unsorted_copy){
                    if(vertex_2.col == vertex_3.row) {
                        vertex_t zakaz_przejscia_2(vertex_3.col, vertex_1.row);
                        vertex_t zakaz_przejscia_3(vertex_3.col, vertex_1.col);
                        zakazane_przejscia.push_back(zakaz_przejscia_2);
                        zakazane_przejscia.push_back(zakaz_przejscia_3);
                    }
                }
            }
        }
    }

    matrix_.change_to_inf(new_vertex, zakazane_przejscia);

}

/**
 * Reduce the cost matrix.
 * @return The sum of reduced values.
 */
cost_t StageState::reduce_cost_matrix() {
    int reduced_values = 0; //wartosc wszystkich zredukowanych elementow
    reduced_values += matrix_.reduce_rows(); //redukuje wartosci w wierszach i zwraca sume zredukowanych wartosci
    reduced_values += matrix_.reduce_cols();


    return reduced_values;
}

/**
 * Given the optimal path, return the optimal cost.
 * @param optimal_path
 * @param m
 * @return Cost of the path.
 */
cost_t get_optimal_cost(const path_t& optimal_path, const cost_matrix_t& m) {
    cost_t cost = 0;

    for (std::size_t idx = 1; idx < optimal_path.size(); ++idx) {
        cost += m[optimal_path[idx - 1]][optimal_path[idx]];
    }

    // Add the cost of returning from the last city to the initial one.
    cost += m[optimal_path[optimal_path.size() - 1]][optimal_path[0]];

    return cost;
}

/**
 * Create the right branch matrix with the chosen vertex forbidden and the new lower bound.
 * @param m
 * @param v
 * @param lb
 * @return New branch.
 */
StageState create_right_branch_matrix(cost_matrix_t m, vertex_t v, cost_t lb) {
    CostMatrix cm(m);
    cm[v.row][v.col] = INF;
    return StageState(cm, {}, lb);
}

/**
 * Retain only optimal ones (from all possible ones).
 * @param solutions
 * @return Vector of optimal solutions.
 */
tsp_solutions_t filter_solutions(tsp_solutions_t solutions) {
    cost_t optimal_cost = INF;
    for (const auto& s : solutions) {
        optimal_cost = (s.lower_bound < optimal_cost) ? s.lower_bound : optimal_cost;
    }

    tsp_solutions_t optimal_solutions;
    std::copy_if(solutions.begin(), solutions.end(),
                 std::back_inserter(optimal_solutions),
                 [&optimal_cost](const tsp_solution_t& s) { return s.lower_bound == optimal_cost; }
    );

    return optimal_solutions;
}

/**
 * Solve the TSP.
 * @param cm The cost matrix.
 * @return A list of optimal solutions.
 */
tsp_solutions_t solve_tsp(const cost_matrix_t& cm) {

    StageState left_branch(cm);

    // The branch & bound tree.
    std::stack<StageState> tree_lifo;

    // The number of levels determines the number of steps before obtaining
    // a 2x2 matrix.
    std::size_t n_levels = cm.size(); //TODO: bylo -2

    tree_lifo.push(left_branch);   // Use the first cost matrix as the root.

    cost_t best_lb = INF;
    tsp_solutions_t solutions;

    while (!tree_lifo.empty()) {

        left_branch = tree_lifo.top();
        tree_lifo.pop();

        while (left_branch.get_level() != n_levels && left_branch.get_lower_bound() <= best_lb) {
            // Repeat until a 2x2 matrix is obtained or the lower bound is too high...

            if (left_branch.get_level() == 0) {
                left_branch.reset_lower_bound();
            }

            // 1. Reduce the matrix in rows and columns.
            cost_t new_cost = left_branch.reduce_cost_matrix();

            // 2. Update the lower bound and check the break condition.
            left_branch.update_lower_bound(new_cost);
            if (left_branch.get_lower_bound() > best_lb) {
                break;
            }

            // 3. Get new vertex and the cost of not choosing it.
            NewVertex new_vertex = left_branch.choose_new_vertex();

            // 4.Update the path - use append_to_path method.
            left_branch.append_to_path(new_vertex.coordinates);

            // 5.(KROK 3) Update the cost matrix of the left branch.
            left_branch.update_cost_matrix(new_vertex.coordinates);

            // 6. Update the right branch and push it to the LIFO.
            cost_t new_lower_bound = left_branch.get_lower_bound() + new_vertex.cost;
            tree_lifo.push(create_right_branch_matrix(cm, new_vertex.coordinates,
                                                      new_lower_bound));
        }

        if (left_branch.get_lower_bound() <= best_lb) {
            // If the new solution is at least as good as the previous one,
            // save its lower bound and its path.
            best_lb = left_branch.get_lower_bound();
            path_t new_path = left_branch.get_path();
            solutions.push_back({get_optimal_cost(new_path, cm), new_path});
        }
    }

    return filter_solutions(solutions); // Filter solutions to find only optimal ones.
}
