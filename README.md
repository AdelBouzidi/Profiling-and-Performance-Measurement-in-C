# Debugging and Profiling in C

Projet académique réalisé dans le cadre d’un travail pratique portant sur le debugging, le profiling et l’analyse des performances d’un programme numérique en C.

Le projet consiste à implémenter et analyser une version simple de `ssgemm`, puis à utiliser différents outils de debugging et de profiling afin d’identifier les erreurs et mesurer les performances d’exécution.

---

# Objectifs du projet

- Implémentation d’une version simple de `ssgemm`
- Utilisation d’outils de debugging et de profiling
- Analyse des performances d’exécution
- Mesure des temps d’exécution et des cycles processeur
- Étude du comportement du programme au niveau bas niveau

---

# Technologies et outils utilisés

- C
- Makefile
- Linux
- GDB
- GProf
- Perf
- `rdtsc`

---

# Structure du projet

```text
.
├── README.md
├── Rapport.pdf
├── Makefile
├── include/
├── src/
├── tests/
├── logs/
├── gprof_report.txt
└── profiling_report.txt
```

---

# Compilation du projet

```bash
make
```

Nettoyage :

```bash
make clean
```

---

# Debugging avec GDB

```bash
gdb ./test.exe
```

---

# Mesure des performances

Temps d’exécution :

```bash
time ./test.exe
```

Mesure des performances CPU :

```bash
perf stat ./test.exe
```

---

# Profiling avec GProf

Compilation avec support de profiling :

```bash
gcc -pg
```

Génération du rapport :

```bash
gprof ./test.exe gmon.out > gprof_report.txt
```

---

# Concepts abordés

- Debugging avec GDB
- Profiling avec GProf
- Analyse de performances avec Perf
- Mesure des cycles processeur
- Fonction `rdtsc`
- Programmation système sous Linux

---

# Rapport

Le rapport complet du projet est disponible dans le dépôt et contient :

- les étapes d’implémentation
- les analyses de debugging
- les mesures de performances
- les résultats des outils de profiling
