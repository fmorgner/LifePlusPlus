//
//  main.cpp
//  Life++
//
//  Created by Felix Morgner on 23.02.13.
//  Copyright (c) 2013 Felix Morgner. All rights reserved.
//

#include <iostream>
#include "CCell.h"
#include "CWorld.h"
#include <vector>
#include <string>

#include <unistd.h>
#include <term.h>

void ClearScreen()
  {
  if (!cur_term)
    {
    int result;
    setupterm( NULL, STDOUT_FILENO, &result );
    if (result <= 0) return;
    }

  putp( tigetstr( "clear" ) );
  }

#define WORLD_SIZE 25

int main(int argc, const char * argv[])
  {
  World oWorld(WORLD_SIZE);

  for(int i = 0; i < WORLD_SIZE; i++)
    {
    for(int j = 0; j < WORLD_SIZE; j++)
      {
      if(rand()%2)
        {
        oWorld.Animate(j, i);
        }
      }
    }
    
  oWorld.Print();
  
  while(true)
    {
    ClearScreen();
    oWorld.Update();
    oWorld.Print();
    usleep(200000);
    }
  
  return 0;
  }
