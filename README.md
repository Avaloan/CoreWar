# CoreWar
Simple game, involving memory and angry processes

30/04 Differences reperees
-name et comment (dans le fichier name-and-comment) n'acceptent pas les noms et comments a cause d'un decalage sur la verif des tailles max (j'ai ajoute +1 sur la size max dans stock-name et stock-comment

-la premiere ligne pose probleme sur Jumper. En enlevant "gobepc: st r1, :buff" ca marche

-probleme sur les commentaires (a regarder : main->valid_player(main.c)->check_command(check)->valid_command(command.c)


42.s n'est pas pris mais parce qu il est trop grand : pas de soucis
barriere.s n'est pas pris mais parce qu il est trop grand : pas de soucis









test.sh dans Globtest est un script qui permet d asm tous les fichiers .s d'un dossier
les .cor sont ranges dans 2 fichiers differents.
les executables de l'asm et la vm sont les derniers en date.
