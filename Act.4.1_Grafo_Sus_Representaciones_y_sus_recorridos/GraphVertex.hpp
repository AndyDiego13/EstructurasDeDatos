/* 

*/

#ifndef GraphVertex_hpp
#define GraphVertex_hpp

#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>

template <class T>
class GraphVertex
{
    private:
        T val;
        std::vector<int> adj;

    public:
        ~GraphVertex() {};
        GraphVertex() {};

        GraphVertex(T _val)
        {
            val = _val;
        }


        T getVal()
        {
            return val;
        }

        void setVal(T _val)
        {
            val = _val;
        }

        std::vector<int> getAdj()
        {
            return adj;
        }

        void addToAdj(int idx)
        {
            adj.push_back(idx);
        }
};

#endif // !GraphVertex_hpp
