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

class Game_window;

class TurnBasedCombat {
	Game_window *gwin;
	int playerWalkCounter;
	bool playerActionsBlocked;
	bool playerTargetting;
	bool onCombat;
public:
	TurnBasedCombat(Game_window *g) : gwin(g), playerWalkCounter(0), playerActionsBlocked(false),  playerTargetting(false), onCombat(false) {};
	void pause_game();
	void resume_game();
	void on_combat_started();
	void on_combat_ended();
	void on_player_walked();
	/*
	 * Returns true if in battle and the player is on stand by (the turn of the rest of actors in the world)
	 */
	bool check_turn_in_progress();
	/*
	 * Returns true if in battle and the player is acting, i.e. no other actor in the world should move
	 */
	bool in_player_turn();
	void set_player_targetting();
	void check_player_used_item();
	void end_turn();
private:
	void run_turn();
	void freeze_turn();
};