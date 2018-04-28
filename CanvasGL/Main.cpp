#include <iostream>
#include "CanvasApp.h"
#include "CLine.h"

int main(int argc, char *argv[]) {

	std::cout << "======================= CANVAS GL ALPHA 0.1 =======================" << std::endl << std::endl;
	std::cout << "  Shortcuts:" << std::endl << std::endl
		<< "    Arrows    : Move Camera;" << std::endl
		<< "    W,A,S,D   : Move Objects;" << std::endl
		<< "    TAB       : Switch between objects;" << std::endl
		<< "    R         : Rotate object" << std::endl;
	std::cout << std::endl << "============================== LOG ================================" << std::endl;


	CanvasApp::Start(argc, argv);

	return EXIT_SUCCESS;

}