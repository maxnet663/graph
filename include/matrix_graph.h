#ifndef MATRIX_GRAPH_H_SENTRY
#define MATRIX_GRAPH_H_SENTRY

#include "igraph.h"
#include <unordered_set>

class ListGraph;

class MatrixGraph : public IGraph {
    std::vector<std::vector<int>> matrix;
    int vertices_count;
    MatrixGraph() : vertices_count(0) {}
public:
    MatrixGraph(int vert_count)
        : matrix(vert_count, std::vector<int>(vert_count, 0))
        , vertices_count(vert_count) {};
    MatrixGraph(IGraph *_oth);
    MatrixGraph(const MatrixGraph &other)
        : matrix(other.matrix), vertices_count(other.vertices_count) {};
    MatrixGraph(const ListGraph &other);
    ~MatrixGraph() {}

    void AddEdge(int from, int to) override;
    int VerticesCount() const override { return vertices_count; };
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
    void printMatrix() const;
    int at(int x, int y) const;

    MatrixGraph& operator=(const ListGraph &right);

private:
    void dfsNext(int vertex, std::unordered_set<int> &visited) const;
    void dfsPrev(int vertex, std::unordered_set<int> &visited) const;
};

#endif //MATRIX_GRAPH_H_SENTRY
