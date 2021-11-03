#include <iostream>

#include"Parser.h"
#include "Shape.h"
#include "Visualizer.h"
#include "ShapeTree.h"

using namespace std;


int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "You need to supply a mode and a rule file." << std::endl;
		std::cout << argv[0] << " <mode> <rule file>" << std::endl;
		std::cout << argv[0] << " <mode> <rule file>" << std::endl;
		std::cout << "Mode 0 for drawing, 1 for tree" << std::endl;
		return 0;
	}
	Parser parser(argv[2]);
	auto rules = parser.parseRules();
	ShapeTree tree;
	Shape shape = Shape("main", Vector3D(0,0,0), Vector3D(40, 120, 80), SCOPE);
	tree.buildTree(rules, shape);
	auto nodes = tree.getLeafNodes();

	if (std::atoi(argv[1])) {
		drawDerivationTree(tree, argc, argv);
	} else {
		drawShapes(nodes, argc, argv);
	}
	return 0;
}