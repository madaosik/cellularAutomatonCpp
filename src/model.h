/*********************************
 * IMS - cellular automata       *
 * 2018/2019                     *
 * Tomas Willaschek  (xwilla00)  *
 * Adam Lanicek      (xlanic04)  *
 *********************************/

#ifndef IMS_MODEL_H
#define IMS_MODEL_H

#include <iostream>
#include <map>

using std::map;

class Model {
public:
    Model(int, int, float, float);
    ~Model();

    /**
     * Prints matrix to stdout
     */
    void print_matrix();
    /**
     * Prints s_arr to stdout
     */
    void print_s_arr();
    /**
     * Starts simulations
     */
    void run();

private:
    /** Input arguments */
    float alpha;
    float beta;
    int fermions;
    int edge;
    int matrix_size;

    /** Program defined variables **/
    int iteration; //! iteration count
    int exit_pos; //! position on exit on map
    int **matrix; //! [cols][rows]
    double **s_arr; //! [cols][rows]
    map<int, map<int, int>> d_arr;


    /**
     * Generates random number from zero to range
     * @param range
     * @return random number
     */
    int random(int);

    /**
     * Generates fermions to random position into matrix
     */
    void populate_matrix();

    /**
     * Populate each index from array with value
     * Indexes close to exit have bigger value than others
     */
    void generate_s_arr();

    /**
     * Insert value to d_arr -> < matrix_index < iteration, value > >
     * @param row: index in matrix
     * @param col: index in matrix
     * @param value: value that should be added
     */
    void insert(int, int, int);
};

#endif //IMS_MODEL_H
