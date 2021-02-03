#include <stdio.h>
#include "table.h"
#include <random>
#include <algorithm>

const int w = 5;
const int h = 5;

auto initializer(std::vector<bool>& vec)
{
	std::random_device rd{};
	std::mt19937 mersenne_engine{ rd() };  // Generates random integers
	std::uniform_real_distribution<float> dist{ 0, 100 };
	auto gen = [&dist, &mersenne_engine]() { return dist(mersenne_engine) < 50 ? 0 : 1; };
	generate(vec.begin(), vec.end(), gen);
}

auto step(table& first_table)
{
	std::vector<bool> new_table(w * h);
	auto e_policy = [&](int pos) {return first_table.get_alive(pos) > 4 ? true : false; };
	for (int i = 0; i < h * w; ++i)
	{
		new_table[i] = e_policy(i);
	}
	table next(w, h, new_table);
	first_table = next;
}
