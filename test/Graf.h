#include <vector>
#include <string>
#include "Podminka.h"

#ifndef GRAF_H
#define GRAF_H

template <typename T>
class Graf
{
public:
	Graf(int nodeCount) : _nodeCount(nodeCount) {
		_nodes = new GrafNode[_nodeCount];

		for (int i = 0; i < _nodeCount; i++) {
			_nodes[i] = new GrafNode<T>(i);
		}
	};
	~Graf() {
		for (int i = 0; i < _nodeCount; i++) {
			delete _nodes[i];
		}
		delete[] _nodes;
	};

	void validateBounds(int nodeNr) {
		for (int i = 0; i < _nodeCount; i++)
		{
			if (_nodes[i].GetId() == nodeNr) {
				return;
			}
		}
			throw Podminka("Neplatne cislo uzel");
	}

	void addEdge(int from, int to) {
		validateBounds(from);
		validateBounds(to);
		_nodes[from].getSuccessors().add(_nodes[to]);
	}

private:
	struct GrafNode {
	public:
		GrafNode() {};
		GrafNode(int id, T value) : _id(id), _data(value) {};

		~GrafNode() {};

		int GetId() const {
			return _id;
		}
		std::vector<GrafNode> GetSuccessors() {
			return _successors;
		}

		std::string GetDataString() {
			return std::to_string(_data) + " " + std::to_string(_id);
		}
	private:
		int _id;
		std::vector<GrafNode> _successors;
		T _data;
	};

	GrafNode* _nodes[];
	int _nodeCount;
};



/*
public class LinkedGraphNode<ENTITY> implements GraphNodeIface<ENTITY> {








}*/
#endif // !GRAF_H
