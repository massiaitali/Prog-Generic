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


#include <iostream>

#include "tic_tac_toe.hpp"


int main()
{
	tic_tac_toe_t tic_tac_toe;
	
	// rvalue
	{
		//tic_tac_toe.run(player_random(), player_random());
		
		//tic_tac_toe.run(player_random(), player_ai());
		
		//tic_tac_toe.run(player_ai(), player_random());
		
		//tic_tac_toe.run(player_ai(), player_ai());
	}
	
	// lvalue
// 	{
// 		tic_tac_toe_t tic_tac_toe;
// 		
// 		player_random a;
// 		player_ai b;
// 		
// 		tic_tac_toe.run(a, b);
// 	}
	
	return 0;
}
