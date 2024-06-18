#include <stdio.h>

struct pStats {
  int health;
  int exp;
};


int main(){
  struct pStats players[5];
  for(int i = 0; i < 5; i++){
    printf("Health for player %d: ", i+1);
    scanf("%d", &players[i].health);
    printf("Experience for player %d: ", i+1);
    scanf("%d", &players[i].exp);  
  }  


  for(int j = 0; j < 5; j++){
    printf("Player %d exp is %d\n", j+1, players[j].exp);
    printf("health is %d\n\n", players[j].health);
  }
  return 0;
}
