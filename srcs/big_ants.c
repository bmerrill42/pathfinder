#include "../includes/lem_in.h"

void display_ants(t_lemin *everything)
{
  int ants = 1;
  int index = 1;

  while (ants < everything->ant_count)
    {
      print_ant_pos();
      while (index < everything->path.index)
	{
	  ants--;
	  index++;
	  print_ant_pos();
	}
      ants++;
    }
  index = 1;
  while (index < everything->path.index)
    {
      while (index < everything->path.index)
	{
	  ants--;
	  index++;
	  print_ant_pos();
	}
      index++;
    }
}
