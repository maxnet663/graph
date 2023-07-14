#include "matrix_graph.h"
#include "list_graph.h"
#include <iostream>

MatrixGraph::MatrixGraph(IGraph *_oth) {
    auto p = dynamic_cast<MatrixGraph*>(_oth);
    if (p) {
        *this = *p;
    } else {
        *this = *dynamic_cast<ListGraph*>(_oth);
    }
}

MatrixGraph::MatrixGraph(const ListGraph &other)
        : matrix(other.VerticesCount()
                 , std::vector<int>(other.VerticesCount(), 0))
        , vertices_count(other.VerticesCount()) {
    std::vector<int> vertices;
    for (int i = 0; i < vertices_count; i++) {
        other.GetNextVertices(i + 1, vertices);
        for (int j = 0; j < vertices.size(); j++) {
            matrix[i][vertices[j] - 1] = 1;
        }
    }
}


void MatrixGraph::AddEdge(int from, int to) {
    if (from < 1 || from > vertices_count + 1) {
        std::cerr << "From out of range\n";
    }
    if (to < 1 || to > vertices_count + 1) {
        std::cerr << "To out of range\n";
    }
    matrix[from - 1][to - 1] = 1;
}

void MatrixGraph::dfsNext(int vertex, std::unordered_set<int> &visited) const {
    visited.insert(vertex);
    for (int j = 0; j < vertices_count; j++) {
        if (matrix[vertex][j] && visited.find(j) == visited.end()) {
            dfsNext(j, visited);
        }
    }
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    if (vertex < 1 || vertex > vertices_count + 1) {
        std::cerr << "Vertex out of range\n";
    }
    std::unordered_set<int> visited;
    dfsNext(vertex - 1, visited);
    for (int p : visited) {
        if (p + 1 != vertex)
            vertices.push_back(p + 1);
    }
}

void MatrixGraph::dfsPrev(int vertex, std::unordered_set<int> &visited) const {
    visited.insert(vertex);
    for (int j = 0; j < vertices_count; j++) {
        if (matrix[j][vertex] && visited.find(j) == visited.end()) {
            dfsPrev(j, visited);
        }
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    if (vertex < 1 || vertex > vertices_count + 1) {
        std::cerr << "Vertex out of range\n";
    }
    std::unordered_set<int> visited;
    dfsPrev(vertex - 1, visited);
    for (int p : visited) {
        if (p + 1 != vertex)
            vertices.push_back(p + 1);
    }
}

void MatrixGraph::printMatrix() const {
    std::cout << "    ";
    for (int i = 0; i < vertices_count; i++) {
        std::cout << i + 1 << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < matrix.size(); i++) {
        std::cout << i + 1 << " | ";
        for (int j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


int MatrixGraph::at(int x, int y) const {
    if (x < 0 || x > vertices_count) {
        std::cerr << "From out of range\n";
        return 0;
    }
    if (y < 0 || y > vertices_count) {
        std::cerr << "To out of range\n";
        return 0;
    }
    return matrix[x][y];
}

MatrixGraph& MatrixGraph::operator=(const ListGraph &right) {
    vertices_count = right.VerticesCount();
    matrix.clear();
    matrix.resize(vertices_count,std::vector<int>(vertices_count, 0));

    std::vector<int> vertices;
    for (int i = 0; i < vertices_count; i++) {
        for (auto j : right.getVertex(i)) {
            if (i != j)
                matrix[i][j] = 1;
        }
    }
    return *this;
}
