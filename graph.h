#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

class graph {
private:
  int32_t __size;
  std::vector<int32_t> __nodes;
  std::vector<std::vector<int32_t>> __edges;

  static bool in(int32_t v, const std::vector<int32_t> &current_path) {
    return (std::find(current_path.begin(), current_path.end(), v) !=
            current_path.end());
  }

public:
  explicit graph(int s);

  void print();

  std::vector<int32_t> get_starting_nodes();

  bool get_hamiltonian_paths_from(int32_t f, std::vector<int32_t> current_path,
                                  std::vector<std::vector<int32_t>> &paths,
                                  bool find_all = true);
};

#endif // __GRAPH_H__