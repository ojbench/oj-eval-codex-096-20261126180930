# Solution

Read and retain the queries, then parse the extended preorder traversal using
a stack of pending subtree positions. Each position records its parent and
depth. A null marker consumes one position; a real node records its metadata
and creates two child positions. Pushing the right position before the left
preserves preorder. The stack avoids recursive call depth on skewed trees.

Two existing nodes are cousins exactly when their stored depths agree and
their stored parents differ. Missing query values return zero.

Every subtree position is processed once, so preprocessing takes O(n) time.
Each query takes O(1) time. Total time is O(n + q), with O(n + q + V) memory,
where V = 1001 is the value lookup table size.

## Validation

- Built with the judge's `cmake .` and `make` workflow using GCC 13.
- Passed the README sample.
- Passed 212,000 reference-checked queries across 106 generated trees,
  including empty, singleton, and 1000-node trees (random seed 2444).
- Passed left- and right-skewed 1000-node tree checks.
- The advertised `/workspace/data/096/data_test/` directory was unavailable.
