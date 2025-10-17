## [1.2.0] — 2025-10-18
### Added
- **Early pruning** based on partial visibility counts:
  - Each row and column is dynamically checked while filling the grid.
  - The solver stops exploring branches where the current state cannot match the clue anymore.
- Integrated pruning logic directly into `check_cell()` for efficient in-place validation.

### Performance improvement
| Size | v1.0.0 (baseline)  | v1.1.0 (obvious values) | v1.2.0 (early pruning) |
|------|--------------------|-------------------------|------------------------|
| 3×3  | < 1 ms             | < 1 ms                  | < 1 ms                 |
| 4×4  | < 1 ms             | < 1 ms                  | < 1 ms                 |
| 5×5  | < 1 ms             | < 1 ms                  | < 1 ms                 |
| 6×6  | 66 ms              | 4 ms                    | < 1 ms                 |
| 7×7  | ~600 000 ms        | ~5 000 ms               | < 1 ms                 |
| 8×8  | > 30 min           | > 30 min                | < 1 ms                 |
| 9×9  | > 30 min           | > 30 min                | < 1 ms                 |

---

## [1.1.0] — 2025-10-17
### Added
- Pre-filling of **obvious values** before backtracking:
  - `clue == n` → the row/column is forced to `{1..n}` in the correct direction.
  - `clue == 1` → the first cell on the clue side is set to `n`.
- Added a new `t_bool **fixed` grid to mark prefilled cells and **skip** them during recursion.

### Performance improvement
| Size | v1.0.0 (baseline)  | v1.1.0 (obvious values) |
|------|--------------------|-------------------------|
| 3×3  | < 1 ms             | < 1 ms                  |
| 4×4  | < 1 ms             | < 1 ms                  |
| 5×5  | < 1 ms             | < 1 ms                  |
| 6×6  | 66 ms              | 4 ms                    |
| 7×7  | ~600 000 ms        | ~5 000 ms               |
| 8×8  | > 30 min           | > 30 min                |
| 9×9  | > 30 min           | > 30 min                |

---

## [1.0.0]
Initial baseline version (unoptimized).
- Pure backtracking solver.
- Full uniqueness checks per row/column.
- No pruning or prefilled cells.
- Reference for future performance improvements.

### Performance
| Size | v1.0.0 (baseline)  |
|------|--------------------|
| 3×3  | < 1 ms             |
| 4×4  | < 1 ms             |
| 5×5  | < 1 ms             |
| 6×6  | 66 ms              |
| 7×7  | ~600 000 ms        |
| 8×8  | > 30 min           |
| 9×9  | > 30 min           |
