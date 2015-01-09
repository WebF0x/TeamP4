# Tutoriel pour Github

Downloader et installer GitHub for Windows: https://windows.github.com/

Utilisation GitHub for Windows
------------------------------
- Sign in
- À gauche le (+), Clone, [TonRepo], Clone, Choisir emplacement (exemple Desktop)
- Dérouler "Uncommitted changes" (Les fichiers que vous avez modifiés)
- Dans summary, décrivez ce que vous avez fait comme changement
- Commit to Master
- Sync (en haut a droite)

Utilisation git en console
------------------------------
- Faire clic gauche dans le repo (où le fichier ".git" se trouve)
- Git Bash
- Cloner un repo existant avec "git clone [SOURCE] [DESTINATION]"
  - ex: "git clone git@github.com:WebF0x/TeamP4.git" (DESTINATION optionelle)
- Connaisser l'état du repo avec "git status"
- Ajouter des modifications avec "git add [FICHIERS]"
  - Tout ajouter avec "git add -A"
- Commit avec "git commit -m [MESSAGE]"
  - Expliquez les changements apportés

Attention
---------
Avant de modifier le code, assurez vous de faire Sync (ou dans le Git Bash: "git pull"). 

Sinon il y a plus de chance d'avoir des conflits avec les modifications des autres
