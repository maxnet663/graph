#include "list_graph.h"
#include "matrix_graph.h"
#include <iostream>

ListGraph::ListGraph(int vert_count)
        : adjacency_lists(vert_count, std::list<int>())
        , vertices_count(vert_count) {
    for (int i = 0; i < vertices_count; i++) {
        adjacency_lists[i].push_back(i);
    }
}

ListGraph::ListGraph(IGraph *_oth) {
    auto p = dynamic_cast<MatrixGraph*>(_oth);
    if (p) {
        *this = *p;
    } else {
        *this = *dynamic_cast<ListGraph*>(_oth);
    }
}


void ListGraph::AddEdge(int from, int to) {
    if (from < 1 || from > vertices_count) {
        std::cerr << "From out of range\n";
        return;
    }
    if (to < 1 || to > vertices_count) {
        std::cerr << "To out of range\n";
        return;
    }
    adjacency_lists[from - 1].push_back(to - 1);
}

void ListGraph::dfsNext(int vertex, std::unordered_set<int> &visited) const {
    visited.insert(vertex);
    for (int i : adjacency_lists[vertex])
        if (visited.find(i) == visited.end())
            dfsNext(i, visited);
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    if (vertex < 1 || vertex > vertices_count) {
        std::cerr << "Vertex out of range\n";
        return;
    }
    std::unordered_set<int> visited;
    dfsNext(vertex - 1, visited);
    for (int i : visited) {
        if (i + 1 != vertex)
            vertices.push_back(i + 1);
    }
}

bool contains(std::list<int> &l, int x) {
    for (int i : l)
        if (i == x)
            return true;

    return false;
}

void ListGraph::dfsPrev(int vertex, std::unordered_set<int> &visited) const {
    visited.insert(vertex);
    for (auto i : adjacency_lists) {
        if (contains(i, vertex) && visited.find(i.front()) == visited.end())
            dfsPrev(i.front(), visited);
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    if (vertex < 1 || vertex > vertices_count) {
        std::cerr << "Vertex out of range\n";
        return;
    }
    std::unordered_set<int> visited;
    dfsPrev(vertex - 1, visited);
    for (int i : visited) {
        if (i + 1 != vertex)
            vertices.push_back(i + 1);
    }
}

void ListGraph::printList() const {
    for (int i = 0; i < vertices_count; i++) {
        for (auto j : adjacency_lists[i]) {
            std::cout << " [" << j + 1 << "] -> ";
        }
        std::cout << std::endl;
    }
}

ListGraph& ListGraph::operator=(const MatrixGraph &right) {
    vertices_count = right.VerticesCount();
    adjacency_lists.clear();
    adjacency_lists.resize(vertices_count, std::list<int>());
    for (int i = 0; i < vertices_count; i++) {
        adjacency_lists[i].push_back(i);
        for (int j = 1; j < vertices_count; j++) {
            if (right.at(i, j))
                adjacency_lists[i].push_back(j);
        }
    }
    return *this;
}
