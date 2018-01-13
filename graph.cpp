#include "graph.h"

graph::graph(int s) : __size(s) {
  __nodes.resize(s + 1);
  __edges.resize(s + 1);

  for (int32_t f = 1; f <= __size; ++f) {
    for (int32_t t = 1; t <= f; ++t) {
      if (f != t) {
        float sq = sqrt(f + t);
        if ((sq * sq) == (f + t)) {
          __edges[f].push_back(t);
          __edges[t].push_back(f);
        }
      }
    }
  }
}

void graph::print() {
  for (int32_t f = 1; f <= __size; ++f) {
    std::cout << f << ": ";
    for (auto n : __edges[f]) {
      std::cout << n << ", ";
    }
    std::cout << '\n';
  }
}

std::vector<int32_t> graph::get_starting_nodes() {
  std::vector<int32_t> start_nodes;
  for (int32_t n = 1; n <= __size; ++n) {
    if (__edges[n].size() == 1)
      start_nodes.push_back(n);
  }
  if (start_nodes.size() == 0)
    start_nodes.push_back(1);
  return start_nodes;
}

bool graph::get_hamiltonian_paths_from(int32_t f,
                                       std::vector<int32_t> current_path,
                                       std::vector<std::vector<int32_t>> &paths,
                                       bool find_all) {

  current_path.push_back(f);

  if (current_path.size() == __size) {
    paths.push_back(current_path);
    return true;
  }

  for (auto e : __edges[f]) {
    if (!in(e, current_path)) {
      bool res = get_hamiltonian_paths_from(e, current_path, paths, find_all);
      if (!find_all && res)
        return true;
    }
  }

  return false;
}
