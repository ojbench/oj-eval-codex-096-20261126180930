#include <array>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int query_count;
    if (!(std::cin >> query_count)) return 0;
    std::vector<std::pair<int, int>> queries(query_count);
    for (auto& query : queries) std::cin >> query.first >> query.second;

    constexpr int max_value = 1000;
    std::array<int, max_value + 1> parent{};
    std::array<int, max_value + 1> depth{};
    depth.fill(-1);

    // Pending subtree positions store their parent and depth, in preorder order.
    std::vector<std::pair<int, int>> pending{{0, 0}};
    while (!pending.empty()) {
        const auto [parent_value, node_depth] = pending.back();
        pending.pop_back();
        int value;
        if (!(std::cin >> value)) return 0;
        if (value == -1) continue;
        parent[value] = parent_value;
        depth[value] = node_depth;
        // Push right before left; both positions have the same metadata.
        pending.emplace_back(value, node_depth + 1);
        pending.emplace_back(value, node_depth + 1);
    }

    for (const auto& [x, y] : queries) {
        const bool present = x >= 1 && x <= max_value &&
                             y >= 1 && y <= max_value &&
                             depth[x] != -1 && depth[y] != -1;
        std::cout << (present && depth[x] == depth[y] && parent[x] != parent[y])
                  << '\n';
    }
}
