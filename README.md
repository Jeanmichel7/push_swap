# Push Swap - 42 School Project

## 📋 Résumé

Le projet "Push Swap" vise à trier une pile d'entiers en utilisant un ensemble spécifique d'instructions et deux piles, `pile a` et `pile b`. Ce projet comporte également une partie bonus pour créer un "checker", qui valide si une liste d'instructions trie effectivement la pile.

## 💻 Technologies Utilisées

- Langage C
- Makefile pour l'automatisation

## 📦 Installation

```bash
git clone https://github.com/Jeanmichel7/push_swap.git
cd push_swap
make
```

## 📜 Règles du Projet

- Les instructions valides sont : `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.
- La pile doit être triée en utilisant le moins d'instructions possible.

## 🛠️ Utilisation

Pour utiliser le programme "push_swap":

```bash
./push_swap 4 3 2 1
./push_swap "4 3 2 1"
```

Cela générera une série d'instructions pour trier la pile.

## 🎯 Partie Bonus: Checker

Pour utiliser le programme bonus "checker":

## 📦 Installation

```bash
git clone https://github.com/Jeanmichel7/push_swap.git
cd push_swap
make bonus
```

```bash
./checker 3 2 1 0
```

Suivez les instructions à l'écran et entrez les commandes une par une, suivies d'un retour à la ligne.

Exemples:

```bash
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
Affiche "OK"
```

```bash
$>./checker 3 2 1 0
sa
rra
pb
Affiche "KO"
```
