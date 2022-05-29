// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> derevoSlov;
  std::ifstream file(filename);
  if (!file) {
        std::cout << "File error!" << std::endl;
        return derevoSlov;
    }

  std::string textForTree = "";
  while (!file.eof()) {
    char symbForTree = file.get();
    if (symbForTree > 64 && symbForTree < 91) {
      textForTree += tolower(symbForTree);
    } else if (symbForTree > 96 && symbForTree < 123) {
      textForTree += symbForTree;
    } else {
      derevoSlov.add(textForTree);
      textForTree = "";
    }
  }
file.close();
return derevoSlov;
}
