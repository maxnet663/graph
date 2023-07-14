#ifndef LIST_GRAPH_H_SENTRY
#define LIST_GRAPH_H_SENTRY

#include "igraph.h"
#include <unordered_set>
#include <list>

class MatrixGraph;

class ListGraph : public IGraph {
    std::vector<std::list<int>> adjacency_lists;
    int vertices_count;
    ListGraph() : vertices_count(0) {}
public:
    ListGraph(int vert_count);
    ListGraph(IGraph *_oth);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override  { return vertices_count; }
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
    const std::list<int>& getVertex(int vertex) const { return adjacency_lists[vertex]; }
    void printList() const;

    ListGraph& operator=(const MatrixGraph &right);

private:
    void dfsNext(int vertex, std::unordered_set<int> &visited) const;
    void dfsPrev(int vertex, std::unordered_set<int> &visited) const;
};


#endif //LIST_GRAPH_H_SENTRY
