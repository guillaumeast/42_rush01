# 🏙️ Rush01 — Skyscrapers Solver (v1.0.0)

> _Baseline implementation (backtracking) for the 42 Paris **Rush01** puzzle. This is the unoptimized v1.0.0 used as a reference before performance work._

[![Language: C](https://img.shields.io/badge/language-C-lightgrey)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Type: CLI](https://img.shields.io/badge/type-CLI-8b949e)]()
[![Platform: macOS/Linux](https://img.shields.io/badge/platform-macOS%20%26%20Linux-blue)](https://en.wikipedia.org/wiki/Unix-like)
[![Status: v1.0.0 (baseline)](https://img.shields.io/badge/status-v1.0.0%20baseline-darkgreen)]()

---

## 🎓 Context

This project is part of the **42 Piscine / Rush** series. It solves the classic **Skyscrapers** puzzle (a.k.a. _Rush01_): fill an `n×n` grid with values `1..n` so that each row/column contains all numbers once, and each side clue indicates how many “buildings” are visible from that side.

This repository pins the **baseline (v1.0.0)** version *before* any optimization (no bitmasks, no advanced pruning). It serves as a **ground truth** to measure future performance improvements.

---

## 🎯 Objective

- Parse command-line input of `4*n` edge clues (top, bottom, left, right).
- Build and solve an `n×n` grid using **pure backtracking** with basic validity checks.
- Print the resulting grid to `stdout`, or `Error\n` when no solution exists or input is invalid.
- Keep the code **Norm-friendly** and simple for learning/debugging.

---

## 🗂️ Repository Structure (v1.0.0)

```
.
├── ex00
│   ├── includes
│   │   ├── args.h
│   │   ├── check.h
│   │   ├── map.h
│   │   ├── print.h
│   │   ├── run.h
│   │   ├── rush01.h
│   │   ├── solve.h
│   │   └── types.h
│   ├── Makefile
│   └── srcs
│       ├── args.c
│       ├── check.c
│       ├── main.c
│       ├── map.c
│       ├── print.c
│       ├── run.c
│       └── solve.c
├── rush01.en.subject.pdf
├── tests.txt
├── time.txt
└── todo.txt
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

## 🧪 Performance (Baseline v1.0.0)

Results measured on the author’s machine (macOS / Apple M4 / Xcode Time Profiler / main() execution time):

| Size | Time          |
|------|---------------|
| 3×3  | < 1 ms        |
| 4×4  | < 1 ms        |
| 5×5  | < 1 ms        |
| 6×6  | 66 ms         |
| 7×7  | 652 200 ms    |
| 8×8  | n.a.          |
| 9×9  | n.a.          |

> The baseline solver uses naive backtracking with a full-row/full-column uniqueness scan and final clue checks. This is intentionally slow on large sizes to serve as a reference point for the upcoming optimization steps.

---

## 🛣️ Roadmap (next versions)

| Version | Focus | Description |
|----------|--------|-------------|
| **v1.1.0 — Fix obvious values** | Pre-fill cells that are already determined before backtracking. | <ul><li>Add `t_bool **fixed[row][col]`.</li><li>If clue = *n* → row/column = { 1, 2, …, n }.</li><li>If clue = 1 → first cell on the clue side = *n*.</li></ul> |
| **v1.2.0 — Prune earlier** | Stop exploring impossible branches earlier based on partial visibility counts. | <ul><li>Compute `count_so_far` and `available_cells`.</li><li>If `count_so_far > clue` → prune.</li><li>If `count_so_far + available_cells < clue` → prune.</li></ul> |
| **v1.3.0 — Store used values** | Avoid scanning entire rows/columns when trying a value. | <ul><li>Add `t_bool **used[row][val]` and `t_bool **used[col][val]`.</li><li>If `used[row][val]` or `used[col][val]` → immediate prune.</li></ul> |
| **v1.4.0 — Simplify data structure** | Simplify global data flow. | <ul><li>Remove `t_run` and streamline data passing.</li></ul> |
| **v2.0.0 — Low-level optimization** | Work directly on bytes for compact representation. | <ul><li>Explore bitmasks or similar low-level techniques.</li></ul> |

Each step will include **reproducible benchmarks** and a **CHANGELOG** entry.

---

> _“From brute force to elegance — one segfault at a time.”_ 🧠
