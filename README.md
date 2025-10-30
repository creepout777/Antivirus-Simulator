# 🛡️ Toy Antivirus – Notre projet étudiant

## 👥 Contributeurs
- YASSINE  
- MARWA  
- HAMZA  
- ADAM  
- MALAK  

---

## 📝 À propos du projet

Nous créerons un simulateur antivirus en C pour apprendre à manipuler des fichiers et des signatures avec des listes chaînées.  

💡 Ce projet ne contiendra aucun vrai virus, il servira uniquement à comprendre comment un antivirus fonctionnera :  

- Nous gérerons des fichiers et des signatures  
- Nous implémenterons un scan simple basé sur des patterns  
- Nous déplacerons des fichiers entre listes (Clean, Suspect, Quarantine)  
- Nous créerons une interface CLI pour interagir avec le programme  
- Nous gérerons manuellement la mémoire (`malloc` / `free`)  

---

## 🕒 Chronologie du développement

Voici comment nous construirons notre projet, étape par étape :  

### Étape 1️⃣ : Structures et prototypes

**Fichiers :** `filelist.h` + `siglist.h`  

Nous commencerons par définir `FileRec` et `Sig`, ainsi que toutes les fonctions principales que nous utiliserons ensuite.  

🎯 **Objectif :** poser les fondations pour tout le projet.

---

### Étape 2️⃣ : Gestion des fichiers

**Fichier :** `filelist.c`  

Nous coderons :  

- Création de fichiers (`create_file`)  
- Ajout dans une liste (`insert_file`)  
- Suppression ou recherche (`remove_file`, `find_file`)  
- Déplacement entre listes (`move_file`)  
- Affichage et libération mémoire (`print_list`, `free_list`)  

✅ Nous testerons chaque fonction avec un petit `main` temporaire pour vérifier que les pointeurs fonctionneront correctement.

---

### Étape 3️⃣ : G
