/*
Le but de ce fichier est de gérer tous les événements, merci d'adopter la même
syntaxe lors d'ajout d'événement, par défaut les événements de déplacement de
la souris sont désactivées.
*/


int event_handle(motor_t ** motor)
{
  int retour=3;
  SDL_WaitEvent(&(*motor)->event);

  if ((*motor)->event.type == SDL_MOUSEMOTION)
  return -1;

  char * key_pressed;
  key_pressed = (*motor)->last_key;
  if ((*motor)->event.type == SDL_KEYDOWN)
  {
    switch ((*motor)->event.key.keysym.sym)
    {
      case SDLK_z:
      key_pressed = "z";
      break;

      case SDLK_q:
      key_pressed = "q";
      break;

      case SDLK_s:
      key_pressed = "s";

      break;

      case SDLK_d:
      key_pressed = "d";
      break;



      case SDLK_RETURN:

      if ((*motor)->menu->menu_battle == 1){
        switch ((*motor)->menu->el_battle_menu_select) {
          case 0:
          (*motor)->menu->menu_battle_attaque= 1;
          (*motor)->menu->menu_battle = 0;
          break;

          case 1:

          (*motor)->menu->menu_pokemon = 1;
          (*motor)->menu->menu_battle = 0;
          break;

          case 2:
          //(*motor)->menu->menu_battle_attaque= 1;
          (*motor)->menu->menu_battle = 0;
          break;
          case 3:
          //(*motor)->menu->menu_battle_attaque= 1;
          (*motor)->menu->menu_battle = 0;
          break;

        }
      }
      else if ((*motor)->menu->menu_battle_attaque == 1 && (*motor)->menu->menu_battle == 0){
        switch ((*motor)->menu->el_battle_menu_atk_select) {
          case 0:
          (*motor)->menu->choixCombat = 0;
          retour = combat(player,&wild_pkm,(*motor)->menu->choixCombat);
          if (verif_fin_combat(player) == 1){
            (*motor)->menu->el_battle_menu_select = 0;
            (*motor)->menu->el_battle_menu_atk_select = 0;
          }
          else
            (*motor)->menu->speech_bubble = 1;
          break;
          case 1:
          (*motor)->menu->choixCombat = 1;
          retour = combat(player,&wild_pkm,(*motor)->menu->choixCombat);
          (*motor)->menu->el_battle_menu_select = 0;
          (*motor)->menu->el_battle_menu_atk_select = 0;
          break;
          case 2:
          (*motor)->menu->choixCombat = 2;
          retour = combat(player,&wild_pkm,(*motor)->menu->choixCombat);
          (*motor)->menu->el_battle_menu_select = 0;
          (*motor)->menu->el_battle_menu_atk_select = 0;
          break;
          case 3:
          (*motor)->menu->choixCombat = 3;
          retour = combat(player,&wild_pkm,(*motor)->menu->choixCombat);
          (*motor)->menu->el_battle_menu_select = 0;
          (*motor)->menu->el_battle_menu_atk_select = 0;
          break;

        }
        if(retour == 1 || retour == 0){    //plus pkm allie ou ennemi mort
          printf("Retour: %d\n", retour);
          (*motor)->menu->speech_bubble = 1;
          (*motor)->menu->menu_battle_attaque = 0;
        }
        else if (retour == 2){ //pkm allie k.o, pkm->next
          printf("Retour: %d\n", retour);
          (*motor)->menu->menu_pokemon = 1;
          (*motor)->menu->menu_battle_attaque = 0;
        }
        else if (retour == 3){  //tour suivant pas de k.o
          printf("Retour: %d\n", retour);
          (*motor)->menu->menu_battle = 1;
          (*motor)->menu->menu_battle_attaque = 0;

        }
      }
      else if ((*motor)->menu->menu_pokemon == 1 && (*motor)->menu->menu_battle == 0){
        switch ((*motor)->menu->el_menu_pokemon_select){
          case 1:
          player = current_pkm(player, 1);
          (*motor)->menu->menu_battle = 1;
          (*motor)->menu->menu_pokemon = 0;
          (*motor)->menu->el_battle_menu_select = 0;
          (*motor)->menu->el_menu_pokemon_select = 0;
          break;
          case 2:
          player = current_pkm(player, 2);
          (*motor)->menu->menu_battle = 1;
          (*motor)->menu->menu_pokemon = 0;
          (*motor)->menu->el_battle_menu_select = 0;
          (*motor)->menu->el_menu_pokemon_select = 0;
          break;
          case 3:
          player = current_pkm(player, 3);
          (*motor)->menu->menu_battle = 1;
          (*motor)->menu->menu_pokemon = 0;
          (*motor)->menu->el_battle_menu_select = 0;
          (*motor)->menu->el_menu_pokemon_select = 0;
          break;
          case 4:
          player = current_pkm(player, 4);
          (*motor)->menu->menu_battle = 1;
          (*motor)->menu->menu_pokemon = 0;
          (*motor)->menu->el_battle_menu_select = 0;
          (*motor)->menu->el_menu_pokemon_select = 0;
          break;
          case 5:
          player = current_pkm(player, 5);
          (*motor)->menu->menu_battle = 1;
          (*motor)->menu->menu_pokemon = 0;
          (*motor)->menu->el_battle_menu_select = 0;
          (*motor)->menu->el_menu_pokemon_select = 0;
          break;
          case 6:
          player = current_pkm(player, 6);
          (*motor)->menu->menu_battle = 1;
          (*motor)->menu->menu_pokemon = 0;
          (*motor)->menu->el_battle_menu_select = 0;
          (*motor)->menu->el_menu_pokemon_select = 0;
          break;
        }
      }

      break;

      case SDLK_m:
      key_pressed = "m";


      break;

      case SDLK_b:
      key_pressed = "b";
      break;

      case SDLK_a:
      key_pressed = "a";
      break;

      case SDLK_UP:

      if ((*motor)->menu->el_menu_select > 0)
      (*motor)->menu->el_menu_select--;
      else
      (*motor)->menu->el_menu_select = 5;


      if ((*motor)->menu->el_battle_menu_select > 0)
      (*motor)->menu->el_battle_menu_select--;
      else
      (*motor)->menu->el_battle_menu_select =3;




      if ((*motor)->menu->el_battle_menu_atk_select > 0)
      (*motor)->menu->el_battle_menu_atk_select--;
      else
      (*motor)->menu->el_battle_menu_atk_select =3;

      if ((*motor)->menu->el_menu_pokemon_select > 0)
      (*motor)->menu->el_menu_pokemon_select--;
      else
      (*motor)->menu->el_menu_pokemon_select = 5;








      break;

      case SDLK_DOWN:


      if ((*motor)->menu->el_menu_select < 5)
      (*motor)->menu->el_menu_select++;
      else
      (*motor)->menu->el_menu_select = 0;


      if ((*motor)->menu->el_battle_menu_select < 3)
      (*motor)->menu->el_battle_menu_select++;
      else
      (*motor)->menu->el_battle_menu_select =0;



      if ((*motor)->menu->el_battle_menu_atk_select < 3)
      (*motor)->menu->el_battle_menu_atk_select++;
      else
      (*motor)->menu->el_battle_menu_atk_select =0;

      if ((*motor)->menu->el_menu_pokemon_select < 5)
      (*motor)->menu->el_menu_pokemon_select++;
      else
      (*motor)->menu->el_menu_pokemon_select = 0;

      break;

      default:
      break;
    }
    strcpy((*motor)->last_key,key_pressed);
  }
  else if ((*motor)->event.type == SDL_QUIT)
  {
    (*motor)->quit = 1;
  }

  return 1;
}
