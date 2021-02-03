#include <stdio.h>
#include <random>
#include <algorithm>
#include <fstream>
#include <string>
#include "table.h"
#include "game_varriables.h"

void gillder_test()
{
	std::ofstream handler("glidder.txt");
	std::vector<bool> g1 =
	{
		0,0,0,0,0,0,
		0,0,1,0,0,0,
		1,0,1,0,0,0,
		0,1,1,0,0,0,
		0,0,0,0,0,0,
		0,0,0,0,0,0
	};

	table glidder(6, 6, g1);
	
	glidder.write_table_out(handler);
	for (int i = 0; i < 5; ++i)
	{
		glidder.do_game();
		glidder.write_table_out(handler);
	}
	handler.close();
}

void write_line(float* res,std::ofstream& handler,int x)
{
	for (int y = 0; y < w; ++y)
	{
		handler << res[x * h + y] << ' ';
	}
}

void write_out_result(float* res,std::ofstream& handler)
{
	for (int x = 0; x < h; ++x)
	{
		write_line(res, handler,x);
		handler << std::endl;
	}
	handler  << std::endl;
}
