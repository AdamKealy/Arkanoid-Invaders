#include "LevelLoader.h"

void operator >> (const YAML::Node& brickNode, BrickData& obstacle)
{
	obstacle.m_position.x = brickNode["position"]["x"].as<float>();
	obstacle.m_position.y = brickNode["position"]["y"].as<float>();
	
}

void operator >> (const YAML::Node& backgroundNode, BackgroundData& background)
{
	background.m_fileName = backgroundNode["file"].as<std::string>();
}

void operator >> (const YAML::Node& paddleNode, PaddleData& paddle)
{
	paddle.m_position.x = paddleNode["position"]["x"].as<float>();
	paddle.m_position.y = paddleNode["position"]["y"].as<float>();
}

void operator >> (const YAML::Node& boltNode, BoltData& bolt)
{
	bolt.m_position.x = boltNode["position"]["x"].as<float>();
	bolt.m_position.y = boltNode["position"]["y"].as<float>();
}

void operator >> (const YAML::Node& levelNode, LevelData& level)
{
	levelNode["background"] >> level.m_background;

	levelNode["tank"] >> level.m_paddle;

	const YAML::Node& obstaclesNode = levelNode["obstacles"].as<YAML::Node>();
	for (unsigned i = 0; i < obstaclesNode.size(); ++i)
	{
		BrickData obstacle;
		obstaclesNode[i] >> obstacle;
		level.m_bricks.push_back(obstacle);
	}
}

bool LevelLoader::load(int nr, LevelData& level)
{
	std::stringstream ss;
	ss << "ASSETS\\LEVELS\\level";
	ss << nr;
	ss << ".yaml";

	try
	{
		YAML::Node baseNode = YAML::LoadFile(ss.str());
		if (baseNode.IsNull())
		{
			std::string message("file: " + ss.str() + " not found");
			throw std::exception(message.c_str());
		}
		baseNode >> level;
	}
	catch (YAML::ParserException& e)
	{
		std::cout << e.what() << "\n";
		return false;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
		return false;
	}

	return true;
}