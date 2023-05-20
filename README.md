# MiniHack Spring 2023 Git Puzzle

Welcome to MiniHack's Git Good puzzle!

We found the Evil Minion bugs using the following methodology:

- We used `git blame` on the HEAD commit `e28882`. We noticed bugs in BELLO and
  checked which lines were buggy, and which commit ID's these were attributed to.
- We found both commits in one shot: `ee321403` and `ab9bc26c`
- We used `git diff` to generate diff files showing the changes in each
  malicious commit. We were then able to fix the commits.

Bugs found:

- Adding too many characters, or using loops incorrectly.

Look here to get started

- [Link to Puzzle Spec](https://docs.google.com/document/d/1liSQt-XAfyyEVkuwCPXu3S8veBe8c6_P2vnIRU6RCpg/edit?usp=sharing)
- [Link to Slides](https://docs.google.com/presentation/d/1F5RhFQf6wL2ZlPuHPojoFckWtyn7v3m3-J0q34kCHvk/edit?usp=sharing)
