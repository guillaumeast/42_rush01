## [1.1.0] — 2025-10-17
### Added
- Pre-filling of **obvious values** before backtracking:
  - `clue == n` → the row/column is forced to `{1..n}` in the correct direction.
  - `clue == 1` → the first cell on the clue side is set to `n`.
- Added a new `t_bool **fixed` grid to mark prefilled cells and **skip** them during recursion.

### Performance improvement
- 6×6: **66 ms → 4 ms**
- 7×7: **~600 000 ms → ~5 510 ms**
- 8×8: still n.a. (timeout > 30 min)

---

## [1.0.0]
Initial baseline version (unoptimized).
- Pure backtracking solver.
- Full uniqueness checks per row/column.
- No pruning or prefilled cells.
- Reference for future performance improvements.
