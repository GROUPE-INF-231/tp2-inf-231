# Cahier de suivi – Jean Joël Abondo (Matricule 23V2214)

## Informations générales

- **Prénom** : Jean Joël
- **Nom** : Abondo
- **Matricule** : 23V2214
- **Fichier principal** : InsertListeDoubleTrie.c

---

## Objectif du programme

Ce programme résout le problème suivant :  
**Insérer un entier dans une liste doublement chaînée triée, tout en maintenant l’ordre croissant de la liste.**  
L’enjeu principal est de garantir que, après chaque insertion, la structure reste triée et cohérente sans désorganisation des maillons.

---

## Principe et méthode utilisée

- La liste est parcourue à partir de la tête, jusqu’à trouver la position où l’élément doit être inséré pour conserver l’ordre.
- Trois cas sont gérés :
  1. **Insertion en tête** : si l’élément à insérer est plus petit que tous les éléments existants.
  2. **Insertion en queue** : si l’élément à insérer est plus grand que tous les éléments existants.
  3. **Insertion au milieu** : si l’élément doit être inséré entre deux éléments existants.
- À chaque insertion, les pointeurs `prev` et `next` des maillons sont correctement mis à jour pour préserver la structure doublement chaînée.

---

## Compilation

Dans le terminal, placez-vous dans le dossier contenant le fichier InsertListeDoubleTrie.c et tapez :
```bash
gcc -Wall -o InsertListeDoubleTrie InsertListeDoubleTrie.c
```
- `-Wall` pour activer les avertissements du compilateur.
- `-o InsertListeDoubleTrie` pour nommer l’exécutable obtenu.

---

## Exécution

Pour lancer le programme compilé, entrez simplement :
```bash
./InsertListeDoubleTrie
```

---

## Collaboration

Ma contribution collaborative s’est également traduite par l’appréciation et la validation commune des différents programmes uploadés par l’équipe. Chaque programme a été discuté et validé collectivement pour assurer la cohérence et la qualité du travail réalisé.

---

## Historique des actions

- Rédaction, test et mise en ligne du fichier InsertListeDoubleTrie.c
- Participation à la validation collective des travaux sur le dépôt.
