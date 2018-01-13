#include "graph.h"
#include <cstdint>
#include <iostream>
#include <vector>

int main(int argc, char **argv) {
  int32_t min = 10;
  int32_t max = 10;

  if (argc > 1) {
    min = std::stoi(argv[1]);
    max = std::stoi(argv[2]);
  }

  for (int32_t n = min; n <= max; ++n) {
    std::cout
        << "============================================================\n";
    graph g(n);

    std::vector<int32_t> start_nodes = g.get_starting_nodes();
    // g.print();

    bool find_all = false;
    std::vector<std::vector<int32_t>> all_paths;
    for (auto f : start_nodes) {
      std::vector<int32_t> begin_path;
      bool res =
          g.get_hamiltonian_paths_from(f, begin_path, all_paths, find_all);
      if (!find_all && res)
        break;
    }
    std::cout << "Number of paths found for " << n << ": " << all_paths.size()
              << '\n';

    for (auto p : all_paths) {
      for (auto n : p) {
        std::cout << n << ",";
      }
      std::cout << '\n';
    }
  }
  return 0;
}