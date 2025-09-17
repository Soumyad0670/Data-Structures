# 📚 Data Structures — Soumyadeep Dutta

> A clean, commented collection of core data structures implemented in C (or your chosen language). Great for learning, interview prep & strengthening foundations.

---

## 🚀 Table of Contents

1. [About](#about)  
2. [Features](#features)  
3. [Folder/Project Structure](#folderproject-structure)  
4. [Getting Started](#getting-started)  
5. [Examples & Usage](#examples--usage)  
6. [Interactive Learning](#interactive-learning)  
7. [How to Contribute](#how-to-contribute)  
8. [License](#license)  
9. [Author](#author)

---

## 🔍 About

This repo contains implementations of classic data structures:

- Arrays, Linked Lists (Singly, Doubly, Circular)  
- Stacks & Queues  
- Trees (Binary, Binary Search Tree, etc.)  
- Graphs  
- Sorting & Searching algorithms  
- Other helpful utilities

Each piece of code is:

- **Commented** — to show what's happening under the hood  
- **Standalone** — you can test each file independently  
- **Lightweight** — minimal external dependencies (just C compiler / standard library)  
- **Ideal for interviews & learning**  

---

## ✨ Features

| ✔️ Feature | Description |
|------------|-------------|
| Pure implementation | No library data structures — you write them from scratch. |
| Clear code & modular | Each data structure has its own file / module. |
| Easy to test | Run single files, verify behavior via sample inputs. |
| Educational comments | Each operation explained (e.g. insert, delete, traversal). |
| Covering essentials | Covers common DS & algorithms you’ll see in interviews. |

---

## 📁 Folder / Project Structure

```text
Data-Structures/
├── Linked Lists/
│   ├── singly_linked_list.c
│   ├── doubly_linked_list.c
│   └── circular_linked_list.c
├── Stacks and Queues/
│   ├── stack.c
│   ├── queue_array.c
│   ├── queue_linked_list.c
│   └── circular_queue.c
├── Trees/
│   ├── tree.c
│   ├── binary_search_tree.c
│   └── (other tree algorithms)
├── Graphs/
│   ├── adjacency_list.c
│   ├── DFS.c
│   ├── BFS.c
│   └── shortest_path.c
├── Sorting/
│   ├── bubble_sort.c
│   ├── merge_sort.c
│   ├── quick_sort.c
│   └── insertion_sort.c
└── Utilities/
    ├── menu_driven.c
    ├── helper_functions.c
    └── …

*(Adjust the names/folders if your code layout is slightly different.)*

---

## 🧰 Getting Started

Here’s how you can run and test individual files.

### Prerequisites

* C compiler (e.g. `gcc`)
* Make / build tools (optional, if you want to make a Makefile)
* Basic terminal / command prompt usage

### Clone the repo

```bash
git clone https://github.com/Soumyad0670/Data-Structures.git
cd Data-Structures
```

### Compile & Run a File

Suppose you want to run `linked_list.c`:

```bash
gcc Linked\ Lists/singly_linked_list.c -o singly_linked_list
./singly_linked_list
```

Or if there is a menu-driven version:

```bash
gcc Utilities/menu_driven_LL.c -o menuLL
./menuLL
```

---

## 📊 Examples & Usage

Here are some sample runs / screenshots (if possible):

| Data Structure       | Operation                      | Expected Output / Behavior                          |
| -------------------- | ------------------------------ | --------------------------------------------------- |
| Singly Linked List   | Insert at head / tail / delete | Prints list contents in order, deletes correct node |
| Binary Search Tree   | Insert & Search                | Should indicate whether a number exists or not      |
| Sorting (Quick Sort) | Sort unsorted array            | Sorted output (verified)                            |

> Tip: You can add your own test inputs by editing the `main` in files or writing wrapper code.

---

## ⚙️ Interactive Learning

To make this repo more “hands-on” for users, you might:

* ✅ Add **menu-driven programs** for many DS: let user pick operations
* ✅ Write some **tests** with sample inputs (you can use a script or small driver)
* ✅ Provide small “challenges” / “TODOs” in code: e.g. “Implement reverse-in-groups in linked list”
* ✅ Add **visual diagrams** (in README) or link to external ones
* ✅ Or use something like **TUI (text-based UI)** in C for simple interactivity

---

## 🤝 How to Contribute

Love to have your help! Steps:

1. Fork the repository
2. Create a branch:

   ```bash
   git checkout -b feature/<your-feature>
   ```
3. Add your data structure / algorithm, with tests / sample usage
4. Commit your changes:

   ```bash
   git add .
   git commit -m "Add <Name-of-DS> / Fix <issue>"
   ```
5. Push to your fork and make a Pull Request

Make sure code is clean, commented, and compiles without errors.

---

## 📝 License

This project is open-source; feel free to use / modify / distribute.

Licensed under **MIT License** — see [LICENSE](LICENSE) for details.

---
