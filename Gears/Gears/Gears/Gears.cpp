#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <vector>
#include <queue>

using Graph = std::vector<std::vector<int>>;
using Rotation = std::vector<std::string>;

struct Args
{
	std::string inputFileName;	
	std::string outputFileName;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];

	return args;
}

void GetGraph(const int M, const int N, Graph& graph, std::ifstream& input)
{

	int numOne, numTwo;
	for (int i = 0; i < N; i++)
	{
		input >> numOne >> numTwo;
		numOne--;
		numTwo--;
		graph[numOne].push_back(numTwo);
		graph[numTwo].push_back(numOne);
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

void GraphRec(int k, Rotation& gearsRotation, Graph& gearsGraph, bool& block)
{	
	std::queue<int> q;
	q.push(k);		
	
	while (!q.empty() && !block) 
	{
		int v = q.front();
		q.pop();
		for (size_t i = 0; i < gearsGraph[v].size(); i++) 
		{
			int to = gearsGraph[v][i];
			if (!block)
			{
				if (gearsRotation[to] == "immovable")
				{
					q.push(to);
					GetRotation(v, to, gearsRotation);
				}
				else if (gearsRotation[v] == gearsRotation[to])
				{
					block = true;
				}
			}					
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
	Graph gearsGraph(M, std::vector<int>());
	Rotation gearsRotation(M, "immovable");
	gearsRotation[0] = "clockwise";
	GetGraph(M, N, gearsGraph, input);
	
	bool block = false;
	GraphRec(0, gearsRotation, gearsGraph, block);

	std::ofstream output;
	output.open(args->outputFileName);
	if (block)
	{
		output << "block";
	}
	else
	{
		for (int i = 0; i < gearsRotation.size(); i++)
		{
			output << gearsRotation[i] << std::endl;
		}
	}

	return 0;
}