// Copyright © 2015 Université Paris-Sud, Written by Lénaïc Bagnères, lenaic.bagneres@u-psud.fr

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include <array>
#include <vector>

#include "hopp/random.hpp"
#include "hopp/container/vector2.hpp"
#include "hopp/time/sleep.hpp"
#include "hopp/time/now.hpp"

#include "tree.hpp"

const size_t BOARD_SIZE = 3;
const char X = 'X';
const char O = 'O';
const char VIDE = '_';

// Forward declaration
class tic_tac_toe_t;
std::ostream & operator <<(std::ostream & out, tic_tac_toe_t const & tic_tac_toe);

// tic_tac_toe_t
class tic_tac_toe_t
{
	private :
		std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE> plateau;
		
		const char log_first_player;
		char currentPlayer;
		char winner;
		
		std::vector<std::pair<size_t, size_t>> log_plays;
		
		template <class player_t0, class player_t1>
		void run_(player_t0 & player_0, player_t1 & player_1){
			std::cout << "Lancement du jeu" << " player_t1" << " player_t2" << std::endl;
		}
		
	public :
	
		//Constructeur
		tic_tac_toe_t() : plateau({{{VIDE,VIDE,VIDE}, {VIDE,VIDE,VIDE}, {VIDE,VIDE,VIDE}}}), 
							log_first_player(hopp::random::uniform(1,2) == 1 ? X : O),
							currentPlayer(log_first_player),
							winner(VIDE),
							log_plays() {}
	
		std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE> board() const { return plateau; }
		
		size_t nb_row() const { return BOARD_SIZE; }
		size_t nb_col() const { return BOARD_SIZE; }
		
		char get(size_t const i, size_t const j) const { return plateau[i][j]; }	
		char operator ()(size_t const i, size_t const j) const { return get(i,j); }		
		
		char is_playing() const { return currentPlayer; }
		char get_winner() const { return winner; }
		
		void play(size_t const i, size_t const j) { 
			if(plateau[i][j] == VIDE) { 
				plateau[i][j] = is_playing(); 
			} else {
				std::cerr << "ERROR : Invalid move" << std::endl;
			}
		}
		void play(hopp::vector2<size_t> const & i_and_j) { play(i_and_j.x, i_and_j.y); }
		
		template <class player_t0, class player_t1>
		void run(player_t0 & player_0, player_t1 & player_1) { run_(player_0, player_1); }
		template <class player_t0, class player_t1>
		void run(player_t0 && player_0, player_t1 && player_1) { run_(player_0, player_1); }
		
		bool is_ended() const {
			if(winner!=VIDE) return true;
			for(size_t i=0; i<BOARD_SIZE; i++){
				for(size_t j=0; j<BOARD_SIZE; j++){
					if(get(i,j)==VIDE) return false;
				}
			}
			return true;
		}		
		
		std::vector<std::pair<size_t, size_t>> moves_possible() const {
			std::vector<std::pair<size_t, size_t>> moves;
			if(!is_ended()){
				for(size_t i=0; i<BOARD_SIZE; i++){
					for(size_t j=0; j<BOARD_SIZE; j++){
						if(get(i,j)==VIDE) moves.push_back(std::make_pair(i,j));
					}
				}
			}
			return moves;
		}
};

inline
std::ostream & operator <<(std::ostream & out, tic_tac_toe_t const & tic_tac_toe)
{
	for(size_t i=0; i<tic_tac_toe.nb_row(); i++){
		for(size_t j=0; j<tic_tac_toe.nb_col(); j++){
			out << tic_tac_toe(i,j) << '|';
		}
		out << std::endl;
	}	
	return out;
}

// player_random

class player_random
{
	public:
		player_random(){}
		std::pair<size_t, size_t> play (tic_tac_toe_t const& tic_tac_toe) const {
			std::pair<size_t, size_t> move;
			std::vector<std::pair<size_t, size_t>> moves = tic_tac_toe.moves_possible();
			move = moves[hopp::random::uniform(size_t(0), moves.size() - 1)];
			return move;
		}
};


// player_ai

class player_ai
{
	public:
		player_ai(){}
		std::pair<size_t, size_t> play (tic_tac_toe_t const& tic_tac_toe) const {
			std::pair<size_t, size_t> move;
			//TODO
			return move;
		}
};



#endif
