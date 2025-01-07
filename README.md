# Projet C++ : Gestion des Circonscriptions Électorales

## Introduction

Ce projet, développé dans le cadre d'un cours de programmation en C++, a pour objectif de gérer les circonscriptions électorales en utilisant une approche orientée objet. Il s'agit de mon premier projet en C++, dans lequel j'ai ajouté des fonctionnalités pour me distinguer. 

Deux fichiers spécifiques, `ContratException` et `Date`, ont été fournis par mon professeur et utilisés tels quels dans ce projet.

## Fonctionnalités principales

Le programme permet :

- **Gestion des candidats et électeurs** :
  - Ajout de candidats et d'électeurs avec des informations détaillées (nom, prénom, NAS, adresse,date de naissance, parti politique).
  - Suppression des personnes inscrites grâce à leur NAS.
  - Affichage des informations détaillées des candidats et électeurs.
- **Validation des données** :
  - Vérification des formats du NAS et des dates.
  - Gestion des erreurs grâce à des exceptions personnalisées.
- **Interfaces graphiques** :
  - Formulaires interactifs pour l'ajout et la suppression de personnes.
  - Tableau pour visualiser les inscrits dans une circonscription.

## Interfaces graphiques

Voici des aperçus des interfaces graphiques développées avec Qt :

1. **Fenêtre principale** :
   - Affichage des candidats et électeurs enregistrés.
   - Navigation intuitive pour ajouter ou supprimer des personnes.
  ![image](https://github.com/user-attachments/assets/f41f9cd7-64fe-45c5-82f7-4872e25f1e19)

2. **Formulaire d'ajout de candidats** :
   - Saisie des informations nécessaires pour enregistrer un nouveau candidat.
     
![image](https://github.com/user-attachments/assets/626c8a6c-c3fb-48e7-a56d-c30b9a8c70fc)

3. **Formulaire d'ajout d'électeurs** :
   - Interface similaire pour ajouter un électeur.
   
![image](https://github.com/user-attachments/assets/2979e671-e094-40a3-bfd2-a54d642e2907)

4. **Formulaire de suppression** :
   - Suppression d'une personne par son NAS.
     
![image](https://github.com/user-attachments/assets/c6ce17e4-a99e-4f37-a606-d9e01d7859bb)


## Structure du projet

Le projet est organisé en deux principaux dossiers :

### 1. **Dossier Source**

- **Ajout de personnes** :
  - `AjoutCandidat.cpp`, `AjoutCandidat.h` : Gestion des candidats.
  - `AjoutElecteur.cpp`, `AjoutElecteur.h` : Gestion des électeurs.

- **Classes principales** :
  - `Personne.cpp`, `Personne.h` : Classe abstraite représentant une personne.
  - `Candidat.cpp`, `Candidat.h` : Classe dérivée pour les candidats.
  - `Electeur.cpp`, `Electeur.h` : Classe dérivée pour les électeurs.
  - `Circonscription.cpp`, `Circonscription.h` : Gestion des listes électorales d'une circonscription.

- **Fichiers utilitaires** :
  - `ContratException.cpp`, `ContratException.h` : Gestion des exceptions via la théorie des contrats (fourni par le professeur Mr Thierry Eude).
  - `Date.cpp`, `Date.h` : Gestion des dates (fourni par le professeur Mr Thierry Eude).
  - `ValidationFormat.cpp`, `ValidationFormat.h` : Fonctions utilitaires pour valider les formats des données.

- **Gestion des erreurs spécifiques** :
  - `PersonneException.h` : Gestion des erreurs liées aux personnes (déjà présentes ou absentes).

### 2. **Dossier CirconscriptionGUI**

- **Interfaces graphiques** :
  - `PersonneGUI.cpp`, `PersonneGUI.h` : Fenêtre principale du programme.
  - `AjoutCandidat.cpp`, `AjoutCandidat.h` : Fenêtre d'ajout des candidats.
  - `AjoutElecteur.cpp`, `AjoutElecteur.h` : Fenêtre d'ajout des electeurs.
  - `SupprimerPersonne.cpp`, `SupprimerPersonne.h` : Fenêtre de suppression d'un candidat ou un electeur.

## Compilation et Exécution

### Prérequis
- **IDE** : Netbeans , CLion ....
- **Qt Framework** : Ce projet utilise Qt pour les interfaces graphiques.
- **Compilateur C++** : Compatible avec le standard C++11 ou supérieur.

### Étapes de compilation

1. Ouvrez le projet dans Netbeans.
2. Configurez les paramètres de compilation, googletest...
3. Compilez le projet.

### Exécution

Une fois la compilation terminée, exécutez le projet en cliquant sur Run Project dans le fichier main.cpp du projet CirconscriptionGUI

### Démonstration Vidéo

Regardez la démonstration complète du projet ici : [Vidéo YouTube]([https://www.youtube.com/watch?v=VOTRE_LIEN](https://youtu.be/_ykolxQODEc?si=imch2jmqlFKR4UkD))





## Conclusion

Ce projet a été une excellente opportunité pour :

- Mettre en pratique les concepts de la programmation orientée objet.
- Apprendre à gérer les erreurs et valider les données.
- Développer des interfaces graphiques simples avec Qt.

Je remercie mon professeur Mr Thierry Eude pour les fichiers de base fournis et les connaissances partagées durant le cours GIF-1003. Ce projet marque un premier pas important dans ma maîtrise du C++.

## Licence

Ce projet est distribué sous la licence MIT. Vous êtes libre de l'utiliser, de le modifier et de le distribuer, à condition de conserver cette licence dans toutes les copies ou dérivés.

```text
MIT License

Copyright (c) 2025 Rayyane Houmine

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

