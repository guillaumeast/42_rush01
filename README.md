# 🏙️ Rush01 — Skyscrapers Solver (v1.2.0)

> _Optimized backtracking solver for the 42 Paris **Rush01** puzzle.  
> v1.2.0 introduces early pruning based on partial visibility counts, achieving sub-millisecond solves up to 9×9._

[![Language: C](https://img.shields.io/badge/language-C-lightgrey)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Type: CLI](https://img.shields.io/badge/type-CLI-8b949e)]()
[![Platform: macOS/Linux](https://img.shields.io/badge/platform-macOS%20%26%20Linux-blue)](https://en.wikipedia.org/wiki/Unix-like)
[![Status: v1.2.0 (baseline)](https://img.shields.io/badge/status-v1.2.0%20baseline-darkgreen)]()

---

## 🎓 Context

This project is part of the **42 Piscine / Rush** series. It solves the classic **Skyscrapers** puzzle (a.k.a. _Rush01_): fill an `n×n` grid with values `1..n` so that each row/column contains all numbers once, and each side clue indicates how many “buildings” are visible from that side.

---

## 🎯 Objective

- Parse command-line input of `4*n` edge clues (top, bottom, left, right).
- Pre-fill **obvious values** before backtracking:
	- If clue = `n` → the entire row/column is `{1..n}` in the correct direction.
	- If clue = `1` → the first cell on the clue side is set to `n`.
- **Early pruning** based on partial visibility counts:
	- Dynamically check partial rows/columns against their visibility clues.
	- Stop recursion early when the current state can no longer match the clue.
- Print the resulting grid to `stdout`, or `Error\n` when no solution exists or input is invalid.
- Keep the code **Norm-friendly** and simple for learning/debugging.

---

## 🗂️ Repository Structure (v1.2.0)

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

| Size | v1.0.0 (baseline) | v1.1.0 (obvious values) | v1.2.0 (early pruning) |
|------|--------------------|-------------------------|------------------------|
| 3×3  | < 1 ms             | < 1 ms                  | < 1 ms                 |
| 4×4  | < 1 ms             | < 1 ms                  | < 1 ms                 |
| 5×5  | < 1 ms             | < 1 ms                  | < 1 ms                 |
| 6×6  | 66 ms              | 4 ms                    | < 1 ms                 |
| 7×7  | ~600 000 ms        | ~5 000 ms               | < 1 ms                 |
| 8×8  | > 30 min           | > 30 min                | < 1 ms                 |
| 9×9  | > 30 min           | > 30 min                | < 1 ms                 |

> v1.1.0 added a **pre-filling** of obvious values (for clue = 1 and clue = n).
> v1.2.0 introduces **real-time pruning** of impossible branches using partial visibility checks.  
> With this, the solver reaches **sub-millisecond** performance up to 9×9 grids. ⚡️

---

> _“From brute force to elegance — one segfault at a time.”_ 🧠
