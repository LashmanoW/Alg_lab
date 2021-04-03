#include <iostream>
#include <fstream>
#include <optional>
#include <string>

#include <vector>


using Graph = std::vector<std::vector<int>>;
using Rotation = std::vector<std::string>;

struct Args
{
	std::string inputFileName;	
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];

	return args;
}

void GetGraph(const int M, const int N, Graph& graph, std::ifstream& input)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			graph[i][j] = 0;			
		}
	}

	int numOne, numTwo;
	for (int i = 0; i < N; i++)
	{
		input >> numOne >> numTwo;
		graph[numOne][numTwo] = 1;
		graph[numTwo][numOne] = 1;
	}
}

void GetRotation(int k_befor, int k, Rotation& gearsRotation)
{
	if (gearsRotation[k_befor] == "clockwise")
	{
		gearsRotation[k] = "unclockwise";
	}
	else
	{
		gearsRotation[k] = "clockwise";
	}
}

void GraphRec(int k_befor, int k, Rotation& gearsRotation, Graph& gearsGraph, bool& block)
{
	std::string rot;
	if (!block)
	{
		if (gearsRotation[k] == "immovable")
		{
			GetRotation(k_befor, k, gearsRotation);
			rot = gearsRotation[k];
			for (int i = 1; i < gearsRotation.size(); i++)
			{
				if ((gearsGraph[k][i] == 1) && (i != k_befor))
				{
					GraphRec(k, i, gearsRotation, gearsGraph, block);
				}
			}
		}
		else if(gearsRotation[k] == gearsRotation[k_befor])
		{
			block = true;
		}
	}	
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	std::ifstream input;
	input.open(args->inputFileName);

	int M, N;	
	input >> M >> N;
	Graph gearsGraph(M + 1, std::vector<int>(M + 1));
	Rotation gearsRotation(M + 1, "immovable");
	gearsRotation[0] = "unclockwise";
	GetGraph(M + 1, N, gearsGraph, input);
	
	bool block = false;
	GraphRec(0, 1, gearsRotation, gearsGraph, block);

	if (block)
	{
		std::cout << "block";
	}
	else
	{
		for (int i = 1; i < gearsRotation.size(); i++)
		{
			std::cout << gearsRotation[i] << std::endl;
		}
	}

	return 0;
}