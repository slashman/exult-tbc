/*
 *  Copyright (C) 2000-2016  The Exult Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <iostream>
#include "SDL.h"
#include <SDL_timer.h>
#include "tqueue.h"
#include "gamewin.h"
#include "turn_based_combat.h"

void TurnBasedCombat::pause_game(){
	std::cout << "TurnBasedCombat:pause_game()" << std::endl;
	//gwin->get_tqueue()->pause(SDL_GetTicks());
	gwin->set_time_stopped(-1);
}

void TurnBasedCombat::resume_game(){
	std::cout << "TurnBasedCombat:resume_game()" << std::endl;
	// std::cout << "TBC: RESUMING GAME" << std::endl;
	gwin->set_time_stopped(0);
}

void TurnBasedCombat::on_combat_started(){
	std::cout << "TurnBasedCombat:on_combat_started()" << std::endl;
	this->onCombat = true;
	this->freeze_turn();
}

void TurnBasedCombat::on_combat_ended(){
	std::cout << "TurnBasedCombat:on_combat_ended()" << std::endl;
	this->onCombat = false;
	// std::cout << "TBC: HIDING PASS TURN BUTTON " << std::endl;	
	this->resume_game();
}

void TurnBasedCombat::on_player_walked(){
	std::cout << "TurnBasedCombat:on_player_walked()" << std::endl;
	this->playerWalkCounter++;
	std::cout << "TurnBasedCombat:playerWalkCounter: " << this->playerWalkCounter << std::endl;
	if (this->playerWalkCounter > 8){
		if (this->onCombat){
			//this->resume_game();
			this->run_turn();
		}
		this->playerWalkCounter = 0;
	}
}

Uint32 freeze_turn_callback(Uint32 interval, void *param){
	((class TurnBasedCombat *)param)->freeze_turn();
	return 0;
}

void TurnBasedCombat::run_turn(){
	std::cout << "TurnBasedCombat:run_turn()" << std::endl;
	// std::cout << "TBC: HIDING PASS TURN BUTTON " << std::endl;	
	this->playerActionsBlocked = true;
	this->resume_game();
	// This must probably be changed to something used the tqueue
	SDL_TimerID my_timer_id = SDL_AddTimer(2000, freeze_turn_callback, this);
}

void TurnBasedCombat::freeze_turn(){
	std::cout << "TurnBasedCombat:freeze_turn()" << std::endl;
	// std::cout << "TBC: SHOWING PASS TURN BUTTON " << std::endl;	
	this->playerActionsBlocked = false;
	this->pause_game();
	this->playerWalkCounter = 0;
}

bool TurnBasedCombat::check_turn_in_progress(){
	std::cout << "TurnBasedCombat:check_turn_in_progress()" << std::endl;
	return this->onCombat && this->playerActionsBlocked;
}

bool TurnBasedCombat::in_player_turn(){
	return this->onCombat && !this->playerActionsBlocked;
}

void TurnBasedCombat::end_turn(){
	std::cout << "TurnBasedCombat:end_turn()" << std::endl;
}

void TurnBasedCombat::set_player_targetting(){
	std::cout << "TurnBasedCombat:set_player_targetting()" << std::endl;	
	this->playerTargetting = true;
}

void TurnBasedCombat::check_player_used_item(){
	std::cout << "TurnBasedCombat:check_player_used_item()" << std::endl;	
	if (this->playerTargetting){
		this->end_turn();
		this->playerTargetting = false;
	}
}