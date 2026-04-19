# MSG
A small snake game

---

## Getting started
This project is written in **C**.

### Features
- Controls with arrows or keys: W for up, S for down, A for left and D for right
- Point counting
- Colorful interface
---

### Requirements
Make sure to have `gcc`, `make`, `git` and ncurses development library programs installed on your system.
You can use your package manager (apt: `gcc make git ncurses-dev`, dnf: `gcc make git ncurses-devel`).

---

1. **Download sources**
   Clone project's repo with `git`:
   ```bash
   git clone https://github.com/Micha1207/MSG.git
   cd MSG
   ```

   Or download ZIP file directly from [project's GitHub page](https://github.com/Micha1207/MSG) and extract it.

2. **Compilation**:
   To compile this project, run `make` in project directory.

3. **Usage**:
   - To run directly: `./msg`
   - To install system-wide: `make install`. Make sure, to run as root.
   - Clean: `make clean` removes object files and binary.
