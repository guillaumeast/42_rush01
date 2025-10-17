# 🏙️ Rush01 — Skyscrapers Solver (v1.1.0)

> _Baseline implementation (backtracking) for the 42 Paris **Rush01** puzzle. This is the unoptimized v1.1.0 used as a reference before performance work._

[![Language: C](https://img.shields.io/badge/language-C-lightgrey)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Type: CLI](https://img.shields.io/badge/type-CLI-8b949e)]()
[![Platform: macOS/Linux](https://img.shields.io/badge/platform-macOS%20%26%20Linux-blue)](https://en.wikipedia.org/wiki/Unix-like)
[![Status: v1.1.0 (baseline)](https://img.shields.io/badge/status-v1.1.0%20baseline-darkgreen)]()

---

## 🎓 Context

This project is part of the **42 Piscine / Rush** series. It solves the classic **Skyscrapers** puzzle (a.k.a. _Rush01_): fill an `n×n` grid with values `1..n` so that each row/column contains all numbers once, and each side clue indicates how many “buildings” are visible from that side.

---

## 🎯 Objective

- Parse command-line input of `4*n` edge clues (top, bottom, left, right).
- Pre-fill **obvious values** before backtracking:
	- If clue = `n` → the entire row/column is `{1..n}` in the correct direction.
	- If clue = `1` → the first cell on the clue side is set to `n`.
- Print the resulting grid to `stdout`, or `Error\n` when no solution exists or input is invalid.
- Keep the code **Norm-friendly** and simple for learning/debugging.

---

## 🗂️ Repository Structure (v1.1.0)

```
.
├── CHANGELOG.md
├── ex00
│   ├── includes
│   │   ├── args.h
│   │   ├── check.h
│   │   ├── fix_max.h
│   │   ├── fix_min.h
│   │   ├── map.h
│   │   ├── print.h
│   │   ├── run.h
│   │   ├── rush01.h
│   │   ├── solve.h
│   │   └── types.h
│   ├── Makefile
│   └── srcs
│       ├── args.c
│       ├── check.c
│       ├── main.c
│       ├── map.c
│       ├── print.c
│       ├── run.c
│       └── solver
│           ├── fix_max.c
│           ├── fix_min.c
│           └── solve.c
├── README.md
├── rush01.en.subject.pdf
└── tests.txt
```

> Subject included: [rush01.en.subject.pdf](./rush01.en.subject.pdf)

---

## ⚙️ Build

From `ex00/`:

```bash
make
# produces ./rush-01
```

Clean targets:
```bash
make clean   # remove objects
make fclean  # remove objects + binary
make re      # full rebuild
```

---

## ▶️ Run

The program expects **4*n clues** (top, bottom, left, right order) as a **single argument list**.  
Example for 6×6:
```bash
./rush01 "6 5 4 3 2 1 1 2 2 2 2 2 6 5 4 3 2 1 1 2 2 2 2 2"
```

Successful output prints the solved grid:
```
1 2 3 4 5 6
2 3 4 5 6 1
3 4 5 6 1 2
4 5 6 1 2 3
5 6 1 2 3 4
6 1 2 3 4 5
```

On invalid/unsatisfiable inputs, prints `Error\n`.

> Tip: See `tests.txt` for ready-to-run samples.

---

## 🧪 Performance

Results measured on the author’s machine (macOS / Apple M4 / Xcode Time Profiler / main() execution time):

+| Size | v1.0.0 (baseline) | v1.1.0 (obvious values) |
+|------|--------------------|-------------------------|
+| 3×3  | < 1 ms             | < 1 ms                  |
+| 4×4  | < 1 ms             | < 1 ms                  |
+| 5×5  | < 1 ms             | < 1 ms                  |
+| 6×6  | 66 ms              | **4 ms**                |
+| 7×7  | 652 200 ms         | **5 510 ms**            |
+| 8×8  | n.a.               | n.a. (timeout > 15 min) |
+| 9×9  | n.a.               | n.a.                    |

> v1.1.0 adds a pre-filling of obvious values (no advanced heuristics yet).

---

## 🛣️ Roadmap

| Version | Focus | Description |
|----------|--------|-------------|
+| **v1.1.0 — Fix obvious values (DONE)** | Pre-fill cells that are already determined before backtracking. | <ul><li>Added `t_bool **fixed[row][col]`.</li><li>If clue = *n* → row/column = {1..n} (sens correct).</li><li>If clue = 1 → première case côté indice = *n*.</li></ul> |
| **v1.2.0 — Prune earlier** | Stop exploring impossible branches earlier based on partial visibility counts. | <ul><li>Compute `count_so_far` and `available_cells`.</li><li>If `count_so_far > clue` → prune.</li><li>If `count_so_far + available_cells < clue` → prune.</li></ul> |
| **v1.3.0 — Store used values** | Avoid scanning entire rows/columns when trying a value. | <ul><li>Add `t_bool **used[row][val]` and `t_bool **used[col][val]`.</li><li>If `used[row][val]` or `used[col][val]` → immediate prune.</li></ul> |
| **v1.4.0 — Simplify data structure** | Simplify global data flow. | <ul><li>Remove `t_run` and streamline data passing.</li></ul> |
| **v2.0.0 — Low-level optimization** | Work directly on bytes for compact representation. | <ul><li>Explore bitmasks or similar low-level techniques.</li></ul> |

Each step will include **reproducible benchmarks** and a **CHANGELOG** entry.

---

> _“From brute force to elegance — one segfault at a time.”_ 🧠
