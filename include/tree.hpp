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


#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <algorithm>


template <class T>
class tree
{
public:
	
	T data;
	
	std::vector<tree<T>> children;
	
public:
	
	tree(T const & data = T()) : data(data), children() { }
	
	size_t nb_children() const
	{
		// TODO
		return 0;
	}
};

#endif
