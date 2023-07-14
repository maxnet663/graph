#ifndef IGRAPH_H_SENTRY
#define IGRAPH_H_SENTRY

#include <vector>

class IGraph { // interface
public:
    virtual ~IGraph() {}
    IGraph() {};
    IGraph(IGraph *_oth) {};

    // The method takes the vertices of the beginning 
    // and end of the edge and adds the edge
    virtual void AddEdge(int from, int to) = 0;

    // The method counts the current number of vertices
    virtual int VerticesCount() const = 0;

    // For a specific vertex, the method outputs to the "vertex" vector
    // all vertices that can be reached along the edge from the given
    virtual void GetNextVertices(int vertex
                                , std::vector<int> &vertices) const = 0;

    // For a specific vertex, the method outputs to the "vertex" vector 
    // all vertices from which it is possible to walk along the edge 
    // to the given
    virtual void GetPrevVertices(int vertex
                                , std::vector<int> &vertices) const = 0;
};

#endif //IGRAPH_H_SENTRY
