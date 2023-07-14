#include <iostream>
#include "matrix_graph.h"
#include "list_graph.h"

int main() {
    std::cout << "Create a new matrix graph\n";
    MatrixGraph m_graph(8);
    m_graph.AddEdge(1, 2);
    m_graph.AddEdge(1, 8);
    m_graph.AddEdge(2, 3);
    m_graph.AddEdge(3, 4);
    m_graph.AddEdge(4, 5);
    m_graph.AddEdge(5, 6);
    m_graph.AddEdge(5, 7);
    m_graph.AddEdge(6, 7);
    m_graph.printMatrix();
    std::cout << "Vertices count: " << m_graph.VerticesCount() << std::endl;
    std::vector<int> next_verts;
    std::cout << "Try GetNextVertices(1, ...)\n";
    m_graph.GetNextVertices(1, next_verts);
    if (next_verts.empty()) {
        std::cout << "There are no vertices\n";
    } else {
        for (int i: next_verts) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    std::vector<int> prev_verts;
    std::cout << "Try GetPrevVertices(6, ...)\n";
    m_graph.GetPrevVertices(6, prev_verts);
    if (prev_verts.empty()) {
        std::cout << "There are no vertices\n";
    } else {
        for (int i: prev_verts) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "Create a new list graph\n";
    ListGraph l_graph(8);
    l_graph.AddEdge(1, 2);
    l_graph.AddEdge(1, 8);
    l_graph.AddEdge(2, 3);
    l_graph.AddEdge(3, 4);
    l_graph.AddEdge(4, 5);
    l_graph.AddEdge(5, 6);
    l_graph.AddEdge(5, 7);
    l_graph.AddEdge(6, 7);
    l_graph.printList();
    std::cout << "Vertices count: " << m_graph.VerticesCount() << std::endl;
    next_verts.clear();
    std::cout << "Try GetNextVertices(1, ...)\n";
    l_graph.GetNextVertices(1, next_verts);
    if (next_verts.empty()) {
        std::cout << "There are no vertices\n";
    } else {
        for (int i: next_verts) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    prev_verts.clear();
    std::cout << "Try GetPrevVertices(6, ...)\n";
    l_graph.GetPrevVertices(6, prev_verts);
    if (prev_verts.empty()) {
        std::cout << "There are no vertices\n";
    } else {
        for (int i: prev_verts) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "Try to make a new graphs:\n";
    IGraph *mg = &m_graph;
    IGraph *lg = &l_graph;
    std::cout << "New matrix graph created from list graph:\n";
    MatrixGraph new_m_graph(lg);
    new_m_graph.printMatrix();
    std::cout << "New list graph created from matrix graph:\n";
    ListGraph new_l_graph(mg);
    new_l_graph.printList();
}
